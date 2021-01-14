#pragma once

#include <string>
#include <iostream>
#include <array>
#include <random>

class ClapTrap
{
public:
	class Attack
	{
	public:
		std::string name;
		unsigned int damage;
		unsigned int cost = 0;

		Attack(std::string name, unsigned int damage);
		Attack(std::string name, unsigned int damage, unsigned int energyCost);
	};

	unsigned int level = 1;
	unsigned int hitPoints = 100;
	unsigned int maxHitPoints = 100;
	unsigned int energyPoints = 100;
	unsigned int maxEnergyPoints = 100;
	unsigned int armorReduction = 5;

	Attack melee = Attack("melee", 30);
	Attack ranged = Attack("ranged", 30);

	std::string name;

	ClapTrap(std::string name);
	~ClapTrap();

	void performAttack(std::string &source, std::string const &target, ClapTrap::Attack const &attack);
	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
