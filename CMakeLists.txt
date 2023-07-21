cmake_minimum_required(VERSION 3.10)
project(test)
find_package(CURL REQUIRED) #FIND CURL
find_package(nlohmann_json 3.11.2 REQUIRED) #FIND NLOHMANN_JSON
add_executable(test ./main.cpp)
target_link_libraries(test CURL::libcurl) #LINK libcurl
target_link_libraries(test nlohmann_json::nlohmann_json) #LINK nlohmann_json
target_include_directories(${PROJECT_NAME} PRIVATE include)