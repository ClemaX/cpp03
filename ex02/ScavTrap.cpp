#include "ScavTrap.hpp"

const ScavTrap::Attack	ScavTrap::melee = Attack("melee", 20);
const ScavTrap::Attack	ScavTrap::ranged = Attack("ranged", 15);

const size_t			ScavTrap::challengesCount = 5;
const std::string		ScavTrap::challenges[ScavTrap::challengesCount] =
{
	"Invent a challenge!",
	"Think about inventing a challenge!",
	"Think about thinking about inventing a challenge!",
	"Think about thinking about thinking about inventing a challenge!",
	"Do not think about inventing a challenge"
};

void ScavTrap::performAttack(ClapTrap& target, Attack const& attack)
{
	std::cout << "SC4V-TP ";
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

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name, 100, 50, 3)
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

void ScavTrap::challengeNewcomer(void)
{
	std::cout << "SC4V-TP ";
	std::cout << name << " challenges a newcomer: ";
	std::cout << challenges[rand() % challengesCount] << std::endl;
}
