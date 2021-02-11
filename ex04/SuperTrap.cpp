#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name)
    :	ClapTrap(name, 100, 60, 5, 0, 0), // TODO
		FragTrap(name),
		NinjaTrap(name)
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
