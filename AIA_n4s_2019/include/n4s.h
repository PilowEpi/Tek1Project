/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** n4s
*/

#ifndef N4S_H_
#define N4S_H_

typedef struct answer {
    unsigned char status; // 0 = KO | 1 = OK
    float info;
    long long time;
} answer_t;

typedef struct simulation {
    unsigned char status; // 0 = Not Running | 1 = Running
    answer_t *last_answer;
    float lidar[32];
    float max_speed;
    float min_speed;
} simulation_t;

char *exec_command(simulation_t *sim, char *command);
int get_lidar_information(simulation_t *sim);
simulation_t *init_simulation(void);
int start_simulation(simulation_t *sim);
void debug_answer(simulation_t *sim);

void ia(simulation_t *sim);

#endif /* !N4S_H_ */
