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

	a.meleeAttack(b);
	b.rangedAttack(a);

	c.meleeAttack(d);
	d.rangedAttack(c);

	for (std::size_t i = 0; i < 5; i++)
		a.vaulthunter_dot_exe(b);

	for (std::size_t i = 0; i < 5; i++)
		c.challengeNewcomer();

	e.ninjaShoebox(a);
	f.ninjaShoebox(c);
	g.ninjaShoebox(e);

	return 0;
}
