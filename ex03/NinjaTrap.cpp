#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string const& name)
	: ClapTrap(name, 60, 120, 0, 60, 5)
{
	std::cout << "NNJ4-TP ";
	std::cout << "Constructing " << name << '!';
	std::cout << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NNJ4-TP ";
	std::cout << "Destructing " << name << '!';
	std::cout << std::endl;
}

void NinjaTrap::performAttack(ClapTrap& target, Attack const& attack)
{
	std::cout << "NNJ4-TP ";
	std::cout << name << " attacks " << target.name << ' ';
	std::cout << "with " << attack.name << ", ";
	std::cout << "causing " << attack.damage << " points of damage!";
	std::cout << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap const &frag)
{
	std::cout << "NNJ4-TP ";
	std::cout << frag.name << ": \"What are you?\"";
	std::cout << std::endl;

	std::cout << "NNJ4-TP ";
	std::cout << name << ": \"We're ninjas.\"" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap const &scav)
{
	std::cout << "NNJ4-TP ";
	std::cout << scav.name << ": \"What are you?\"";
	std::cout << std::endl;

	std::cout << "NNJ4-TP ";
	std::cout << name << ": \"We're mutants!\"" << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap const &ninja)
{
	std::cout << "NNJ4-TP ";
	std::cout << ninja.name << ": \"What are you?\"";
	std::cout << std::endl;

	std::cout << "NNJ4-TP ";
	std::cout << name << ": \"Technically, we're turtles.\"" << std::endl;
}
