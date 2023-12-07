#ifndef GL_UTILS
#define GL_UTILS
#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <iostream>

// Define a macro to suppress a specific warning
#define SUPPRESS_WARNING_BEGIN #pragma GCC diagnostic push #pragma GCC diagnostic ignored "-Wint-to-pointer-cast" 

// Define a macro to end the warning suppression block
#define SUPPRESS_WARNING_END #pragma GCC diagnostic pop

void GLDebugMessageCallback(GLenum source, GLenum type, GLuint id,
                                     GLenum severity, GLsizei length,
                                     const GLchar *msg, const void *data);
#endif // !GL_UTILS
