#include "ScavTrap.hpp"

const ScavTrap::Attack	ScavTrap::melee = ScavTrap::Attack("melee", 20);
const ScavTrap::Attack	ScavTrap::ranged = ScavTrap::Attack("ranged", 15);

const size_t		ScavTrap::challengesCount = 5;
const std::string	ScavTrap::challenges[ScavTrap::challengesCount] =
{
	"Invent a challenge!",
	"Think about inventing a challenge!",
	"Think about thinking about inventing a challenge!",
	"Think about thinking about thinking about inventing a challenge!",
	"Do not think about inventing a challenge"
};

ScavTrap::Attack::Attack(std::string const& name, unsigned int damage)
	: name(name), damage(damage), cost(0)
{
}

ScavTrap::Attack::Attack(std::string const& name, unsigned int damage,
	unsigned int cost)
	: name(name), damage(damage), cost(cost)
{
}

ScavTrap::ScavTrap(std::string const& name)
	:	maxHitPoints(100),
		maxEnergyPoints(50),
		armorReduction(3),
		hitPoints(maxHitPoints),
		energyPoints(maxEnergyPoints),
		name(name)
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

void ScavTrap::performAttack(ScavTrap& target, ScavTrap::Attack const &attack)
{
	std::cout << "SC4V-TP " << name;
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

void ScavTrap::rangedAttack(ScavTrap& target)
{
	performAttack(target, ranged);
}

void ScavTrap::meleeAttack(ScavTrap& target)
{
	performAttack(target, melee);
}

void ScavTrap::takeDamage(unsigned int amount)
{
	amount -= armorReduction;
	if (amount > hitPoints)
		amount = hitPoints;

	std::cout << "SC4V-TP ";
	std::cout << name;
	std::cout << " takes " << amount << " points of damage!";
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
	std::cout << challenges[rand() % challengesCount] << std::endl;
}
