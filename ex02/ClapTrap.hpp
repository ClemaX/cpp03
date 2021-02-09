#pragma once

#include <string>
#include <iostream>
#include <array>
#include <random>

class ClapTrap
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
	public:
		const std::string	name;
		const unsigned int	damage;
		const unsigned int	cost;

		Attack(std::string name, unsigned int damage);
		Attack(std::string name, unsigned int damage, unsigned int energyCost);
	};

	static const Attack melee;
	static const Attack ranged;

	void performAttack(ClapTrap& target, ClapTrap::Attack const& attack);

public:
	const std::string	name;

	ClapTrap(std::string name);
	~ClapTrap();

	void rangedAttack(ClapTrap& target);
	void meleeAttack(ClapTrap& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
