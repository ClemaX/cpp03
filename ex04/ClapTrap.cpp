#include "ClapTrap.hpp"

const ClapTrap::Attack ClapTrap::melee = Attack("melee", 30);
const ClapTrap::Attack ClapTrap::ranged = Attack("ranged", 30);

ClapTrap::Attack::Attack(std::string name, unsigned int damage)
	: name(name), damage(damage), cost(0)
{
}

ClapTrap::Attack::Attack(std::string name, unsigned int damage, unsigned int cost)
	: name(name), damage(damage), cost(cost)
{
}

ClapTrap::ClapTrap(std::string name)
	:	level(1),
		maxHitPoints(100),
		maxEnergyPoints(100),
		armorReduction(5),
		hitPoints(maxHitPoints),
		energyPoints(maxEnergyPoints),
		name(name)
{
	std::cout << "CL4P-TP ";
	std::cout << "Constructing " << name << '!';
	std::cout << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int maxHitPoints,
	unsigned int maxEnergyPoints, unsigned int armorReduction)
	:	level(1),
		maxHitPoints(maxHitPoints),
		maxEnergyPoints(maxEnergyPoints),
		armorReduction(armorReduction),
		hitPoints(maxHitPoints),
		energyPoints(maxEnergyPoints),
		name(name)
{

}

ClapTrap::~ClapTrap()
{
	std::cout << "CL4P-TP ";
	std::cout << "Destructing " << name << '!';
	std::cout << std::endl;
}

void ClapTrap::performAttack(ClapTrap const &target, ClapTrap::Attack const &attack) const
{
	std::cout << "CL4P-TP ";
	std::cout << name << " attacks " << target.name << ' ';
	std::cout << "with " << attack.name << ", ";
	std::cout << "causing " << attack.damage << " points of damage!";
	std::cout << std::endl;
}

void ClapTrap::rangedAttack(ClapTrap const& target) const
{
	performAttack(target, ranged);
}

void ClapTrap::meleeAttack(ClapTrap const& target) const
{
	performAttack(target, melee);
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
