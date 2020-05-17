#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	int energyPoints = 50;
	int maxEnergyPoints = 50;
	int armorReduction = 3;

	Attack melee = Attack("melee", 20);
	Attack ranged = Attack("ranged", 15);

	std::array<std::string, 5> challenges = {
		"Invent a challenge!",
		"Think about inventing a challenge!",
		"Think about thinking about inventing a challenge!",
		"Think about thinking about thinking about inventing a challenge!",
		"Do not think about inventing a challenge"
	};

	ScavTrap(std::string name);
	~ScavTrap();

	void performAttack(std::string &source, std::string const &target, ClapTrap::Attack const &attack);
	void challengeNewcomer(void);
};

#endif