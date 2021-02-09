#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name)
    : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
    std::cout << "SUPR-TP ";
	std::cout << "Constructing " << name << '!';
	std::cout << std::endl;
}

SuperTrap::~SuperTrap()
{
    std::cout << "SUPR-TP ";
	std::cout << "Destructing " << name << '!';
	std::cout << std::endl;
}
