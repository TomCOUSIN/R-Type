cmake_minimum_required(VERSION 3.11)
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

SET(ENCAPSULATION_SRC ${SHARED_SRC}encapsulation/)
SET(GAME_SRC ${SHARED_SRC}game/)
SET(SFML_SRC ${SHARED_SRC}sfml/)
SET(ENGINE_SRC ${SHARED_SRC}engine/)
SET(EXCEPTION_SRC ${SHARED_SRC}exception/)
SET(NETWORK_SRC ${SHARED_SRC}network/)
SET(ENTITY_SRC ${ENGINE_SRC}entity/)
SET(LOADER_SRC ${ENGINE_SRC}loader/)
SET(SYSTEM_SRC ${ENGINE_SRC}system/)
SET(COMPONENT_SRC ${ENGINE_SRC}component/)
SET(EVENT_SRC ${ENGINE_SRC}event/)

SET(FORK_SRC ${ENCAPSULATION_SRC}fork/)

SET(COMPONENT_POSITION_SRC ${COMPONENT_SRC}position/)
SET(COMPONENT_SPEED_SRC ${COMPONENT_SRC}speed/)

SET(SFML_COMPONENT_SRC ${SFML_SRC}component/)
SET(SFML_SYSTEM_SRC ${SFML_SRC}system/)
SET(SFML_GRAPHIC_SRC ${SFML_SRC}graphic/)
SET(SFML_TIMER_SRC ${SFML_SRC}timer/)
SET(SFML_EVENT_SRC ${SFML_SRC}event/)
SET(SFML_ENTITY_SRC ${SFML_SRC}entity/)
SET(SFML_AUDIO_SRC ${SFML_SRC}audio/)

SET(GAME_SCENE_SRC ${GAME_SRC}scene/)
SET(GAME_COMPONENT_SRC ${GAME_SRC}component/)

# Include directories
include_directories(${SRC})
include_directories(${CLIENT_SRC})
include_directories(${INTERFACE_SRC})
include_directories(${ENGINE_SRC})
include_directories(${ENTITY_SRC})
include_directories(${EXCEPTION_SRC})
include_directories(${NETWORK_SRC})
include_directories(${SYSTEM_SRC})
include_directories(${EVENT_SRC})
include_directories(${FORK_SRC})
include_directories(${COMPONENT_SRC})
include_directories(${COMPONENT_POSITION_SRC})
include_directories(${COMPONENT_SPEED_SRC})
include_directories(${SFML_COMPONENT_SRC})
include_directories(${SFML_GRAPHIC_SRC})
include_directories(${SFML_SYSTEM_SRC})
include_directories(${SFML_EVENT_SRC})
include_directories(${SFML_TIMER_SRC})
include_directories(${SFML_ENTITY_SRC})
include_directories(${SFML_AUDIO_SRC})
include_directories(${GAME_SCENE_SRC})
include_directories(${INTERFACE_SRC})
include_directories(${EXCEPTION_SRC})
include_directories(${COMPONENT_SRC})
include_directories(${ENGINE_SRC})
include_directories(${ENTITY_SRC})
include_directories(${NETWORK_SRC})
include_directories(${EVENT_SRC})
include_directories(${GAME_SRC})
include_directories(${LOADER_SRC})

# Set source files variable
SET(INTERFACE
        ${INTERFACE_SRC}ITimer.hpp
        ${INTERFACE_SRC}IScene.hpp
        ${INTERFACE_SRC}IEvent.hpp
        ${INTERFACE_SRC}IAudio.hpp
        ${INTERFACE_SRC}ISystem.hpp
        ${INTERFACE_SRC}IGraphic.hpp
        ${INTERFACE_SRC}IEntityLoader.hpp)

SET(ENCAPSULATION
        ${FORK_SRC}ForkException.hpp
        ${FORK_SRC}Fork.hpp
        ${FORK_SRC}Fork.cpp)

SET(COMPONENT
        ${COMPONENT_SRC}Speed.hpp
        ${COMPONENT_SRC}Key.hpp
        ${COMPONENT_SRC}Collision.hpp
        ${COMPONENT_SRC}Position.hpp
        ${COMPONENT_SRC}ComponentStorage.hpp
        ${COMPONENT_SRC}Component.hpp)

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
        ${NETWORK_SRC}Network.cpp
        ${NETWORK_SRC}Network.hpp
        ${NETWORK_SRC}NetworkException.hpp
        ${NETWORK_SRC}BoostNetwork.cpp
        ${NETWORK_SRC}BoostNetwork.hpp
        ${NETWORK_SRC}BoostNetworkException.hpp
        ${NETWORK_SRC}Packet.cpp
        ${NETWORK_SRC}Packet.hpp
        ${NETWORK_SRC}PacketException.hpp)

SET(SFML
        ${SFML_ENTITY_SRC}SoundEntity.cpp
        ${SFML_ENTITY_SRC}SoundEntity.hpp
        ${SFML_ENTITY_SRC}SpriteEntity.cpp
        ${SFML_ENTITY_SRC}SpriteEntity.hpp
        ${SFML_ENTITY_SRC}MouseEntity.hpp
        ${SFML_ENTITY_SRC}MouseEntity.cpp
        ${SFML_ENTITY_SRC}ButtonEntity.hpp
        ${SFML_ENTITY_SRC}ButtonEntity.cpp
        ${SFML_ENTITY_SRC}InputEntity.hpp
        ${SFML_ENTITY_SRC}InputEntity.cpp
        ${SFML_ENTITY_SRC}BulletEntity.cpp
        ${SFML_ENTITY_SRC}BulletEntity.hpp
        ${SFML_ENTITY_SRC}EnemyEntity.cpp
        ${SFML_ENTITY_SRC}EnemyEntity.hpp
        ${SFML_ENTITY_SRC}ParallaxEntity.cpp
        ${SFML_ENTITY_SRC}ParallaxEntity.hpp
        ${SFML_EVENT_SRC}InputEvent.cpp
        ${SFML_EVENT_SRC}InputEvent.hpp
        ${SFML_EVENT_SRC}FireEvent.cpp
        ${SFML_EVENT_SRC}FireEvent.hpp
        ${SFML_SYSTEM_SRC}InputSystem.cpp
        ${SFML_SYSTEM_SRC}InputSystem.hpp
        ${SFML_SYSTEM_SRC}RenderSystem.cpp
        ${SFML_SYSTEM_SRC}RenderSystem.hpp
        ${SFML_SYSTEM_SRC}PositionSystem.cpp
        ${SFML_SYSTEM_SRC}PositionSystem.hpp
        ${SFML_SYSTEM_SRC}AnimationSystem.cpp
        ${SFML_SYSTEM_SRC}AnimationSystem.hpp
        ${SFML_SYSTEM_SRC}ButtonSystem.cpp
        ${SFML_SYSTEM_SRC}ButtonSystem.hpp
        ${SFML_SYSTEM_SRC}ParallaxSystem.cpp
        ${SFML_SYSTEM_SRC}ParallaxSystem.hpp
        ${SFML_SYSTEM_SRC}BulletSystem.cpp
        ${SFML_SYSTEM_SRC}BulletSystem.hpp
        ${SFML_SYSTEM_SRC}EnemySystem.cpp
        ${SFML_SYSTEM_SRC}EnemySystem.hpp
        ${SFML_COMPONENT_SRC}Sprite.hpp
        ${SFML_COMPONENT_SRC}Button.hpp
        ${SFML_COMPONENT_SRC}Sound.hpp
        ${SFML_COMPONENT_SRC}Music.hpp
        ${SFML_COMPONENT_SRC}Text.hpp
        ${SFML_GRAPHIC_SRC}SfmlGraphic.cpp
        ${SFML_GRAPHIC_SRC}SfmlGraphic.hpp
        ${SFML_TIMER_SRC}SfmlTimer.cpp
        ${SFML_TIMER_SRC}SfmlTimer.hpp
        ${SFML_AUDIO_SRC}SfmlAudio.cpp
        ${SFML_AUDIO_SRC}SfmlAudio.hpp)

SET(SHARED
        ${SRC}Shared.hpp
        ${ENCAPSULATION}
        ${ENTITY}
        ${SFML}
        ${ENTITY}
        ${COMPONENT}
        ${EXCEPTION}
        ${NETWORK}
        ${EVENT}
        ${SYSTEM}
        ${LOADER_SRC}DLLoader.hpp
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
        ${GAME_SCENE_SRC}LobbyScene.cpp
        ${GAME_SCENE_SRC}LobbyScene.hpp
        ${GAME_SCENE_SRC}LoginScene.cpp
        ${GAME_SCENE_SRC}LoginScene.hpp
        ${GAME_COMPONENT_SRC}Health.hpp
        ${GAME_SRC}Game.cpp
        ${GAME_SRC}Game.hpp)

SET(SERVER
        ${CLIENT_SRC}ClientNetwork.cpp
        ${CLIENT_SRC}ClientNetwork.hpp
        ${SERVER_SRC}ServerSession.cpp
        ${SERVER_SRC}ServerSession.hpp
        ${SERVER_SRC}ServerNetwork.cpp
        ${SERVER_SRC}ServerNetwork.hpp
        ${SERVER_SRC}main.cpp)

SET(CLIENT
        ${CLIENT_SRC}ClientNetwork.cpp
        ${CLIENT_SRC}ClientNetwork.hpp
        ${CLIENT_SRC}main.cpp)

SET(UNIT_TESTS
        ${COMMON}
        ${TESTS_SRC}packet_tests.cpp
        ${TESTS_SRC}boost_tests.cpp
        ${TESTS_SRC}component_storage_tests.cpp)

# Create executable
add_executable(r-type_server ${SERVER} ${COMMON} ${GAME})
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
