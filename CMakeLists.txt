cmake_minimum_required(VERSION 3.0)
project(MyApp)

set(CMAKE_CXX_COMPILER "clang++")


set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML")


include_directories("${SFML_DIR}/include")
include_directories(" ${CMAKE_SOURCE_DIR}/include")
link_directories("${SFML_DIR}/lib")


add_executable(MyApp main.cpp 
    src/person.cpp
    src/MyWindow.cpp
    src/FieldOfView.cpp
    #src/Zombie.cpp
    
    )


target_link_libraries(MyApp PRIVATE
    "${SFML_DIR}/lib/libsfml-graphics.so"
    "${SFML_DIR}/lib/libsfml-window.so"
    "${SFML_DIR}/lib/libsfml-system.so"
)


file(COPY "${SFML_DIR}/lib/" DESTINATION "${CMAKE_BINARY_DIR}/lib")
file(COPY "${SFML_DIR}/pkgconfig/" DESTINATION "${CMAKE_BINARY_DIR}/pkgconfig")
file(COPY "${SFML_DIR}/include/" DESTINATION "${CMAKE_BINARY_DIR}/include")


add_custom_target(run
    COMMAND "./MyApp"
    DEPENDS MyApp
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)
