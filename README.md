# Test project for SDL2 OpenGL rendering issues on OS X 10.14.4

I'm investigating rendering problems which occur when rendering using OpenGL
using SDL2 on macOS v10.14.4.  The issues don't appear to happen under 10.14.2 and earlier,
and I've been unable to test 10.14.3;  problems may or may not be visible there.

This program creates a window and draws fullscreen red or black each frame.  Under 10.14.4,
though, those red and black colors don't appear in the window at all.

The combination of factors which reliably produce the problem appear to be:

 1.  Create two rendering contexts associated with the window.
 2.  Call `SDL_GL_MakeCurrent()` to set the first context as active.


