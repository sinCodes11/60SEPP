cmake_minimum_required(VERSION 3.20)
project(portscanner VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(portscanner
    main.cpp
    src/PortScanner.cpp
    src/ServiceDB.cpp
    src/OutputFormatter.cpp
)

target_include_directories(portscanner PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(portscanner Boost::program_options)

install(TARGETS portscanner DESTINATION bin)
