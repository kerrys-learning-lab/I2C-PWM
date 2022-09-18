cmake_minimum_required(VERSION 3.8)
project(i2c_pwm)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_library(${PROJECT_NAME} SHARED
  src/Pca9685.cpp
  src/Pca9685Impl.cpp
  src/Pca9685Mock.cpp
)

find_library(
  LIB_I2C
  libi2c.a
  PATHS /usr/lib/x86_64-linux-gnu
  REQUIRED
)

ament_target_dependencies(${PROJECT_NAME}
  rclcpp
)

ament_export_targets(export_${PROJECT_NAME}
  HAS_LIBRARY_TARGET
)

install(
  DIRECTORY include/
  DESTINATION include
)

install(TARGETS
  ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  INCLUDES DESTINATION include
)


target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Declare our dependency on libi2c, so that CMake will link libi2c
# transitively when this library is used.
target_link_libraries(${PROJECT_NAME}
  ${LIB_I2C}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
