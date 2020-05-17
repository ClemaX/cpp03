#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "SC4V-TP ";
	std::cout << "Constructing " << name << '!';
	std::cout << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SC4V-TP ";
	std::cout << "Destructing " << name << '!';
	std::cout << std::endl;
}

void ScavTrap::challengeNewcomer(void)
{
	std::cout << "SC4V-TP ";
	std::cout << name << " challenges a newcomer: ";
	std::cout << challenges[rand() % challenges.size()] << std::endl;
}

void ScavTrap::performAttack(std::string &source, std::string const &target, ClapTrap::Attack const &attack)
{	
	std::cout << "SC4V-TP ";
	std::cout << source << " attacks " << target << ' ';
	std::cout << "with " << attack.name << ", ";
	std::cout << "causing " << attack.damage << " points of damage!";
	std::cout << std::endl;
}