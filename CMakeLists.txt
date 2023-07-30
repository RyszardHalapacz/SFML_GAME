cmake_minimum_required(VERSION 3.14)
project(MyApp)

#set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#GTEST

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


#SFML


set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/SFML")

include_directories("${SFML_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/include")
link_directories("${SFML_DIR}/lib")


add_library(SFLM_LIB STATIC IMPORTED)


set_target_properties(SFLM_LIB PROPERTIES IMPORTED_LOCATION
    "${SFML_DIR}/lib/libsfml-graphics.so"
    "${SFML_DIR}/lib/libsfml-window.so"
    "${SFML_DIR}/lib/libsfml-system.so"
)


file(COPY "${SFML_DIR}/lib/" DESTINATION "${CMAKE_BINARY_DIR}/lib")
file(COPY "${SFML_DIR}/pkgconfig/" DESTINATION "${CMAKE_BINARY_DIR}/pkgconfig")
file(COPY "${SFML_DIR}/include/" DESTINATION "${CMAKE_BINARY_DIR}/include")

enable_testing()

set(TEST_SOURCES   
src/person.cpp
src/MyWindow.cpp
src/FieldOfView.cpp
test/test.cpp)

add_executable(
  hello_test
  ${TEST_SOURCES}

)
target_link_libraries(hello_test PRIVATE SFLM_LIB sfml-graphics sfml-window sfml-system
GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(hello_test)


add_executable(MyApp 
    src/main.cpp 
    src/person.cpp
    src/MyWindow.cpp
    src/FieldOfView.cpp
    #src/Zombie.cpp    
)


target_link_libraries(MyApp PRIVATE SFLM_LIB sfml-graphics sfml-window sfml-system)

add_custom_target(run
    COMMAND "./MyApp"
    DEPENDS MyApp
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)
