#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
protected:
	static const Attack	melee;
	static const Attack	ranged;

	static const size_t			challengesCount;
	static const std::string	challenges[];

public:
	ScavTrap(std::string name);
	~ScavTrap();

	void performAttack(std::string &source, std::string const &target,
		ClapTrap::Attack const &attack) const;
	void challengeNewcomer(void) const;
};
