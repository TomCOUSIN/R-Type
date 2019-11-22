/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_DIRECTION_HPP
#define CPP_RTYPE_2019_DIRECTION_HPP

namespace rtype {

    namespace engine {

        namespace component {

            class Direction {

                // @MARK Public
                public:

                // @MARK Constructor / Destructor
                explicit Direction(const bool &up = false, const bool &down = false, const bool &right = false, const bool &left = false);
                ~Direction() = default;

                // @MARK Getter
                bool getUp() const;
                bool getDown() const;
                bool getRight() const;
                bool getLeft() const;

                // @MARK Setter
                void setUp(const bool &up);
                void setDown(const bool &down);
                void setRight(const bool &right);
                void setLeft(const bool &left);

                // @MARK Private
                private:

                // @MARK Attributes
                bool _up;
                bool _down;
                bool _right;
                bool _left;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_DIRECTION_HPP
