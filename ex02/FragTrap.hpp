#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
protected:
	static const size_t	specialAttacksCount;
	static const Attack specialAttacks[];

public:
	FragTrap(std::string name);
	~FragTrap();

	void performAttack(ClapTrap& target, FragTrap::Attack const &attack);
	void vaulthunter_dot_exe(ClapTrap& target);
};
