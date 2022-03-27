
add_library(rotation rotation.cpp)

target_link_libraries(rotation PRIVATE autodiff::autodiff Eigen3::Eigen)
