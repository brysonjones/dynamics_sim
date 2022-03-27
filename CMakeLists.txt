cmake_minimum_required(VERSION 3.15.0)
project (simulator VERSION 1.0.0
                     DESCRIPTION "A project for testing simulation methods"
                     HOMEPAGE_URL "https://github.com/brysonjones/dynamics_sim")
set(CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
include(FetchContent)

# TODO: Eigen should already be found the autodiff repo below, but it is not
#       fix this to be more robust
find_package(Eigen3 3.3 REQUIRED) 

# Get Auto-Diff repo
set(AUTODIFF_BUILD_TESTS OFF)
set(AUTODIFF_BUILD_PYTHON OFF)
set(AUTODIFF_BUILD_EXAMPLES OFF)
set(AUTODIFF_BUILD_DOCS OFF)
FetchContent_Declare(
  autodiff_repo
  GIT_REPOSITORY https://github.com/autodiff/autodiff.git
  GIT_TAG        main
)
FetchContent_MakeAvailable(autodiff_repo)

enable_testing()

add_subdirectory(src)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE autodiff::autodiff Eigen3::Eigen)

# target_include_directories(${PROJECT_NAME} autodiff)
