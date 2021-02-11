#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	unsigned int	maxEnergyPoints;
	unsigned int	armorReduction;

	static const Attack melee;
	static const Attack ranged;

	static const size_t			challengesCount;
	static const std::string	challenges[];

	void performAttack(ClapTrap& target, Attack const &attack);

public:
	ScavTrap(std::string name);
	~ScavTrap();

	void challengeNewcomer(void);
};
