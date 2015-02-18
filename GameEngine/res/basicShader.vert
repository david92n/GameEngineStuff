#version 120

attribute vec3 position;
attribute vec2 texCoord;

varying vec2 texCoord0;

uniform float time;

void main()
{

	float length = length(position);

	gl_Position = vec4(position + vec3(sin(time * length) * length * 0.7, cos(time * 0.5) * 0.5, 0.0), 1.0);
	texCoord0 = texCoord;
}