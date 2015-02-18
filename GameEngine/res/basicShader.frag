#version 120

varying mediump vec2 texCoord0;

uniform sampler2D diffuse;
uniform mediump float time;

void main()
{
	mediump float length = length(texCoord0);
	mediump float sinTime = sin(time);
	gl_FragColor = texture2D(diffuse, texCoord0 + sinTime) + vec4(length, -sinTime * length * 0.5, sinTime * length * 2.0, 1.0);
}