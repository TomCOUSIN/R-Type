/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_POSITION_HPP
#define CPP_RTYPE_2019_POSITION_HPP

namespace rtype {

    namespace engine {

        namespace component {

            class Position {

                // @MARK Public
                public:

                // @MARK Constructor / Destructor
                explicit Position(const float &x = 0, const float &y = 0);
                ~Position() = default;

                // @MARK Getter
                float getX() const;
                float getY() const;

                // @MARK Setter
                void setX(const float &x);
                void setY(const float &y);

                // @MARK Private
                private:

                // @MARK Attributes
                float _x;
                float _y;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_POSITION_HPP
