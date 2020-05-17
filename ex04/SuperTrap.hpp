#ifndef SUPER_TRAP_H
# define SUPER_TRAP_H

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
    using FragTrap::hitPoints;
    using FragTrap::maxHitPoints;
    using NinjaTrap::energyPoints;
    using NinjaTrap::maxEnergyPoints;
    using FragTrap::armorReduction;

    using NinjaTrap::melee;
    using FragTrap::ranged;

    unsigned int level = 1;
    std::string name;

    SuperTrap(std::string name);
    ~SuperTrap();

    using FragTrap::rangedAttack;
    using NinjaTrap::meleeAttack;
};

#endif
