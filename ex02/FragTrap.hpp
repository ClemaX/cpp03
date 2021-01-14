#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	std::array<Attack, 5> specialAttacks = {
		Attack("a pan", 5, 25),
		Attack("his feet", 10, 25),
		Attack("a magic wand", 10, 25),
		Attack("his bare hands", 5, 25),
		Attack("nuclear power", 1000, 25)
	};

	FragTrap(std::string name);
	~FragTrap();

	void performAttack(std::string &source, std::string const &target, ClapTrap::Attack const &attack);
	void vaulthunter_dot_exe(std::string const &target);
};
