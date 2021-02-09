#pragma once

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
protected:
	unsigned int level;

	using FragTrap::hitPoints;
	using FragTrap::maxHitPoints;
	using NinjaTrap::energyPoints;
	using NinjaTrap::maxEnergyPoints;
	using FragTrap::armorReduction;

	using NinjaTrap::melee;
	using FragTrap::ranged;

public:

	SuperTrap(std::string name);
	~SuperTrap();

	using FragTrap::rangedAttack;
	using NinjaTrap::meleeAttack;
};
