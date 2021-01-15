#pragma once

#include <string>
#include <iostream>
#include <array>
#include <random>

class FragTrap
{
public:
	class Attack
	{
	public:
		std::string name;
		unsigned int damage;
		unsigned int cost;

		Attack(std::string name, unsigned int damage);
		Attack(std::string name, unsigned int damage, unsigned int energyCost);
	};

	unsigned int level;
	unsigned int hitPoints;
	unsigned int maxHitPoints;
	unsigned int energyPoints;
	unsigned int maxEnergyPoints;
	unsigned int armorReduction;
	static const Attack melee;
	static const Attack ranged;
	static const size_t	specialAttacksCount;
	static const Attack specialAttacks[];

	std::string name;

	FragTrap(std::string name);
	~FragTrap();

	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const &target);
};
