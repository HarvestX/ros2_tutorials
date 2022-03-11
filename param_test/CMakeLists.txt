cmake_minimum_required(VERSION 3.8)
project(param_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
set(THIS_PACKAGE_INCLUDE_DEPENDS rclcpp)

# Param Test ========================================================
set(TARGET param_test)
add_executable(${TARGET})
target_sources(${TARGET} PRIVATE src/main.cpp)
ament_target_dependencies(${TARGET} ${THIS_PACKAGE_INCLUDE_DEPENDS})

# Append list
set(THIS_CREATED_EXEC_LIST ${THIS_CREATED_EXEC_LIST} ${TARGET})
# End Param Test ========================================================

# Install ===========================================================
install(TARGETS ${THIS_CREATED_EXEC_LIST} DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY launch config DESTINATION share/${PROJECT_NAME})
# End Install =======================================================

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
