# C++ Rendering API with OpenGL

This project implements a Rendering API in C++ using OpenGL. It provides various components such as shaders, models, textures, and a rendering engine.

## Components

### Camera
- **Camera.hpp**
  - Manages the camera position, orientation, and view matrix.
  - Allows translation and rotation of the camera.
  - Supports clamping of yaw and pitch angles.

### Index Buffer
- **IndexBuffer.hpp**
  - Handles OpenGL index buffers.
  - Provides methods for binding and unbinding index buffers.

### Input Handling
- **Input.hpp**
  - Manages keyboard and mouse input using GLFW.
  - Tracks cursor movement and keyboard state.
  - Allows setting scroll callbacks.

### Lighting
- **Light.hpp**
  - Defines structures for directional light, point light, and material.
  - Includes properties such as direction, ambient, diffuse, specular, and attenuation factors.

### Model Loading
- **Model.hpp**
  - Loads 3D models using Assimp library.
  - Processes meshes and textures.
  - Draws the model using provided shaders.

### Renderer
- **Renderer.hpp**
  - Provides a rendering interface using OpenGL.
  - Supports rendering of vertex arrays, index buffers, models, and shaders.
  - Manages depth testing and clears the screen.

### Shaders
- **Shaders.hpp**
  - Loads and compiles vertex and fragment shaders.
  - Provides methods to bind and unbind shaders.
  - Sets uniforms for matrices, lights, and materials.

### Textures
- **Texture2D.hpp**
  - Loads 2D textures from file.
  - Binds and unbinds textures to OpenGL texture units.
  - Retrieves texture properties such as width, height, and file path.

### Vertex Array and Buffer
- **VertexArray.hpp**
- **VertexBuffer.hpp**
- **VertexBufferLayout.hpp**
  - Encapsulates OpenGL vertex array objects and vertex buffer objects.
  - Handles vertex buffer layouts and attribute pointers.

## Usage

To use this library, include the necessary headers in your C++ project and link against OpenGL and GLFW libraries.

##Build
```bash
mkdir build
cd build
cmake ..
make -j $(nproc)
```
