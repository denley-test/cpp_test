cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(cpp_test
  VERSION 0.0.1
  LANGUAGES CXX
)

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
)
target_sources(${PROJECT_NAME}
  PRIVATE
    main.cpp
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
