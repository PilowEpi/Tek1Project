#!/bin/python3

import json
import sys

from shapely.geometry import Polygon, Point

from copy import copy, deepcopy
from tkinter import *
from tkinter import filedialog
from tkinter import messagebox
from tkinter import colorchooser
from tkinter import ttk

colors = {
    "white": [255, 255, 255, 255]
}

types = {
    "object": 'W',
    "light": 'L',
    "entity": 'E',
    "info" : 'I',
    "empty": 'N'
}

light_status = {
    "on": 1,
    "off": 0
}

entity_type = {
    "ENNEMY": 0,
    "NPC": 1
}

info_type = {
    "START": 0,
    "END": 1,
    "OBJ": 2,
    "TRIGGER": 3,
}

class Editor():
    def __init__(self, previous=None):
        self.current_map = None
        self.current_room = 0
        self.selection = None
        if previous != None:
            self.current_map = self.load(previous)
        if self.current_map == None:
            self.current_map = self.init_map()
        self.exporter = Export()
        self.setup_window()
        self.root.mainloop()
        pass

    ##############
    ##  LAYOUT  ##
    ##############
    
    def setup_window(self):
        self.root = Tk()
        self.root.title('MyRPG map editor')

        self.frame_height = 1080#600
        self.frame_width = 1920#800
        self.right_container_width = 300#200
        self.frame = Frame(self.root, width=self.frame_width, height=self.frame_height)
        self.frame.pack_propagate(0)
        self.frame.pack()

        self.menu_bar = Menu(self.frame)
        self.file_menu = Menu(self.menu_bar)
        self.edit_menu = Menu(self.menu_bar)
        self.menu_bar.add_cascade(label="File", menu=self.file_menu)
        self.menu_bar.add_cascade(label="Edit", menu=self.edit_menu)

        self.file_menu.add_command(label='Open map project', command=self.open_project)
        self.file_menu.add_command(label='Save map project', command=self.save_project)
        self.file_menu.add_command(label='Export map', command=self.export)
        self.file_menu.add_separator()
        self.file_menu.add_command(label='Switch room', command=self.switch_room)

        self.edit_menu.add_command(label='Create Wall', command=self.add_new_wall)
        self.edit_menu.add_command(label='Create Entity', command=self.add_new_entity)
        self.edit_menu.add_command(label='Create Light', command=self.add_new_light)
        self.edit_menu.add_command(label='Create Info object', command=self.add_new_info)
#        self.edit_menu.add_command(label='Create Empty node')
        self.root.config(menu=self.menu_bar)

        self.footer = Frame(self.frame, width=self.frame_width, height=20, bg='green')
        self.footer.pack(side=BOTTOM)
        self.foot_label = Label(self.footer, text='X=0, Y=0')
        self.foot_label.pack()
        self.root.bind('<Motion>', self.update_foot_label)

        self.right_container = Frame(self.frame, width=self.right_container_width, height=self.frame_height)
        self.right_container.pack(side=RIGHT)

        self.inspector = Frame(self.right_container, width=self.right_container_width, height=300)
        self.inspector.grid_columnconfigure((0,1), weight=1)
        self.inspector.grid_propagate(0)
        self.inspector.pack()
        self.inspect = {
            types["object"]: self.inspect_object,
            types["light"]: self.inspect_light,
            types["entity"]: self.inspect_entity,
            types["info"]: self.inspect_info
            #types["empty"]: self.no_op
        }

        self.hier_scrollbar = Scrollbar(self.right_container)
        self.hier_scrollbar.pack(side=RIGHT, fill=Y)
        self.hier = ttk.Treeview(self.right_container, height=300, yscrollcommand=self.hier_scrollbar.set)
        self.hier_scrollbar.config(command=self.hier.yview)
        self.hier.heading("#0", text="hierarchy")
        self.hier.column("#0", width=self.right_container_width)
        self.hier.bind('<Button-3>', self.hier_menu)
        self.hier.bind('<Button-1>', self.hier_deselect)
        self.hier.bind('<Control-d>', self.hier_dup)
        self.hier.bind('<Delete>', self.hier_menu_delete)
        self.hier.pack()

        self.hier_menu = Menu(self.frame)
        self.hier_menu.add_command(label='delete', command=self.hier_menu_delete)

        self.main = Canvas(self.frame, width=self.frame_width, height=self.frame_height, borderwidth=2, bg='black')
        self.main.bind("<B1-Motion>", self.canvas_drag)
        self.main.bind("<Button-1>", self.canvas_press)
        self.main.bind("<ButtonRelease-1>", self.canvas_release)
        self.main.bind('<Control-d>', self.hier_dup)
        self.main.bind('<Delete>', self.hier_menu_delete)
        self.main.pack()
        self.main_scale = 1.0
        self.pos = [0, 0]
        self.draw = {
            types["object"]: self.draw_object,
            types["light"]: self.draw_light,
            types["entity"]: self.draw_entity,
            types["info"]: self.draw_info
            #types["empty"]: self.no_op
        }
        self.update_all()
        pass

    def update_foot_label(self, event):
        pos = self.mouse_to_canvas([event.x, event.y])
        self.foot_label['text'] = 'X = %d, Y = %d' % (pos[0], pos[1])
        pass

    ################
    ##  RUN DATA  ##
    ################
    
    def add_new_wall(self):
        room = self.current_map[self.current_room]
        room[3].append([types["object"], [100, 100], [200, 100], [200, 200], [100, 200]])
        self.update_hierarchy()
        self.update_canvas()
        pass
    
    def add_new_light(self):
        room = self.current_map[self.current_room]
        room[3].append([types["light"], 100, light_status["on"], [200, 200]])
        self.update_hierarchy()
        self.update_canvas()
        pass
    
    def add_new_entity(self):
        room = self.current_map[self.current_room]
        room[3].append([types["entity"], entity_type["NPC"], [200, 100], 0, 0])
        self.update_hierarchy()
        self.update_canvas()
        pass
    
    def add_new_info(self):
        room = self.current_map[self.current_room]
        room[3].append([types["info"], info_type["START"], [200, 100], 0])
        self.update_hierarchy()
        self.update_canvas()
        pass

    def remove_item(self, idx):
        room = self.current_map[self.current_room]
        room[3].remove(room[3][idx])
        pass
    
    def init_room(self):
        return (deepcopy([1920, 1080, colors["white"], []]))
        pass
    
    def init_map(self):
        return (deepcopy([self.init_room()]))
        pass
    
    def open_project(self):
        new_project = filedialog.askopenfile(mode="r", filetypes=[("JSON file", ".json")])
        if new_project == None:
            return
        self.current_map = self.load_with_open(new_project)
        self.update_all()
        pass

    def save_project(self):
        project = filedialog.asksaveasfile(mode="w", filetypes=[("JSON file", ".json")])
        if project == None:
            return
        json.dump(self.current_map, project, indent=4)
        pass

    def export(self):
        exp = filedialog.asksaveasfile(mode="wb", filetypes=[("MyRPG data file", ".dat")])
        if exp == None:
            return
        self.exporter.write_object_to_file(exp, self.current_map)
        pass

    #################
    ##  HIERARCHY  ##
    #################

    def hier_menu_delete(self, *a):
        for item in self.hier.selection():
            self.remove_item(self.hier.item(item)['values'][0])
        self.selection = None
        self.update_all()
        pass

    def hier_deselect(self, event):
        row = self.hier.identify_row(event.y)
        if not row:
            self.hier.selection_set([])
        pass
    
    def hier_menu(self, event):
        row = self.hier.identify_row(event.y)
        if row:
            self.hier.selection_set(row)
            self.hier_menu.post(event.x_root, event.y_root)
        pass
    
    def hier_dup(self, *a):
        selected = self.hier.selection()
        if len(selected) == 0:
            return
        idx = self.hier.item(selected[0])['values'][0]
        cpy = deepcopy(self.current_map[self.current_room][3][idx])
        self.current_map[self.current_room][3].append(cpy)
        self.update_all()
        for item in self.hier.get_children():
            if self.hier.item(item)['values'][0] == self.hier_index(self.current_map[self.current_room][3], cpy):
                self.hier.selection_set(item)
                return
        pass
    
    def update_tree_selected(self, event):
        selection = event.widget.selection()
        if len(selection) > 0:
            item = self.hier.item(selection[0])
            self.selection = item['values']
        else:
            self.selection = None
        self.update_inspector()
        self.update_canvas()
        pass
    
    def update_hierarchy(self):
        self.hier.delete(*self.hier.get_children())
        self.hier.bind("<<TreeviewSelect>>", self.update_tree_selected)
        inv_map = {v: k for k, v in types.items()}
        for obj in self.current_map[self.current_room][3]:
            self.hier.insert("", 0, text=inv_map[obj[0]], values=self.hier_index(self.current_map[self.current_room][3], obj))
        pass

    # exactly like .index() method but more precise
    def hier_index(self, lst, obj):
        for i, val in enumerate(lst):
            if val is obj:
                return (i)
        return (-1)

    ##############
    ##  CANVAS  ##
    ##############

    def get_item_from_mouse_point(self, pos):
        pos = self.mouse_to_canvas(pos)
        pt = Point(*pos)
        cr_size = 10
        for obj in self.current_map[self.current_room][3]:
            if obj[0] == types["object"]:
                arr = [(v[0], v[1]) for v in obj[1:]]
                poly = Polygon(arr)
                if pt.within(poly):
                    return (obj)
            else:
                pos = obj[3] if obj[0] == types["light"] else obj[2]
                arr = [(pos[0] - cr_size, pos[1] - cr_size),
                       (pos[0] - cr_size, pos[1] + cr_size),
                       (pos[0] + cr_size, pos[1] + cr_size),
                       (pos[0] + cr_size, pos[1] - cr_size),]
                poly = Polygon(arr)
                if pt.within(poly):
                    return (obj)
        return (None)

    def set_selection_from_object(self, obj):
        if obj == None:
            if len(self.hier.selection()) == 0:
                return
            self.hier.selection_set([])
        else:
            for item in self.hier.get_children():
                if self.hier.item(item)['values'][0] == self.current_map[self.current_room][3].index(obj):
                    if len(self.hier.selection()) > 0 and self.hier.selection()[0] == item:
                        return
                    self.hier.selection_set(item)
                    break
        self.update_inspector()
        pass

    def canvas_drag(self, event):
        if self.selected != None and self.selected[0] == types["object"]:
            for i in range(0, len(self.selected) - 1):
                self.selected[i + 1][0] = self.obj_copy[i + 1][0] + event.x - self.org_pos[0]
                self.selected[i + 1][1] = self.obj_copy[i + 1][1] + event.y - self.org_pos[1]
        else:
            self.write_to[0] = self.pos_save[0] + event.x - self.org_pos[0]
            self.write_to[1] = self.pos_save[1] + event.y - self.org_pos[1]
        self.update_canvas()
        pass

    def canvas_press(self, event):
        self.pos_save = copy(self.pos)
        self.org_pos = [event.x, event.y]
        self.selected = self.get_item_from_mouse_point(self.org_pos)
        self.set_selection_from_object(self.selected)
        if self.selected == None:
            self.write_to = self.pos
        elif self.selected[0] == types["object"]:
            self.obj_copy = deepcopy(self.selected)
        else:
            self.write_to = self.selected[3] if self.selected[0] == types["light"] else self.selected[2]
            self.pos_save = copy(self.write_to)
        pass

    def mouse_to_canvas(self, pos):
        pos = copy(pos)
        pos[0] -= self.pos[0]
        pos[1] -= self.pos[1]
        return (pos)

    def canvas_to_mouse(self, pos):
        pos = copy(pos)
        pos[0] += self.pos[0]
        pos[1] += self.pos[1]
        return (pos)

    def canvas_release(self, event):
        self.update_inspector()
        pass

    def draw_object(self, obj):
        points = []
        for pt in obj[1:]:
            points.append((pt[0] + self.pos[0]) * self.main_scale)
            points.append((pt[1] + self.pos[1]) * self.main_scale)
        if self.selection != None and obj == self.current_map[self.current_room][3][self.selection[0]]:
            self.main.create_polygon(points, fill='#fff', width=2, outline="#f11")
        else:
            self.main.create_polygon(points, fill='#fff', width=2)
        pass
    
    def draw_light(self, obj):
        pos = obj[3]
        color = "#fff" if obj[2] == light_status["on"] else "#999"
        self.main.create_oval(pos[0] - obj[1] / 2 + self.pos[0], pos[1] - obj[1] / 2 + self.pos[1],
                              pos[0] + obj[1] / 2 + self.pos[0], pos[1] + obj[1] / 2 + self.pos[1], outline=color)
        self.main.create_line(pos[0] + self.pos[0], pos[1] + self.pos[1], pos[0] + 1 + self.pos[0], pos[1] + 1 + self.pos[1], fill="#f00", width=2)
        pass
    
    def draw_entity(self, obj):
        pos = obj[2]
        cr_size = 5
        color = "#f00" if obj[1] == entity_type["ENNEMY"] else "#0f0"
        if self.selection != None and obj == self.current_map[self.current_room][3][self.selection[0]]:
            color = "#777"
        self.main.create_line(pos[0] - cr_size + self.pos[0], pos[1] - cr_size + self.pos[1],
                              pos[0] + cr_size + 1 + self.pos[0], pos[1] + cr_size + 1 + self.pos[1], fill=color)
        self.main.create_line(pos[0] + cr_size + 1 + self.pos[0], pos[1] - cr_size - 1 + self.pos[1],
                              pos[0] - cr_size + self.pos[0], pos[1] + cr_size + self.pos[1], fill=color)
        pass
    
    def draw_info(self, obj):
        pos = obj[2]
        cr_size = 5
        color = "#00f"
        if self.selection != None and obj == self.current_map[self.current_room][3][self.selection[0]]:
            color = "#777"
        self.main.create_line(pos[0] - cr_size + self.pos[0], pos[1] - cr_size + self.pos[1],
                              pos[0] + cr_size + 1 + self.pos[0], pos[1] + cr_size + 1 + self.pos[1], fill=color)
        self.main.create_line(pos[0] + cr_size + 1 + self.pos[0], pos[1] - cr_size - 1 + self.pos[1],
                              pos[0] - cr_size + self.pos[0], pos[1] + cr_size + self.pos[1], fill=color)
        pass
    
    def update_canvas(self):
        self.main.delete(ALL)
        for obj in self.current_map[self.current_room][3]:
            self.draw[obj[0]](obj)
        pass

    def update_all(self):
        self.update_hierarchy()
        self.update_canvas()
        self.update_inspector()
        pass
    
    #############
    ##  ROOMS  ##
    #############

    def room_popup(self, event):
        row = self.room_tree.identify_row(event.y)
        if row:
            self.room_tree.selection_set(row)
        self.room_menu.post(event.x_root, event.y_root)
        pass

    def room_menu_delete(self):
        for item in self.room_tree.selection():
            self.current_map.remove(self.current_map[(self.room_tree.item(item)['values'][0])])
        self.update_room_tree()
        pass

    def room_menu_add(self):
        self.current_map.append(self.init_room())
        self.update_room_tree()
        pass

    def switch_to_room(self, *a):
        if len(self.room_tree.selection()) == 0:
            return
        self.current_room = self.room_tree.item(self.room_tree.selection()[0])['values'][0]
        self.window.destroy()
        self.update_all()
        pass

    def update_room_tree(self):
        self.room_tree.delete(*self.room_tree.get_children())
        for i in range(0, len(self.current_map)):
            self.room_tree.insert("", i, text="Room #%d" % i, values=i)
        pass
    
    def switch_room(self):
        self.window = Toplevel(self.root)

        Button(self.window, text="switch to selection", command=self.switch_to_room).pack()
        self.room_tree = ttk.Treeview(self.window)
        self.room_tree.heading("#0", text="rooms")
        self.room_tree.bind('<Button-3>', self.room_popup)
        self.room_tree.bind('<Double-Button-1>', self.switch_to_room)
        self.room_tree.pack()

        self.room_menu = Menu(self.window)
        self.room_menu.add_command(label='delete', command=self.room_menu_delete)
        self.room_menu.add_command(label='add', command=self.room_menu_add)
        self.update_room_tree()
        pass
    
    #################
    ##  INSPECTOR  ##
    #################
    
    def update_inspector(self):
        for child in self.inspector.winfo_children():
            child.destroy()
        if self.selection == None or len(self.selection) == 0:
            self.inspect_room()
        else:
            self.inspect[self.current_map[self.current_room][3][self.selection[0]][0]]()
        pass

    def update_val(self, array, i, val):
        try:
            array[i] = val.get()
        except:
            pass
        pass

    def update_val_arr(self, array, i, val, arr):
        try:
            array[i] = arr[val.get()]
        except:
            pass
        pass

    def update_color(self):
        c = self.current_map[self.current_room][2]
        res = colorchooser.askcolor(color=(c[0], c[1], c[2]))
        if res == None or res[0] == None:
            return
        c[0] = int(res[0][0])
        c[1] = int(res[0][1])
        c[2] = int(res[0][2])
        pass
    
    def inspect_points(self, pt_nb, obj):
        points = 0
        try:
            points = pt_nb.get()
        except:
            return
        if hasattr(self, 'points_inspected'):
            for pts in self.points_inspected:
                pts[0].destroy()
                pts[1].destroy()
        self.points_inspected = []
        self.var_dict = {}
        while len(obj) - 1 < points:
            if len(obj) < 1:
                obj.append([0, 0])
            else:
                obj.append(copy(obj[len(obj) - 1]))
        while len(obj) - 1 > points:
            obj.pop()
        for i in range(0, points):
            var_x = IntVar()
            var_y = IntVar()
            e_x = Entry(self.inspector, textvariable=var_x)
            e_y = Entry(self.inspector, textvariable=var_y)
            e_x.grid(column=0, row=2 + i)
            e_y.grid(column=1, row=2 + i)
            self.points_inspected.append([e_x, e_y, var_x, var_y])
            var_x.set(obj[i + 1][0])
            var_y.set(obj[i + 1][1])
            self.var_dict[var_x._name] = i
            self.var_dict[var_y._name] = i
            var_x.trace("w", lambda n, *a: (self.update_val(obj[self.var_dict[n] + 1], 0, self.points_inspected[self.var_dict[n]][2]), self.update_canvas()))
            var_y.trace("w", lambda n, *a: (self.update_val(obj[self.var_dict[n] + 1], 1, self.points_inspected[self.var_dict[n]][3]), self.update_canvas()))
        pass
    
    def inspect_object(self):
        obj = self.current_map[self.current_room][3][self.selection[0]]
        pt_nb = IntVar()
        pt_nb.set(len(obj) - 1)
        pt_nb.trace("w", lambda n, i, m: (self.inspect_points(pt_nb, obj), self.update_canvas()))
        Label(self.inspector, text="Wall", font='Helvetica 12 bold').grid(column=1, row=0)
        Label(self.inspector, text="Point nb").grid(column=0, row=1)
        Entry(self.inspector, width=10, textvariable=pt_nb).grid(column=1, row=1)
        self.inspect_points(pt_nb, obj)
        pass
    
    def inspect_light(self):
        obj = self.current_map[self.current_room][3][self.selection[0]]
        inten = IntVar()
        inten.set(obj[1])
        inten.trace("w", lambda *a: (self.update_val(obj, 1, inten), self.update_canvas()))
        Label(self.inspector, text="Light", font='Helvetica 12 bold').grid(column=1, row=0)
        Label(self.inspector, text="Intensity").grid(column=0, row=1)
        Entry(self.inspector, width=10, textvariable=inten).grid(column=1, row=1)
        status = IntVar()
        status.set(obj[2])
        status.trace("w", lambda *a: (self.update_val(obj, 2, status), self.update_canvas()))
        Checkbutton(self.inspector, text="Activated", variable=status).grid(column=1, row=2)
        var_x = IntVar()
        var_y = IntVar()
        var_x.set(obj[3][0])
        var_y.set(obj[3][1])
        var_x.trace("w", lambda *a: (self.update_val(obj[3], 0, var_x), self.update_canvas()))
        var_y.trace("w", lambda *a: (self.update_val(obj[3], 1, var_y), self.update_canvas()))
        Label(self.inspector, text="Position").grid(column=0, row=3)
        Entry(self.inspector, width=10, textvariable=var_x).grid(column=0, row=4)
        Entry(self.inspector, width=10, textvariable=var_y).grid(column=1, row=4)
        pass
    
    def inspect_entity(self):
        obj = self.current_map[self.current_room][3][self.selection[0]]
        inv_map = {v: k for k, v in entity_type.items()}
        Label(self.inspector, text="Entity", font='Helvetica 12 bold').grid(column=1, row=0)
        var_type = StringVar()
        var_type.set(inv_map[obj[1]])
        var_type.trace("w", lambda *a: self.update_val_arr(obj, 1, var_type, entity_type))
        OptionMenu(self.inspector, var_type, *entity_type.keys()).grid(column=0, row=1)
        var_x = IntVar()
        var_y = IntVar()
        var_x.set(obj[2][0])
        var_y.set(obj[2][1])
        var_x.trace("w", lambda *a: (self.update_val(obj[2], 0, var_x), self.update_canvas()))
        var_y.trace("w", lambda *a: (self.update_val(obj[2], 1, var_y), self.update_canvas()))
        Label(self.inspector, text="Position").grid(column=0, row=2)
        Entry(self.inspector, width=10, textvariable=var_x).grid(column=0, row=3)
        Entry(self.inspector, width=10, textvariable=var_y).grid(column=1, row=3)
        var_id = IntVar()
        var_state = IntVar()
        var_id.set(obj[3])
        var_state.set(obj[4])
        var_id.trace("w", lambda *a: (self.update_val(obj, 3, var_id), self.update_canvas()))
        var_state.trace("w", lambda *a: (self.update_val(obj, 4, var_state), self.update_canvas()))
        Label(self.inspector, text="ID").grid(column=0, row=4)
        Entry(self.inspector, width=10, textvariable=var_id).grid(column=1, row=4)
        Label(self.inspector, text="State").grid(column=0, row=5)
        Entry(self.inspector, width=10, textvariable=var_state).grid(column=1, row=5)
        pass
    
    def inspect_obj(self, obj):
        if obj[1] == 2:
            self.info_obj_label = Label(self.inspector, text="Object ID")
            self.info_obj_label.grid(column=0, row=4)
            obj_type = IntVar()
            obj_type.set(obj[3])
            obj_type.trace("w", lambda *a: self.update_val(obj, 3, obj_type))
            self.info_obj_entry = Entry(self.inspector, width=10, textvariable=obj_type)
            self.info_obj_entry.grid(column=1, row=4)
        pass

    def inspect_info(self):
        obj = self.current_map[self.current_room][3][self.selection[0]]
        print(obj)
        inv_map = {v: k for k, v in info_type.items()}
        Label(self.inspector, text="Info", font='Helvetica 12 bold').grid(column=1, row=0)
        var_type = StringVar()
        var_type.set(inv_map[obj[1]])
        var_type.trace("w", lambda *a: (self.update_val_arr(obj, 1, var_type, info_type), self.inspect_obj(obj)))
        OptionMenu(self.inspector, var_type, *info_type.keys()).grid(column=0, row=1)
        var_x = IntVar()
        var_y = IntVar()
        var_x.set(obj[2][0])
        var_y.set(obj[2][1])
        var_x.trace("w", lambda *a: (self.update_val(obj[2], 0, var_x), self.update_canvas()))
        var_y.trace("w", lambda *a: (self.update_val(obj[2], 1, var_y), self.update_canvas()))
        Label(self.inspector, text="Position").grid(column=0, row=2)
        Entry(self.inspector, width=10, textvariable=var_x).grid(column=0, row=3)
        Entry(self.inspector, width=10, textvariable=var_y).grid(column=1, row=3)
        self.inspect_obj(obj)
        pass
    
    def inspect_room(self):
        room = self.current_map[self.current_room]
        w_var = IntVar()
        h_var = IntVar()
        w_var.set(room[0])
        h_var.set(room[1])
        w_var.trace("w", lambda n, i, m: self.update_val(room, 0, w_var))
        h_var.trace("w", lambda n, i, m: self.update_val(room, 1, h_var))
        Label(self.inspector, text="Room #%d" % self.current_room, font='Helvetica 12 bold').grid(column=1, row=0)
        Label(self.inspector, text="width").grid(column=0, row=1)
        Label(self.inspector, text="height").grid(column=0, row=2)
        Entry(self.inspector, textvariable=w_var).grid(column=1, row=1)
        Entry(self.inspector, textvariable=h_var).grid(column=1, row=2)
        Button(self.inspector, text="Change color", command=self.update_color).grid(column=1, row=3)
        pass

    ################
    ##    DATA    ##
    ################
    
    def check_data(self, data):
        #TODO: perform data verification
        return (True)
    
    def load_with_open(self, save):
        data = json.load(save)
        if self.check_data(data):
            return (data)
        else:
            print("Corrupted data in file %s !" % previous)
        return (None)

    def load(self, previous):
        try:
            with open(previous) as save:
                return self.load_with_open(save)
        except:
            print("Could not load save %s !" % previous)
        return (None)

class Export():
    def __init__(self):
        self.write_type = {
            types["object"]: self.write_object,
            types["light"]: self.write_light,
            types["entity"]: self.write_entity,
            types["info"]: self.write_info,
            types["empty"]: self.no_op
        }
        pass
    
    def no_op(self, res, data):
        pass
    
    def write_map(self, filename, data):
        f = open(filename, 'wb')
        f.write(bytes(data))
        f.close()
    
    def append_short(self, res, data):
        if data > 65536:
            messagebox.showerror(title="export error", message="Trying too write big value ! (%d)" % data)
        if data < 0:
            messagebox.showerror(title="export error", message="Trying too write negative value ! (%d)" % data)
        res.append((data >> 8) & 0xFF)
        res.append(data & 0xFF)

    def append_color(self, res, color):
        if len(color) != 4:
            messagebox.showerror(title="export error", message="Incorrect color : "+ color)
        for c in color:
            res.append(c)

    def write_object(self, res, data):
        res.append(len(data) - 1)
        for point in data[1:]:
            self.append_short(res, point[0])
            self.append_short(res, point[1])

    def write_info(self, res, data):
        res.append(data[1])
        self.append_short(res, data[2][0])
        self.append_short(res, data[2][1])
        if (data[1] == 2):
            res.append(data[3])

    def write_light(self, res, data):
        self.append_short(res, data[1])
        if data[2] not in [0, 1]:
            messagebox.showerror(title="export error", message="Unknown light status:"+ data[2])
        self.append_short(res, data[3][0])
        self.append_short(res, data[3][1])

    def write_entity(self, res, data):
        if data[1] not in entity_type.values():
            messagebox.showerror(title="export error", message="Unknown entity type:"+ data[1])
        res.append(data[1])
        self.append_short(res, data[2][0])
        self.append_short(res, data[2][1])
        res.append(data[3])
        res.append(data[4])
        pass

    def write_object_to_file(self, fil, obj):
        array = self.data_to_array(obj)
        fil.write(bytes(array))
        pass
    
    def data_to_array(self, data):
        res = []
        for i, room in enumerate(data):
            res.append(ord('R'))
            res.append(i)
            self.append_short(res, room[0])
            self.append_short(res, room[1])
            self.append_color(res, room[2])
            for item in room[3]:
                item_type = item[0][0]
                if item_type not in self.write_type:
                    messagebox.showerror(title="export error", message="Incorrect item : unknown type %c ?" % item_type)
                res.append(ord(item_type))
                self.write_type[item_type](res, item)
        return (res)

def main():
    if len(sys.argv) > 2:
        exit(84)
    Editor(None if len(sys.argv) != 2 else sys.argv[1])

if __name__ == "__main__":
    main()
