#pragma once

#include <string>
#include <iostream>
#include <array>
#include <random>

class ScavTrap
{
protected:
	unsigned int	level;

	unsigned int	maxHitPoints;
	unsigned int	maxEnergyPoints;
	unsigned int	armorReduction;

	unsigned int	hitPoints;
	unsigned int	energyPoints;

	struct Attack
	{
		const std::string name;
		const unsigned int damage;
		const unsigned int cost;

		Attack(std::string name, unsigned int damage);
		Attack(std::string name, unsigned int damage, unsigned int energyCost);
	};

	static const Attack melee;
	static const Attack ranged;

	static const size_t			challengesCount;
	static const std::string	challenges[];

	void	performAttack(ScavTrap const& target,
		ScavTrap::Attack const& attack);

public:
	const std::string	name;

	ScavTrap(std::string const& name);
	~ScavTrap();

	void rangedAttack(ScavTrap const& target);
	void meleeAttack(ScavTrap const& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(void);
};
