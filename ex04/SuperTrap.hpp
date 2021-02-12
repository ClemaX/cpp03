#pragma once

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
protected:
	void performAttack(ClapTrap& target, Attack const& attack);

public:
    SuperTrap(std::string name);
    ~SuperTrap();
};
