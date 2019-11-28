cmake_minimum_required(VERSION 3.15)
project(CPP_rtype_2019)

# Define c++ version to use
set(CMAKE_CXX_STANDARD 17)

# Add more cmake module to cmake
list(APPEND CMAKE_MODULE_PATH cmake_module)

# Find for criterion to play tests
include(cmake_module/FindCriterion.cmake)

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

SET(SFML_SRC ${SHARED_SRC}sfml/)
SET(ENGINE_SRC ${SHARED_SRC}engine/)
SET(EXCEPTION_SRC ${SHARED_SRC}exception/)
SET(NETWORK_SRC ${ENGINE_SRC}network/)
SET(ENTITY_SRC ${ENGINE_SRC}entity/)
SET(COMPONENT_SRC ${ENGINE_SRC}component/)
SET(EVENT_SRC ${ENGINE_SRC}event/)

SET(COMPONENT_POSITION_SRC ${COMPONENT_SRC}position/)
SET(COMPONENT_SPEED_SRC ${COMPONENT_SRC}speed/)

SET(SFML_COMPONENT_SRC ${SFML_SRC}component/)
SET(SFML_SYSTEM_SRC ${SFML_SRC}system/)

# Include directories
include_directories(${INTERFACE_SRC})
include_directories(${ENGINE_SRC})
include_directories(${ENTITY_SRC})
include_directories(${EXCEPTION_SRC})
include_directories(${NETWORK_SRC})
include_directories(${COMPONENT_SRC})
include_directories(${COMPONENT_POSITION_SRC})
include_directories(${COMPONENT_SPEED_SRC})
include_directories(${SFML_COMPONENT_SRC})
include_directories(${SFML_SYSTEM_SRC})
include_directories(${EVENT_SRC})

# Set source files variable
SET(INTERFACE)

SET(COMPONENT)

SET(ENTITY)

SET(EXCEPTION
        ${EXCEPTION_SRC}BaseException.cpp)

SET(NETWORK
        ${NETWORK_SRC}BoostNetwork.cpp
        ${NETWORK_SRC}Packet.cpp)

SET(SFML
        ${SFML_SYSTEM_SRC}InputSystem.cpp
        ${SFML_SYSTEM_SRC}RenderSystem.cpp
        ${SFML_SYSTEM_SRC}PositionSystem.cpp
        ${SFML_SYSTEM_SRC}AnimationSystem.cpp
        ${SFML_SYSTEM_SRC}MovementSystem.cpp
        ${SFML_SYSTEM_SRC}ButtonSystem.cpp
        ${SFML_SYSTEM_SRC}ButtonSystem.Hpp)

SET(SHARED
        ${SFML}
        ${ENTITY}
        ${COMPONENT}
        ${EXCEPTION}
        ${NETWORK}
        ${EVENT_SRC}Event.cpp
        ${ENGINE_SRC}GameEngine.cpp)

SET(COMMON
        ${INTERFACE}
        ${SHARED})

SET(SERVER
        ${SERVER_SRC}main.cpp)

SET(CLIENT
        ${CLIENT_SRC}main.cpp)

SET(UNIT_TESTS
        ${COMMON}
        ${TESTS_SRC}packet_tests.cpp
        ${TESTS_SRC}boost_tests.cpp
        ${TESTS_SRC}component_storage_tests.cpp)

# Create executable
add_executable(r-type_server ${SERVER} ${COMMON})
add_executable(r-type_client ${CLIENT} ${COMMON})

message(${CONAN_LIBS})
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
    target_link_libraries(unit_tests ${CONAN_LIBS})
endif (${CRITERION_FOUND})
