add_executable(open_gl ./main.cpp )
add_subdirectory("./renderer/")
include_directories(open_gl PUBLIC "./renderer/include/")
target_link_libraries(open_gl PUBLIC GL)
target_link_libraries(open_gl PUBLIC glfw3)
target_link_libraries(open_gl PUBLIC GLEW)
target_link_libraries(open_gl PUBLIC renderer)

