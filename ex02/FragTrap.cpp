#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "FR4G-TP ";
	std::cout << "Constructing " << name << '!';
	std::cout << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP ";
	std::cout << "Destructing " << name << '!';
	std::cout << std::endl;
}

void FragTrap::performAttack(std::string &source, std::string const &target, ClapTrap::Attack const &attack)
{	
	std::cout << "FR4G-TP ";
	std::cout << source << " attacks " << target << ' ';
	std::cout << "with " << attack.name << ", ";
	std::cout << "causing " << attack.damage << " points of damage!";
	std::cout << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	Attack &attack = specialAttacks[rand() % specialAttacks.size()];
	if (attack.cost > energyPoints)
	{
		std::cout << "FR4G-TP ";
		std::cout << name << " does not have enough energy to use " << attack.name << "!";
		std::cout << std::endl;
	}
	else
	{
		energyPoints -= attack.cost;
		performAttack(name, target, attack);
	}
}
