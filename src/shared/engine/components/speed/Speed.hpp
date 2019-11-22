/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_SPEED_HPP
#define CPP_RTYPE_2019_SPEED_HPP

namespace rtype {

    namespace engine {

        namespace component {

            class Speed {

                // @MARK Public
                public:

                // @MARK Constructor / Destructor
                explicit Speed(const int &value = 1);
                ~Speed() = default;

                // @MARK Getter
                int getValue() const;

                // @MARK Setter
                void setValue(const int &value);

                private:
                int _value;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_SPEED_HPP
