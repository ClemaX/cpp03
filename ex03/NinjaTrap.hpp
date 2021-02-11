#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
protected:
	static const Attack	melee;
	static const Attack	ranged;

	void performAttack(ClapTrap& target, Attack const& attack);

public:
	NinjaTrap(std::string const& name);
	~NinjaTrap();

	void ninjaShoebox(FragTrap const& frag);
	void ninjaShoebox(ScavTrap const& scav);
	void ninjaShoebox(NinjaTrap const& ninja);
};
