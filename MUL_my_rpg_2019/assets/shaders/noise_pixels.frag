#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;
uniform vec2 u_resolution;

float rand(vec2 pos)
{
    return fract(sin(dot(floor(pos), vec2(12.3862, 24.233))) * 41234.23456784 + u_time / 4000.0);
}

void main()
{
    gl_FragColor = vec4(vec3(rand(10.0 * gl_FragCoord.xy / u_resolution)), 1.0);
}