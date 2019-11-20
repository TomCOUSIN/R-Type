/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_SFMLGRAPHICMODULE_HPP
#define CPP_RTYPE_2019_SFMLGRAPHICMODULE_HPP

#include "IGraphicModule.hpp"

namespace rtype {

    namespace engine {

        namespace module {

            class SfmlGraphicModule : public IGraphicModule {

                // @MARK Public
                public:

                // @MARK Constructor / Destructor
                SfmlGraphicModule() = default;
                ~SfmlGraphicModule() final = default;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_SFMLGRAPHICMODULE_HPP
