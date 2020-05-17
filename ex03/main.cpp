#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main(void)
{
	FragTrap a = FragTrap("Alpha");
	FragTrap b = FragTrap("Beta");

	ScavTrap c = ScavTrap("Charlie");
	ScavTrap d = ScavTrap("Delta");

	NinjaTrap e = NinjaTrap("Leonardo");
	NinjaTrap f = NinjaTrap("Raphael");
	NinjaTrap g = NinjaTrap("Donatello");

	a.meleeAttack(b.name);
	b.rangedAttack(a.name);

	c.meleeAttack(d.name);
	d.rangedAttack(c.name);

	for (std::size_t i = 0; i < a.specialAttacks.size(); i++)
		a.vaulthunter_dot_exe(b.name);

	for (std::size_t i = 0; i < c.challenges.size(); i++)
		c.challengeNewcomer();

	e.ninjaShoebox(a);
	f.ninjaShoebox(c);
	g.ninjaShoebox(e);

	return 0;
}
