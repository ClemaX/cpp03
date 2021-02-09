#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap a = FragTrap("Alpha");
	FragTrap b = FragTrap("Beta");

	ScavTrap c = ScavTrap("Charlie");
	ScavTrap d = ScavTrap("Delta");

	a.meleeAttack(b);
	b.rangedAttack(a);

	c.meleeAttack(d);
	d.rangedAttack(c);

	for (std::size_t i = 0; i < 5; i++)
		a.vaulthunter_dot_exe(b);

	for (std::size_t i = 0; i < 5; i++)
		c.challengeNewcomer();

	return 0;
}
