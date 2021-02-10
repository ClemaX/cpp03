#pragma once

#include <string>
#include <iostream>
#include <array>
#include <random>

class ClapTrap
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
	public:
		const std::string	name;
		const unsigned int	damage;
		const unsigned int	cost;

		Attack(std::string const& name, unsigned int damage);
		Attack(std::string const& name, unsigned int damage, unsigned int energyCost);
	};

	static const Attack	melee;
	static const Attack	ranged;

	void	performAttack(ClapTrap& target, Attack const& attack);

	ClapTrap(std::string const& name, unsigned int maxHitPoints,
		unsigned int maxEnergyPoints, unsigned int armorReduction);

public:
	const std::string	name;

	ClapTrap(std::string const& name);
	~ClapTrap();

	void	rangedAttack(ClapTrap& target);
	void	meleeAttack(ClapTrap& target);

	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	beEnergized(unsigned int amount);
};
