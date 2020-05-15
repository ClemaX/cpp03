#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

# include <string>
# include <iostream>
# include <array>
# include <random>

class ScavTrap
{
public:
	class Attack
	{
	public:
		std::string name;
		int damage;
		int cost = 0;

		Attack(std::string name, int damage);
		Attack(std::string name, int damage, int energyCost);
	};

	int level = 1;
	int hitPoints = 100;
	int maxHitPoints = 100;
	int energyPoints = 50;
	int maxEnergyPoints = 50;
	int armorReduction = 3;

	Attack melee = Attack("melee", 20);
	Attack ranged = Attack("ranged", 15);

	std::array<std::string, 5> challenges = {
		"Invent a challenge!",
		"Think about inventing a challenge!",
		"Think about thinking about inventing a challenge!",
		"Think about thinking about thinking about inventing a challenge!",
		"Do not think about inventing a challenge"
	};

	std::string name;

	ScavTrap(std::string name);
	~ScavTrap();

	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(void);
};

#endif