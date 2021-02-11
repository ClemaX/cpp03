#pragma once

#include <string>
#include <iostream>
#include <array>
#include <random>

class ClapTrap
{
protected:
	struct Attack
	{
	public:
		const std::string	name;
		const unsigned int	damage;
		const unsigned int	cost;

		Attack(std::string const& name, unsigned int damage);
		Attack(std::string const& name, unsigned int damage, unsigned int energyCost);
	};

	const unsigned int	maxHitPoints;
	const unsigned int	maxEnergyPoints;
	const unsigned int	armorReduction;

	const Attack	melee;
	const Attack	ranged;

	unsigned int	level;
	unsigned int	hitPoints;
	unsigned int	energyPoints;


	virtual void	performAttack(ClapTrap& target, Attack const& attack);

	ClapTrap(
		std::string const& name,
		unsigned int maxHitPoints,
		unsigned int maxEnergyPoints,
		unsigned int armorReduction,
		unsigned int meleeDamage,
		unsigned int rangedDamage
	);

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
