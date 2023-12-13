# set(LIB_SRC_FILES 
#   ./IndexBuffer.cpp
#   ./VertexBuffer.cpp
#   )
file(GLOB SOURCES "./*.cpp")
file (GLOB VENDOR_SOURCES "./include/vendor/*/*.cpp")
include_directories(renderer PUBLIC "./include/")
include_directories(renderer PUBLIC "./include/vendor/")
add_library(renderer ${SOURCES} ${VENDOR_SOURCES})
