# set(LIB_SRC_FILES 
#   ./IndexBuffer.cpp
#   ./VertexBuffer.cpp
#   )
file(GLOB SOURCES "./*.cpp")
add_library(renderer ${SOURCES})
