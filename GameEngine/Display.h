#pragma once
#include <SDL2/SDL.h>
#undef main
#include <string>

class Display
{
public:
	Display(int width, int height, const std::string& title);

	void Clear(float r, float g, float b, float a);
	void Update();

	inline bool IsRunning() { return m_isRunning; }

	virtual ~Display();
private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isRunning;
};

