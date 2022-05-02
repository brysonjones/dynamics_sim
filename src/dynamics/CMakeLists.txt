
# Rotation lib
add_library(rotation STATIC rotation.cpp)

target_link_libraries(rotation PRIVATE 
                               autodiff::autodiff 
                               Eigen3::Eigen)

# Object lib
add_library(object STATIC object.cpp)

target_link_libraries(object PUBLIC 
                             autodiff::autodiff 
                             Eigen3::Eigen
                             rotation)

# Box lib
add_library(box STATIC box.cpp)

target_link_libraries(box PRIVATE
                          object)


