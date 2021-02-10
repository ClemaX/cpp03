#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
protected:
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
