#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap a = FragTrap("Alpha");
	FragTrap b = FragTrap("Beta");

	ScavTrap c = ScavTrap("Charlie");
	ScavTrap d = ScavTrap("Delta");

	a.meleeAttack(b.name);
	b.rangedAttack(a.name);

	c.meleeAttack(d.name);
	d.rangedAttack(c.name);

	for (int i = 0; i < a.specialAttacks.size(); i++)
		a.vaulthunter_dot_exe(b.name);

	for (int i = 0; i < c.challenges.size(); i++)
		c.challengeNewcomer();

	return 0;
}
