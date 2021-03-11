#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform int u_lights_count;
uniform vec3[20] u_lights;

void main()
{
    float future = 0.0;
    for (int i = 0; i < u_lights_count; i++){
        vec2 l = vec2(u_lights[i].x, u_resolution.y - u_lights[i].y);
        vec2 pos = (gl_FragCoord.xy - l) / min(u_resolution.x, u_resolution.y);
        future += u_lights[i].z * 0.000001 / length(pos);
    }

    gl_FragColor = vec4(vec3(future), 1.0);
}
