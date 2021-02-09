#include "ScavTrap.hpp"

const ScavTrap::Attack ScavTrap::melee = Attack("melee", 20);
const ScavTrap::Attack ScavTrap::ranged = Attack("ranged", 15);

const size_t	ScavTrap::challengesCount = 5;
const std::string ScavTrap::challenges[ScavTrap::challengesCount] =
{
	"Invent a challenge!",
	"Think about inventing a challenge!",
	"Think about thinking about inventing a challenge!",
	"Think about thinking about thinking about inventing a challenge!",
	"Do not think about inventing a challenge"
};

ScavTrap::ScavTrap(std::string name)
	:	ClapTrap(name, 50, 50, 3)
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

void ScavTrap::challengeNewcomer(void) const
{
	std::cout << "SC4V-TP ";
	std::cout << name << " challenges a newcomer: ";
	std::cout << challenges[rand() % challengesCount] << std::endl;
}

void ScavTrap::performAttack(std::string &source, std::string const &target,
	ClapTrap::Attack const &attack) const
{
	std::cout << "SC4V-TP ";
	std::cout << source << " attacks " << target << ' ';
	std::cout << "with " << attack.name << ", ";
	std::cout << "causing " << attack.damage << " points of damage!";
	std::cout << std::endl;
}
