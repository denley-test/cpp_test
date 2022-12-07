cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(cppunitlite_test
  VERSION 0.0.1
  LANGUAGES CXX
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/third_party/cmake-modules")
find_package(CppUnitLite REQUIRED)
if(NOT CPPUNITLITE_FOUND)
  message("CppUnitLite not find!")
endif()

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
    ${CPPUNITLITE_INCLUDE_DIR}
)
target_sources(${PROJECT_NAME}
  PRIVATE
    main.cpp
    DequeDefaultTest.cpp
    DequeTest.cpp
    ${CMAKE_SOURCE_DIR}/src/Deque.cpp
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
  ${CPPUNITLITE_LIBRARY}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
