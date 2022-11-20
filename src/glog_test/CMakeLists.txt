cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(glog_test
  VERSION 0.0.1
  LANGUAGES CXX
)

find_package(glog 0.7.0 REQUIRED)

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
    ${PROJECT_SOURCE_DIR}/include
)
target_sources(${PROJECT_NAME}
  PRIVATE
    main.cpp
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
  glog::glog
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
