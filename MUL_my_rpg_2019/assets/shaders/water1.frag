#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;
uniform vec2 u_resolution;

void main()
{
    vec2 pos = 20.0 * (gl_FragCoord.xy - u_resolution / 2.0) / min(u_resolution.x, u_resolution.y);
    float len;

    for (int i = 0; i < 20; i++){
        len = length(vec2(pos.x, pos.y));

        pos.x = pos.x - cos(pos.y + sin(len)) + cos(u_time / 10000.0);
        pos.y = pos.y + sin(pos.x + cos(len)) + sin(u_time / 20000.0);
    }
    gl_FragColor = vec4(vec3(cos(len)), 1.0);//cos(len * 2.0), cos(len * 3.0), cos(len)
}
