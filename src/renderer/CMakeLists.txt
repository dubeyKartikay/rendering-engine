# set(LIB_SRC_FILES 
#   ./IndexBuffer.cpp
#   ./VertexBuffer.cpp
#   )
file(GLOB SOURCES "./*.cpp")
file (GLOB VENDOR_SOURCES "./include/vendor/*/*.cpp")
include_directories(renderer PUBLIC "./include/vendor/")
include_directories(renderer PUBLIC "./include/")
add_library(renderer ${SOURCES} ${VENDOR_SOURCES})
target_link_libraries(renderer PUBLIC assimp)
