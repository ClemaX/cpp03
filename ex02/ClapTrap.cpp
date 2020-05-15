#include "ClapTrap.hpp"

ClapTrap::Attack::Attack(std::string name, int damage)
	: name(name), damage(damage)
{
}

ClapTrap::Attack::Attack(std::string name, int damage, int cost)
	: name(name), damage(damage), cost(cost)
{
}

ClapTrap::ClapTrap(std::string name)
	: name(name)
{
	std::cout << "CL4P-TP ";
	std::cout << "Constructing " << name << '!';
	std::cout << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "CL4P-TP ";
	std::cout << "Destructing " << name << '!';
	std::cout << std::endl;
}

void ClapTrap::performAttack(std::string &source, std::string const &target, ClapTrap::Attack const &attack)
{
	std::cout << "CL4P-TP ";
	std::cout << source << " attacks " << target << ' ';
	std::cout << "with " << attack.name << ", ";
	std::cout << "causing " << attack.damage << " points of damage!";
	std::cout << std::endl;
}

void ClapTrap::rangedAttack(std::string const &target)
{
	performAttack(name, target, ranged);
}

void ClapTrap::meleeAttack(std::string const &target)
{
	performAttack(name, target, melee);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	amount -= armorReduction;
	if (amount > hitPoints)
		amount = hitPoints;
	std::cout << "CL4P-TP ";
	std::cout << '<' << name << "> ";
	std::cout << "takes " << amount << " points of damage!";
	std::cout << std::endl;
	hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints + amount > maxHitPoints)
		amount = maxHitPoints - hitPoints;
	std::cout << "CL4P-TP ";
	std::cout << name << " heals " << amount << " hit points!";
	std::cout << std::endl;
	hitPoints += amount;
}
