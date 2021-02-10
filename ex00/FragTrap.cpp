#include "FragTrap.hpp"

const FragTrap::Attack FragTrap::melee = Attack("melee", 30);
const FragTrap::Attack FragTrap::ranged = Attack("ranged", 30);

const size_t FragTrap::specialAttacksCount = 5;
const FragTrap::Attack FragTrap::specialAttacks[FragTrap::specialAttacksCount] =
{
	FragTrap::Attack("a pan", 5, 25),
	FragTrap::Attack("his feet", 10, 25),
	FragTrap::Attack("a magic wand", 10, 25),
	FragTrap::Attack("his bare hands", 5, 25),
	FragTrap::Attack("nuclear power", 1000, 25)
};

FragTrap::Attack::Attack(std::string name, unsigned int damage)
	: name(name), damage(damage), cost(0)
{
}

FragTrap::Attack::Attack(std::string name, unsigned int damage, unsigned int cost)
	: name(name), damage(damage), cost(cost)
{
}

FragTrap::FragTrap(std::string const& name)
	:	level(1),
		maxHitPoints(100),
		maxEnergyPoints(100),
		armorReduction(5),
		hitPoints(maxHitPoints),
		energyPoints(maxEnergyPoints),
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

void FragTrap::performAttack(FragTrap& target, FragTrap::Attack const& attack)
{
	std::cout << "FR4G-TP " << name;
	if (attack.cost > energyPoints)
	{
		std::cout << "does not have enough energy to use ";
		std::cout << attack.name << "!";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "attacks " << target.name << ' ';
		std::cout << "with " << attack.name << ", ";
		std::cout << "causing " << attack.damage << " points of damage!";
		std::cout << std::endl;

		energyPoints -= attack.cost;
		target.takeDamage(attack.damage);
	}
}

void FragTrap::rangedAttack(FragTrap& target)
{
	performAttack(target, ranged);
}

void FragTrap::meleeAttack(FragTrap& target)
{
	performAttack(target, melee);
}

void FragTrap::takeDamage(unsigned int amount)
{
	amount -= armorReduction;
	if (amount > hitPoints)
		amount = hitPoints;

	std::cout << "FR4G-TP ";
	std::cout << name;
	std::cout << " takes " << amount << " points of damage!";
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

void FragTrap::beEnergized(unsigned int amount)
{
	if (energyPoints + amount > maxEnergyPoints)
		amount = maxEnergyPoints - energyPoints;

	std::cout << "FR4G-TP ";
	std::cout << name << " earns " << amount << " energy points!";
	std::cout << std::endl;

	energyPoints += amount;
}

void FragTrap::vaulthunter_dot_exe(FragTrap& target)
{
	const FragTrap::Attack &attack = specialAttacks[rand() % specialAttacksCount];

	performAttack(target, attack);
}
