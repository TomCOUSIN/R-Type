// /*
// ** EPITECH PROJECT, 2019
// ** CPP_rtype_2019
// ** File description:
// ** created by lucasmrdt
// */

// #ifndef EVENTMANAGER_HPP_
// #define EVENTMANAGER_HPP_

// #include <map>
// #include <functional>

// #include "Event.hpp"

// namespace rtype::engine::event {

//     // @MARK Types
//     using EventCallback = std::function<void(Event const &)>;

//     class EventManager {

//     // @MARK Constructors/Destructors
//         public:
//         /**
//          * @brief Construct a new Event Manager
//          */
//         EventManager();

//         /**
//          * @brief Destroy the Event Manager object
//          */
//         ~EventManager();

//     // @MARK Methods
//         public:
//         void subscribeTo(Event const &event, EventCallback);
//         void emit(Event const &event);

//     // @MARK Properties
//         private:
//         std::map<std::pair<EVENT_SENDER, EventType>, EventCallback> _listeners;

//     };

// }

// #endif /* !EVENTMANAGER_HPP_ */
