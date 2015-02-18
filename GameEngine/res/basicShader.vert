#version 120

attribute vec3 position;
attribute vec2 texCoord;

varying vec2 texCoord0;

uniform mat4 transform;
uniform float time;

void main()
{
	texCoord0 = texCoord;

	float length = length(position);

	gl_Position = vec4(position + vec3(sin(time * length) * length * 0.7, cos(time * 0.5) * 0.5, 0.0), 1.0);
	gl_Position = transform * vec4(position, 1.0);
}