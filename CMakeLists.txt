cmake_minimum_required(VERSION 3.15)
project(CPP_rtype_2019)

# Define c++ version to use
set(CMAKE_CXX_STANDARD 14)

# Add more cmake module to cmake
list(APPEND CMAKE_MODULE_PATH cmake_module)

# Find for criterion to play tests
include(cmake_module/FindCriterion.cmake)

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
SET(TESTS_SRC tests/)
SET(INTERFACE_SRC ${SRC}interface/)
SET(SHARED_SRC ${SRC}shared/)
SET(SERVER_SRC ${SRC}server/)
SET(CLIENT_SRC ${SRC}client/)

SET(ENGINE_SRC ${SHARED_SRC}engine/)
SET(ENTITY_SRC ${ENGINE_SRC}entity/)
SET(COMPONENT_SRC ${ENGINE_SRC}components/)

SET(ENGINE_TESTS ${TESTS_SRC}engine/)
SET(ENTITY_TESTS ${ENGINE_TESTS}entity/)
SET(COMPONENT_TESTS ${ENGINE_TESTS}components/)

# Include directories
include_directories(${INTERFACE_SRC})
include_directories(${ENGINE_SRC})
include_directories(${ENTITY_SRC})
include_directories(${COMPONENT_SRC})

# Set source files variable
SET(INTERFACE
        ${INTERFACE_SRC}IGameEngine.hpp)

SET(SHARED
        ${COMPONENT_SRC}Position.cpp
        ${COMPONENT_SRC}Position.hpp
        ${COMPONENT_SRC}ComponentManager.hpp
        ${ENTITY_SRC}Entity.cpp
        ${ENTITY_SRC}Entity.hpp
        ${ENTITY_SRC}EntityManager.cpp
        ${ENTITY_SRC}EntityManager.hpp
        ${ENGINE_SRC}GameEngine.cpp
        ${ENGINE_SRC}GameEngine.hpp)

SET(COMMON
        ${SHARED}
        ${INTERFACE})

SET(SERVER
        ${SERVER_SRC}main.cpp)

SET(CLIENT
        ${CLIENT_SRC}main.cpp)

SET(UNIT_TESTS
        ${COMPONENT_TESTS}position_tests.cpp
        ${COMPONENT_TESTS}component_manager_tests.cpp
        ${ENTITY_TESTS}entity_tests.cpp
        ${ENTITY_TESTS}entity_manager_tests.cpp
        ${COMMON})

# Create executable
add_executable(r-type_server ${SERVER} ${COMMON})
add_executable(r-type_client ${CLIENT} ${COMMON})

# Link library to executable
target_link_libraries(r-type_server ${CONAN_LIBS})
target_link_libraries(r-type_client ${CONAN_LIBS})

# Create tests if criterion is found
if (${CRITERION_FOUND})
    # Add coverage option
    SET(CMAKE_CXX_FLAGS  --coverage)

    # Include criterion header
    include_directories(${CRITERION_INCLUDE_DIRS})

    # Create executable
    add_executable(unit_tests ${UNIT_TESTS})

    # Link executable to criterion
    target_link_libraries(unit_tests ${CRITERION_LIBRARIES})
endif (${CRITERION_FOUND})
