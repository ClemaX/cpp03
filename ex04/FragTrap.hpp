#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	static const size_t	specialAttacksCount;
	static const Attack	specialAttacks[];

	void performAttack(ClapTrap& target, ClapTrap::Attack const& attack) const;

public:
	FragTrap(std::string name);
	~FragTrap();

	void vaulthunter_dot_exe(ClapTrap const& target);
};
