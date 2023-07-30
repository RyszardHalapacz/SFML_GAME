cmake_minimum_required(VERSION 3.0)
project(MyApp)

set(CMAKE_CXX_COMPILER "clang++")

set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/SFML")

include_directories("${SFML_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/include")
link_directories("${SFML_DIR}/lib")

# Używamy opcji IMPORTED, aby dołączyć już skompilowaną bibliotekę SFML
add_library(SFLM_LIB STATIC IMPORTED)

# Wskazujemy biblioteki SFML do podlinkowania
set_target_properties(SFLM_LIB PROPERTIES IMPORTED_LOCATION
    "${SFML_DIR}/lib/libsfml-graphics.so"
    "${SFML_DIR}/lib/libsfml-window.so"
    "${SFML_DIR}/lib/libsfml-system.so"
)

# Kopiujemy potrzebne pliki i nagłówki SFML
file(COPY "${SFML_DIR}/lib/" DESTINATION "${CMAKE_BINARY_DIR}/lib")
file(COPY "${SFML_DIR}/pkgconfig/" DESTINATION "${CMAKE_BINARY_DIR}/pkgconfig")
file(COPY "${SFML_DIR}/include/" DESTINATION "${CMAKE_BINARY_DIR}/include")

add_executable(MyApp 
    src/main.cpp 
    src/person.cpp
    src/MyWindow.cpp
    src/FieldOfView.cpp
    #src/Zombie.cpp    
)

# Linkujemy naszą aplikację z biblioteką SFML
target_link_libraries(MyApp PRIVATE SFLM_LIB sfml-graphics sfml-window sfml-system)

add_custom_target(run
    COMMAND "./MyApp"
    DEPENDS MyApp
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)
