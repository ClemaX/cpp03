#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	srand(time(NULL));

	FragTrap a = FragTrap("Alpha");
	FragTrap b = FragTrap("Beta");

	ScavTrap c = ScavTrap("Charlie");
	ScavTrap d = ScavTrap("Delta");

	std::cout << std::endl;

	a.meleeAttack(b);
	b.rangedAttack(a);

	std::cout << std::endl;

	c.meleeAttack(d);
	d.rangedAttack(c);

	std::cout << std::endl;

	a.beEnergized(4 * 25);

	for (std::size_t i = 0; i < 5; i++)
		a.vaulthunter_dot_exe(b);

	std::cout << std::endl;

	for (std::size_t i = 0; i < 5; i++)
		c.challengeNewcomer();

	std::cout << std::endl;

	return 0;
}
