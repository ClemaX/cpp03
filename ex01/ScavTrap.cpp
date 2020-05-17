#include "ScavTrap.hpp"

ScavTrap::Attack::Attack(std::string name, unsigned int damage)
	: name(name), damage(damage)
{
}

ScavTrap::Attack::Attack(std::string name, unsigned int damage, unsigned int cost)
	: name(name), damage(damage), cost(cost)
{
}

ScavTrap::ScavTrap(std::string name)
	: name(name)
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

void performAttack(std::string &source, std::string const &target, ScavTrap::Attack const &attack)
{
	std::cout << "SC4V-TP ";
	std::cout << source << " attacks " << target << ' ';
	std::cout << "with " << attack.name << ", ";
	std::cout << "causing " << attack.damage << " points of damage!";
	std::cout << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target)
{
	performAttack(name, target, ranged);
}

void ScavTrap::meleeAttack(std::string const &target)
{
	performAttack(name, target, melee);
}

void ScavTrap::takeDamage(unsigned int amount)
{
	amount -= armorReduction;
	if (amount > hitPoints)
		amount = hitPoints;
	std::cout << "SC4V-TP ";
	std::cout << '<' << name << "> ";
	std::cout << "takes " << amount << " points of damage!";
	std::cout << std::endl;
	hitPoints -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (hitPoints + amount > maxHitPoints)
		amount = maxHitPoints - hitPoints;
	std::cout << "SC4V-TP ";
	std::cout << name << " heals " << amount << " hit points!";
	std::cout << std::endl;
	hitPoints += amount;
}

void ScavTrap::challengeNewcomer(void)
{
	std::cout << "SC4V-TP ";
	std::cout << name << " challenges a newcomer: ";
	std::cout << challenges[rand() % challenges.size()] << std::endl;
}
