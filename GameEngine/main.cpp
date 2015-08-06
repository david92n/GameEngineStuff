#include <chrono>
#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"

int main()
{
	Display display(800, 600, "Game Engine");

	Shader shader("./res/basicShader");

	Vertex verticies[] =
	{
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f), glm::vec2(0.5f, 1.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec2(1.0f, 0.0f))
	};

	Texture texture("./res/bricks.jpg");

	Mesh mesh(verticies, sizeof(verticies) / sizeof(verticies[0]));

	Transform transform;

	auto startTime = std::chrono::high_resolution_clock::now();

	while (display.IsRunning())
	{
		auto currentTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> time = currentTime - startTime;

		display.Clear(0.0f, 0.0f, 0.0f, 1.0f);
		shader.Bind();
		shader.Update(transform, time.count());
		texture.Bind(0);
		mesh.Draw();

		display.Update();
	}

	return 0;
}
