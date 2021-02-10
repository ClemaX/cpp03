#include "FragTrap.hpp"

const size_t			FragTrap::specialAttacksCount = 5;

const FragTrap::Attack	FragTrap::specialAttacks[FragTrap::specialAttacksCount] =
{
	Attack("a pan", 5, 25),
	Attack("his feet", 10, 25),
	Attack("a magic wand", 10, 25),
	Attack("his bare hands", 5, 25),
	Attack("nuclear power", 1000, 25)
};

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

void FragTrap::performAttack(ClapTrap& target, Attack const& attack)
{
	std::cout << "FR4G-TP " << name;
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

void FragTrap::vaulthunter_dot_exe(ClapTrap& target)
{
	performAttack(target, specialAttacks[rand() % specialAttacksCount]);
}
