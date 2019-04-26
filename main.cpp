#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

static void testContext()
{
	const int x = 100;
	const int y = 100;
	const int width = 640;
	const int height = 480;
	const int videoFlags = SDL_WINDOW_OPENGL;

	SDL_Init(SDL_INIT_VIDEO);

	// SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	// SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	// SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);

	auto * g_sdlWindow = SDL_CreateWindow("", x, y, width, height, videoFlags);
	auto * m_sdlGlContext = SDL_GL_CreateContext(g_sdlWindow);
	if ( !m_sdlGlContext )
	{
		printf("Failed to create OpenGL context??\n");
		exit(1);
	}

	auto * m_loadingGlContext = SDL_GL_CreateContext(g_sdlWindow);
	if ( !m_loadingGlContext )
	{
		printf("Failed to create OpenGL context for loading??\n");
		exit(1);
	}

	// KEY LINE FOLLOWS:
	//
	// With this SDL_GL_MakeCurrent() line, no visuals appear on screen under OS X
	// 10.14.4, but they DO appear under OS X 10.14.2.  Comment it out, and it works
	// everywhere.  Alternately, if you don't create the 'loadingGlContext' above,
	// it works on 10.14.4 whether or not you call SDL_GL_MakeCurrent().
	SDL_GL_MakeCurrent( g_sdlWindow, m_sdlGlContext ); // set back to the main context

	bool done = false;
	while(!done)
	{
		glClearColor((rand() % 100) / 100.f, 0.f, 0.f, 0.f);
		glClear(GL_COLOR_BUFFER_BIT);

		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			switch( e.type )
			{
				case SDL_KEYDOWN:
					done = true;
					break;
				default:
					break;
			}
		}

		SDL_GL_SwapWindow(g_sdlWindow);

	}
}

int main()
{
	testContext();
	return 0;
}
