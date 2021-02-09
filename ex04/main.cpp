#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void)
{
	FragTrap a = FragTrap("Alpha");
	FragTrap b = FragTrap("Beta");

	ScavTrap c = ScavTrap("Charlie");
	ScavTrap d = ScavTrap("Delta");

	NinjaTrap e = NinjaTrap("Leonardo");
	NinjaTrap f = NinjaTrap("Raphael");
	NinjaTrap g = NinjaTrap("Donatello");

	SuperTrap h = SuperTrap("Samuel");

	std::cout << std::endl;

	a.meleeAttack(b.name);
	b.rangedAttack(a.name);

	c.meleeAttack(d.name);
	d.rangedAttack(c.name);

	std::cout << std::endl;

	for (std::size_t i = 0; i < 5; i++)
		a.vaulthunter_dot_exe(b.name);

	for (std::size_t i = 0; i < 5; i++)
		c.challengeNewcomer();

	e.meleeAttack(f);

	e.ninjaShoebox(a);
	f.ninjaShoebox(c);
	g.ninjaShoebox(e);

	h.meleeAttack(e.name);
	h.rangedAttack(f.name);

	for (std::size_t i = 0; i < 5; i++)
		h.vaulthunter_dot_exe(g.name);

	h.ninjaShoebox(a);
	h.ninjaShoebox(c);
	h.ninjaShoebox(e);

	return 0;
}
