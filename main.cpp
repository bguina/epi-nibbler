// 
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#include <iostream>
#include <stdexcept>

#include "Game.hpp"

int main(int ac, char **av)
{
    try
    {
      Game::run(ac, av);      
      return (0);
    }
    catch (std::invalid_argument const& e)
      {
        std::cerr
            << e.what() << std::endl
            << av[0] << ": " << Game::usage << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (-1);
}
