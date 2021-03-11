#ifdef GL_ES
precision mediump float;
#endif

uniform vec3 u_color;
uniform vec2 u_pos;
uniform vec2 u_resolution;
uniform int u_size;

void main()
{
    vec2 l = vec2(u_pos.x, u_resolution.y - u_pos.y);
    vec2 p = (gl_FragCoord.xy - l) / min(u_resolution.x, u_resolution.y);
    float future = float(u_size) * 0.00001 / length(p);
    
    gl_FragColor = vec4(u_color * future, future);
    //gl_FragColor = vec4(1.0);
}
