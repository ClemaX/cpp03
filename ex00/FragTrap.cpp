#include "FragTrap.hpp"

FragTrap::Attack::Attack(std::string name, unsigned int damage)
	: name(name), damage(damage)
{
}

FragTrap::Attack::Attack(std::string name, unsigned int damage, unsigned int cost)
	: name(name), damage(damage), cost(cost)
{
}

FragTrap::FragTrap(std::string name)
	: name(name)
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

void performAttack(std::string &source, std::string const &target, FragTrap::Attack const &attack)
{
	std::cout << "FR4G-TP ";
	std::cout << source << " attacks " << target << ' ';
	std::cout << "with " << attack.name << ", ";
	std::cout << "causing " << attack.damage << " points of damage!";
	std::cout << std::endl;
}

void FragTrap::rangedAttack(std::string const &target)
{
	performAttack(name, target, ranged);
}

void FragTrap::meleeAttack(std::string const &target)
{
	performAttack(name, target, melee);
}

void FragTrap::takeDamage(unsigned int amount)
{
	amount -= armorReduction;
	if (amount > hitPoints)
		amount = hitPoints;
	std::cout << "FR4G-TP ";
	std::cout << '<' << name << "> ";
	std::cout << "takes " << amount << " points of damage!";
	std::cout << std::endl;
	hitPoints -= amount;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (hitPoints + amount > maxHitPoints)
		amount = maxHitPoints - hitPoints;
	std::cout << "FR4G-TP ";
	std::cout << name << " heals " << amount << " hit points!";
	std::cout << std::endl;
	hitPoints += amount;
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
