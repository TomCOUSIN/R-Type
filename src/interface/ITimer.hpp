/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_ITIMER_HPP
#define CPP_RTYPE_2019_ITIMER_HPP

namespace rtype::timer {

    /**
     * @brief Timer interface
     */
    class ITimer {

        public:
        /**
         * @brief Destroy an ITimes object
         */
        virtual ~ITimer() = default;

        /**
         * @brief Start the timer
         */
        virtual void start() = 0;

        /**
         * @brief Restart the timer
         */
        virtual void restart() = 0;

        /**
         * @brief Get the elapsed time
         *
         * @return the elapsed time
         */
        virtual float getElapsedTime() = 0;

        /**
         * @brief Stop the timer
         */
        virtual void stop() = 0;
    };
}

#endif //CPP_RTYPE_2019_ITIMER_HPP
