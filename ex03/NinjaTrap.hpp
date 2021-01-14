#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(std::string name);
	~NinjaTrap();

	void performAttack(std::string &source, std::string const &target, ClapTrap::Attack const &attack);
	void ninjaShoebox(FragTrap const &frag);
	void ninjaShoebox(ScavTrap const &scav);
	void ninjaShoebox(NinjaTrap const &ninja);
};
