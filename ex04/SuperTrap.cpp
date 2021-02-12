#include "SuperTrap.hpp"

void SuperTrap::performAttack(ClapTrap& target, Attack const& attack)
{
	std::cout << "SUPR-TP " << name;
	if (attack.cost > energyPoints)
	{
		std::cout << " does not have enough energy to use ";
		std::cout << attack.name << "!";
		std::cout << std::endl;
	}
	else
	{
		std::cout << " attacks " << target.name << ' ';
		std::cout << "with " << attack.name << ", ";
		std::cout << "causing " << attack.damage << " points of damage!";
		std::cout << std::endl;

		energyPoints -= attack.cost;
		target.takeDamage(attack.damage);
	}
}

SuperTrap::SuperTrap(std::string name)
    :	ClapTrap(name, 100, 120, 5, 30, 5), // TODO
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
