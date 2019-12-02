/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Fork
*/

#ifndef Fork_HPP_
#define Fork_HPP_

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <functional>

namespace rtype::encapsulation {

  class Fork
  {
    // @MARK: Types
    public:
      using StarterFunction = std::function<void(void)>;

    // @MARK: Constructors/Destructors
    public:
      Fork(void) = default;
      ~Fork(void) = default;

    // @MARK: Methods
    public:
      static void start(StarterFunction parent_method, StarterFunction child_method);
      static void start(StarterFunction child_method);

  };

}

#endif /* !Fork_HPP_ */
