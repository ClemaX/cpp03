#include "ClapTrap.hpp"

ClapTrap::Attack::Attack(std::string const& name, unsigned int damage)
	:	name(name),
		damage(damage),
		cost(0)
{
}

ClapTrap::Attack::Attack(
	std::string const& name,
	unsigned int damage,
	unsigned int cost
)	:	name(name),
		damage(damage),
		cost(cost)
{
}

ClapTrap::ClapTrap(std::string const& name)
	:	maxHitPoints(100),
		maxEnergyPoints(100),
		armorReduction(5),
		melee("melee", 30),
		ranged("ranged", 30),
		level(1),
		hitPoints(maxHitPoints),
		energyPoints(maxEnergyPoints),
		name(name)
{
	std::cout << "CL4P-TP ";
	std::cout << "Constructing " << name;
	std::cout << " with " << hitPoints << "HP, ";
	std::cout << energyPoints << "EP, ";
	std::cout << armorReduction << "AR!";
	std::cout << std::endl;
}

ClapTrap::ClapTrap(
	std::string const& name,
	unsigned int maxHitPoints,
	unsigned int maxEnergyPoints,
	unsigned int armorReduction,
	unsigned int meleeDamage,
	unsigned int rangedDamage
)	:	maxHitPoints(maxHitPoints),
		maxEnergyPoints(maxEnergyPoints),
		armorReduction(armorReduction),
		melee("melee", meleeDamage),
		ranged("ranged", rangedDamage),
		level(1),
		hitPoints(maxHitPoints),
		energyPoints(maxEnergyPoints),
		name(name)
{
	std::cout << "CL4P-TP ";
	std::cout << "Constructing " << name;
	std::cout << " with " << hitPoints << "HP, ";
	std::cout << energyPoints << "EP, ";
	std::cout << armorReduction << "AR!";
	std::cout << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "CL4P-TP ";
	std::cout << "Destructing " << name << '!';
	std::cout << std::endl;
}

void ClapTrap::performAttack(ClapTrap& target, ClapTrap::Attack const& attack)
{
	std::cout << "CL4P-TP " << name;
	if (attack.cost > energyPoints)
	{
		std::cout << " does not have enough energy to use " << attack.name << "!";
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

void ClapTrap::rangedAttack(ClapTrap& target)
{
	performAttack(target, ranged);
}

void ClapTrap::meleeAttack(ClapTrap& target)
{
	performAttack(target, melee);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	amount -= armorReduction;
	if (amount > hitPoints)
		amount = hitPoints;

	std::cout << "CL4P-TP " << name;
	std::cout << " takes " << amount << " points of damage!";
	std::cout << std::endl;

	hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints + amount > maxHitPoints)
		amount = maxHitPoints - hitPoints;

	std::cout << "CL4P-TP " << name;
	std::cout << " heals " << amount << " hit points!";
	std::cout << std::endl;

	hitPoints += amount;
}
