/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Fork
*/

#include "Fork.hpp"
#include "ForkException.hpp"

namespace rtype::encapsulation {

  void
  Fork::start(StarterFunction parent_starter, StarterFunction child_starter)
  {
    int ret = fork();

    if (ret == -1) {
      throw ForkException("Fail to fork");
    } else if (ret == 0) {
      child_starter();
    } else {
      parent_starter();
    }
  }

  void
  Fork::start(StarterFunction child_starter)
  {
    int ret = fork();

    if (ret == -1) {
      throw ForkException("Fail to fork");
    } else if (ret == 0) {
      child_starter();
    } else {
      // Nothing
    }
  }

}
