#include <Walking.h>
#include <Hammering.h>
#include <Swordsmanship.h>
#include <Idle.h>

void Walking::idle(Animation * a)
{
	std::cout << "Walking -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Walking::hammering(Animation * a)
{
	std::cout << "Idle -> Hammering" << std::endl;
	a->setCurrent(new Hammering());
	delete this;
}

void Walking::swordsmanship(Animation * a)
{
	std::cout << "Idle -> Swordsmanship" << std::endl;
	a->setCurrent(new Swordsmanship());
	delete this;
}
