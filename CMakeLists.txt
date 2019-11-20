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

# Set source path variable
SET(SRC src/)
SET(INTERFACE_SRC ${SRC}interface/)
SET(SHARED_SRC ${SRC}shared/)
SET(SERVER_SRC ${SRC}server/)
SET(CLIENT_SRC ${SRC}client/)

SET(ENGINE_SRC ${SHARED_SRC}engine/)
SET(MODULE_SRC ${ENGINE_SRC}module/)
SET(GRAPHIC_MODULE_SRC ${MODULE_SRC}graphic/)

# Include directories
include_directories(${INTERFACE_SRC})
include_directories(${ENGINE_SRC})
include_directories(${GRAPHIC_MODULE_SRC})

# Set source files variable
SET(INTERFACE
        ${INTERFACE_SRC}IGraphicModule.hpp
        ${INTERFACE_SRC}IGameEngine.hpp)

SET(SHARED
        ${ENGINE_SRC}GameEngine.cpp
        ${ENGINE_SRC}GameEngine.hpp
        ${GRAPHIC_MODULE_SRC}SfmlGraphicModule.cpp
        ${GRAPHIC_MODULE_SRC}SfmlGraphicModule.hpp)

SET(SERVER
        ${SHARED}
        ${INTERFACE}
        ${SERVER_SRC}main.cpp)

SET(CLIENT
        ${SHARED}
        ${INTERFACE}
        ${CLIENT_SRC}main.cpp)

# Create executable
add_executable(r-type_server ${SERVER})
add_executable(r-type_client ${CLIENT})

# Link library to executable
target_link_libraries(r-type_server ${CONAN_LIBS})
target_link_libraries(r-type_client ${CONAN_LIBS})
