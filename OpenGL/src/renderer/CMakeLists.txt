# set(LIB_SRC_FILES 
#   ./IndexBuffer.cpp
#   ./VertexBuffer.cpp
#   )
file(GLOB SOURCES "./*.cpp")
include_directories(renderer PUBLIC "./include/")
add_library(renderer ${SOURCES})
