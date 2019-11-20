cmake_minimum_required(VERSION 3.15)
project(CPP_rtype_2019)

# Define c++ version to use
set(CMAKE_CXX_STANDARD 14)

# Redefine c++ compiler version for MacOS
IF (${APPLE})
    set(CMAKE_C_COMPILER_VERSION "10")
    set(CMAKE_CXX_COMPILER_VERSION "10")
ENDIF (${APPLE})

# Setup conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

IF (${APPLE})
    conan_basic_setup(KEEP_RPATHS)
ELSE (${APPLE})
    conan_basic_setup()
ENDIF (${APPLE})

# Set Variable
SET(SERVER_SRC src/server/)
SET(CLIENT_SRC src/client/)

# Create executable
add_executable(r-type_server
        ${SERVER_SRC}main.cpp)

add_executable(r-type_client
        ${CLIENT_SRC}main.cpp)

# Link library to executable
target_link_libraries(r-type_server ${CONAN_LIBS})
target_link_libraries(r-type_client ${CONAN_LIBS})
