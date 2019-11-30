/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_SFMLTIMER_HPP
#define CPP_RTYPE_2019_SFMLTIMER_HPP

#include <SFML/System/Clock.hpp>
#include "ITimer.hpp"

namespace rtype::sfml::timer {

    /**
     * @brief SfmlTimer to handle a sfml clock
     */
    class SfmlTimer : public rtype::timer::ITimer {

        public:
        /**
         * @brief Construct a SfmlTimer object
         */
        SfmlTimer() = default;

        /**
         * @brief Destroy a SfmlTimer object
         */
        ~SfmlTimer() final = default;

        /**
         * @brief Start the timer
         */
        void start() final;

        /**
         * @brief Restart the timer
         */
        void restart() final;

        /**
         * @brief Get the elapsed time
         *
         * @return the elapsed time
         */
        float getElapsedTime() final;

        /**
         * @brief Stop the timer
         */
        void stop() final;

        private:
        /**
         * @brief The clock used as timer
         */
        sf::Clock _clock;
    };
}

#endif //CPP_RTYPE_2019_SFMLTIMER_HPP
