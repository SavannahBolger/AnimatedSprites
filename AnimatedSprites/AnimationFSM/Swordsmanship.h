#ifndef SWORDSMANSHIP_H
#define SWORDSMANSHIP_H

#include <State.h>

class Swordsmanship : public State
{
public:
	Swordsmanship() {};
	~Swordsmanship() {};
	void idle(Animation* a);
};

#endif // !SWORDSMANSHIP_H
