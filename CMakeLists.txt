cmake_minimum_required(VERSION 3.0.2)
project(protosharp)
find_package(Protobuf 3.0.0 REQUIRED CONFIG)

set(SOURCE_FILES Main.cpp
				 WriteFile.cpp)
                 
set(HEADER_FILES Paths.h
				 WriteFile.h)

add_executable(protosharp-plugin ${SOURCE_FILES}
                                 ${HEADER_FILES})
                                     
target_link_libraries(protosharp-plugin PRIVATE protobuf::libprotoc)

install(TARGETS protosharp-plugin
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})