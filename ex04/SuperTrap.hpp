#pragma once

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
    using NinjaTrap::melee;
    using FragTrap::ranged;

    SuperTrap(std::string name);
    ~SuperTrap();

    using FragTrap::rangedAttack;
    using NinjaTrap::meleeAttack;
};
