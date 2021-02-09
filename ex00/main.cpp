#include "FragTrap.hpp"

int main(void)
{
	FragTrap a = FragTrap("Alpha");
	FragTrap b = FragTrap("Beta");

	a.meleeAttack(b);
	b.rangedAttack(a);

	for (std::size_t i = 0; i < 10; i++)
		a.vaulthunter_dot_exe(b);

	return 0;
}
