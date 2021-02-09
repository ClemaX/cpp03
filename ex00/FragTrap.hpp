#pragma once

#include <string>
#include <iostream>
#include <array>
#include <random>

class FragTrap
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
		const std::string	name;
		const unsigned int	damage;
		const unsigned int	cost;

		Attack(std::string name, unsigned int damage);
		Attack(std::string name, unsigned int damage, unsigned int energyCost);
	};

	static const Attack	melee;
	static const Attack	ranged;
	static const size_t	specialAttacksCount;
	static const Attack	specialAttacks[];

	void	performAttack(FragTrap const& target,
		FragTrap::Attack const& attack);

public:
	const std::string	name;

	FragTrap(std::string const& name);
	~FragTrap();

	void	rangedAttack(FragTrap const& target);
	void	meleeAttack(FragTrap const& target);

	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	beEnergized(unsigned int amount);

	void	vaulthunter_dot_exe(FragTrap const& target);
};
