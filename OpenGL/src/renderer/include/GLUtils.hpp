#ifndef GL_UTILS
#define GL_UTILS
#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <iostream>
void GLDebugMessageCallback(GLenum source, GLenum type, GLuint id,
                                     GLenum severity, GLsizei length,
                                     const GLchar *msg, const void *data);
#endif // !GL_UTILS
