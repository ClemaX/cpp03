#include "FragTrap.hpp"

const FragTrap::Attack FragTrap::melee = Attack("melee", 30);

const FragTrap::Attack FragTrap::ranged = Attack("ranged", 30);

const size_t FragTrap::specialAttacksCount = 5;

const FragTrap::Attack FragTrap::specialAttacks[FragTrap::specialAttacksCount] =
{
	Attack("a pan", 5, 25),
	Attack("his feet", 10, 25),
	Attack("a magic wand", 10, 25),
	Attack("his bare hands", 5, 25),
	Attack("nuclear power", 1000, 25)
};

FragTrap::Attack::Attack(std::string name, unsigned int damage)
	: name(name), damage(damage), cost(0)
{
}

FragTrap::Attack::Attack(std::string name, unsigned int damage, unsigned int cost)
	: name(name), damage(damage), cost(cost)
{
}

FragTrap::FragTrap(std::string name)
	:	//level(1),
		hitPoints(100),
		maxHitPoints(100),
		// maxEnergyPoints(100),
		armorReduction(5),
		name(name)
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
	const Attack &attack = specialAttacks[rand() % specialAttacksCount];

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
