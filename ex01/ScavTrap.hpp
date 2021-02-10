#pragma once

#include <string>
#include <iostream>
#include <array>
#include <random>

class ScavTrap
{
protected:
	unsigned int	maxHitPoints;
	unsigned int	maxEnergyPoints;
	unsigned int	armorReduction;

	unsigned int	level;
	unsigned int	hitPoints;
	unsigned int	energyPoints;

	struct Attack
	{
		const std::string name;
		const unsigned int damage;
		const unsigned int cost;

		Attack(std::string const& name, unsigned int damage);
		Attack(std::string const& name, unsigned int damage, unsigned int energyCost);
	};

	static const Attack melee;
	static const Attack ranged;

	static const size_t			challengesCount;
	static const std::string	challenges[];

	void	performAttack(ScavTrap& target, ScavTrap::Attack const& attack);

public:
	const std::string	name;

	ScavTrap(std::string const& name);
	~ScavTrap();

	void rangedAttack(ScavTrap& target);
	void meleeAttack(ScavTrap& target);

	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void challengeNewcomer(void);
};
