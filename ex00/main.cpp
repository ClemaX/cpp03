#include "FragTrap.hpp"

int main(void)
{
	FragTrap a = FragTrap("Alpha");
	FragTrap b = FragTrap("Beta");

	a.meleeAttack(b.name);
	b.rangedAttack(a.name);

	for (std::size_t i = 0; i < a.specialAttacks.size(); i++)
		a.vaulthunter_dot_exe(b.name);

	return 0;
}
