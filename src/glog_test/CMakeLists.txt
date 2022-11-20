cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(glog_test)

find_package(glog 0.7.0 REQUIRED)

add_executable(${PROJECT_NAME})
target_compile_features(${PROJECT_NAME}
  PRIVATE
    cxx_std_11
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
