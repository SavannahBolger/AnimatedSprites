#ifndef INPUT_H
#define INPUT_H
#include <AnimatedSprite.h>

class Input
{
public:
	Input();
	~Input();

	enum Action
	{
		IDLE,
		UP,
		LEFT,
		RIGHT,
		SPACE,
		DOWN,
		H,
		S
	};

	void setCurrent(Action);
	Action getCurrent();

private:
	Action m_current;
};
#endif