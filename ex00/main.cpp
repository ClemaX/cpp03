#include "FragTrap.hpp"

int main(void)
{
	srand(time(NULL));

	FragTrap a = FragTrap("Alpha");
	FragTrap b = FragTrap("Beta");

	std::cout << std::endl;

	a.meleeAttack(b);
	b.rangedAttack(a);

	std::cout << std::endl;

	for (std::size_t i = 0; i < 5; i++)
		a.vaulthunter_dot_exe(b);

	std::cout << std::endl;

	return 0;
}
