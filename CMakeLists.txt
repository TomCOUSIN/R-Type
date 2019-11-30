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

SET(GAME_SRC ${CLIENT_SRC}game/)
SET(SFML_SRC ${SHARED_SRC}sfml/)
SET(ENGINE_SRC ${SHARED_SRC}engine/)
SET(EXCEPTION_SRC ${SHARED_SRC}exception/)
SET(NETWORK_SRC ${ENGINE_SRC}network/)
SET(ENTITY_SRC ${ENGINE_SRC}entity/)
SET(SYSTEM_SRC ${ENGINE_SRC}system/)
SET(COMPONENT_SRC ${ENGINE_SRC}component/)
SET(EVENT_SRC ${ENGINE_SRC}event/)

SET(COMPONENT_POSITION_SRC ${COMPONENT_SRC}position/)
SET(COMPONENT_SPEED_SRC ${COMPONENT_SRC}speed/)

SET(SFML_COMPONENT_SRC ${SFML_SRC}component/)
SET(SFML_SYSTEM_SRC ${SFML_SRC}system/)
SET(SFML_GRAPHIC_SRC ${SFML_SRC}graphic/)
SET(SFML_TIMER_SRC ${SFML_SRC}timer/)
SET(SFML_EVENT_SRC ${SFML_SRC}event/)
SET(SFML_ENTITY_SRC ${SFML_SRC}entity/)

SET(GAME_SCENE_SRC ${GAME_SRC}scene/)

# Include directories
include_directories(${INTERFACE_SRC})
include_directories(${ENGINE_SRC})
include_directories(${ENTITY_SRC})
include_directories(${EXCEPTION_SRC})
include_directories(${NETWORK_SRC})
include_directories(${SYSTEM_SRC})
include_directories(${EVENT_SRC})
include_directories(${COMPONENT_SRC})
include_directories(${COMPONENT_POSITION_SRC})
include_directories(${COMPONENT_SPEED_SRC})
include_directories(${SFML_COMPONENT_SRC})
include_directories(${SFML_GRAPHIC_SRC})
include_directories(${SFML_SYSTEM_SRC})
include_directories(${SFML_EVENT_SRC})
include_directories(${SFML_TIMER_SRC})
include_directories(${SFML_ENTITY_SRC})
include_directories(${GAME_SCENE_SRC})
include_directories(${INTERFACE_SRC})
include_directories(${EXCEPTION_SRC})
include_directories(${COMPONENT_SRC})
include_directories(${ENGINE_SRC})
include_directories(${NETWORK_SRC})
include_directories(${EVENT_SRC})
include_directories(${GAME_SRC})

# Set source files variable
SET(INTERFACE
        ${INTERFACE_SRC}ITimer.hpp
        ${INTERFACE_SRC}IScene.hpp
        ${INTERFACE_SRC}IEvent.hpp
        ${INTERFACE_SRC}ISystem.hpp
        ${INTERFACE_SRC}IGraphic.hpp)

SET(COMPONENT
        ${COMPONENT_SRC}Speed.hpp
        ${COMPONENT_SRC}Collision.hpp
        ${COMPONENT_SRC}Position.hpp
        ${COMPONENT_SRC}ComponentStorage.hpp
        ${COMPONENT_SRC}Component.hpp
        ${COMPONENT_SRC}Health.hpp)

SET(ENTITY
        ${ENTITY_SRC}EntityCreator.cpp
        ${ENTITY_SRC}EntityCreator.hpp
        ${ENTITY_SRC}Entity.hpp)

SET(EXCEPTION
        ${EXCEPTION_SRC}BaseException.cpp)

SET(EVENT
        ${EVENT_SRC}CollisionEvent.cpp
        ${EVENT_SRC}CollisionEvent.hpp
        ${EVENT_SRC}Event.cpp
        ${EVENT_SRC}Event.hpp)

SET(SYSTEM
        ${SYSTEM_SRC}CollisionSystem.cpp
        ${SYSTEM_SRC}CollisionSystem.hpp)

SET(NETWORK
        ${NETWORK_SRC}BoostNetwork.cpp
        ${NETWORK_SRC}Packet.cpp)

SET(SFML
        ${SFML_ENTITY_SRC}MouseEntity.hpp
        ${SFML_ENTITY_SRC}MouseEntity.cpp
        ${SFML_ENTITY_SRC}ButtonEntity.hpp
        ${SFML_ENTITY_SRC}ButtonEntity.cpp
        ${SFML_EVENT_SRC}InputEvent.cpp
        ${SFML_EVENT_SRC}InputEvent.hpp
        ${SFML_SYSTEM_SRC}InputSystem.cpp
        ${SFML_SYSTEM_SRC}InputSystem.hpp
        ${SFML_SYSTEM_SRC}RenderSystem.cpp
        ${SFML_SYSTEM_SRC}RenderSystem.hpp
        ${SFML_SYSTEM_SRC}PositionSystem.cpp
        ${SFML_SYSTEM_SRC}PositionSystem.hpp
        ${SFML_SYSTEM_SRC}AnimationSystem.cpp
        ${SFML_SYSTEM_SRC}AnimationSystem.hpp
        ${SFML_SYSTEM_SRC}MovementSystem.cpp
        ${SFML_SYSTEM_SRC}MovementSystem.hpp
        ${SFML_SYSTEM_SRC}ButtonSystem.cpp
        ${SFML_SYSTEM_SRC}ButtonSystem.Hpp
        ${SFML_COMPONENT_SRC}Sprite.hpp
        ${SFML_COMPONENT_SRC}Button.hpp
        ${SFML_COMPONENT_SRC}Text.hpp
        ${SFML_GRAPHIC_SRC}SfmlGraphic.cpp
        ${SFML_GRAPHIC_SRC}SfmlGraphic.hpp
        ${SFML_TIMER_SRC}SfmlTimer.cpp
        ${SFML_TIMER_SRC}SfmlTimer.hpp)

SET(SHARED
        ${ENTITY}
        ${SFML}
        ${COMPONENT}
        ${EXCEPTION}
        ${NETWORK}
        ${EVENT}
        ${SYSTEM}
        ${ENGINE_SRC}GameEngine.cpp
        ${ENGINE_SRC}GameEngine.hpp)

SET(COMMON
        ${INTERFACE}
        ${SHARED})

SET(GAME
        ${GAME_SCENE_SRC}MenuScene.cpp
        ${GAME_SCENE_SRC}MenuScene.hpp
        ${GAME_SCENE_SRC}GameScene.cpp
        ${GAME_SCENE_SRC}GameScene.hpp
        ${GAME_SRC}Game.cpp
        ${GAME_SRC}Game.hpp)

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
add_executable(r-type_client ${CLIENT} ${COMMON} ${GAME})

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
