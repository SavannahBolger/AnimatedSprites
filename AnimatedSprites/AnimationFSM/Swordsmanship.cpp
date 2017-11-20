#include <Swordsmanship.h>
#include <Idle.h>

void Swordsmanship::idle(Animation * a)
{
	std::cout << "Swordsmanship -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
