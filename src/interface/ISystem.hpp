/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_ISYSTEM_HPP
#define CPP_RTYPE_2019_ISYSTEM_HPP

namespace rtype {

    namespace engine {

        namespace system {

            class ISystem {

                // @MARK Public
                public:

                // @MARK Destructor
                virtual ~ISystem() = default;

                // @MARK Methods
                virtual void update() = 0;
            };
        }
    }
}
#endif //CPP_RTYPE_2019_ISYSTEM_HPP
