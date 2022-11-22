cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(gtest_test
  VERSION 0.0.1
  LANGUAGES CXX
)

find_package(GTest REQUIRED)
add_executable(${PROJECT_NAME})
set_target_properties(${PROJECT_NAME}
  PROPERTIES
    VERSION ${PROJECT_VERSION}
)
target_compile_features(${PROJECT_NAME}
  PRIVATE
    cxx_std_11
)
target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}
    ${GTEST_INCLUDE_DIRS}
)
target_sources(${PROJECT_NAME}
  PRIVATE
    main.cpp
    DequeTest.cpp
    ${CMAKE_SOURCE_DIR}/src/Deque.cpp
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
  ${GTEST_BOTH_LIBRARIES}
  pthread
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
