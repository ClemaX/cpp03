#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

# include <string>
# include <iostream>
# include <array>
# include <random>

class Attack
{
public:
	std::string name;
	int damage;
	int cost = 0;

	Attack(std::string name, int damage);
	Attack(std::string name, int damage, int energyCost);
};

class FragTrap
{
public:
	int level = 1;
	int hitPoints = 100;
	int maxHitPoints = 100;
	int energyPoints = 100;
	int maxEnergyPoints = 100;
	int armorReduction = 5;

	Attack melee = Attack("melee", 30);
	Attack ranged = Attack("ranged", 30);
	std::array<Attack, 5> specialAttacks = {
		Attack("a pan", 5, 25),
		Attack("his feet", 10, 25),
		Attack("a magic wand", 10, 25),
		Attack("his bare hands", 5, 25),
		Attack("nuclear power", 1000, 25)
	};

	std::string name;

	FragTrap(std::string name);
	~FragTrap();

	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const &target);
};

#endif