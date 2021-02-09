#include "FragTrap.hpp"

const size_t	FragTrap::specialAttacksCount = 5;
const FragTrap::Attack FragTrap::specialAttacks[FragTrap::specialAttacksCount] =
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

void FragTrap::performAttack(ClapTrap& target, ClapTrap::Attack const& attack) const
{
	std::cout << "FR4G-TP ";
	std::cout << name << " attacks " << target.name << ' ';
	std::cout << "with " << attack.name << ", ";
	std::cout << "causing " << attack.damage << " points of damage!";
	target.takeDamage(attack.damage);
	std::cout << std::endl;
}

void FragTrap::vaulthunter_dot_exe(ClapTrap const& target)
{
	Attack const&	attack = specialAttacks[rand() % specialAttacksCount];

	if (attack.cost > energyPoints)
	{
		std::cout << "FR4G-TP ";
		std::cout << name << " does not have enough energy to use " << attack.name << "!";
		std::cout << std::endl;
	}
	else
	{
		energyPoints -= attack.cost;
		performAttack(target, attack);
	}
}
