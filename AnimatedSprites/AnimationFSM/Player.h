#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

#include <Input.h>
#include <Animation.h>
#include <AnimatedSprite.h>

class Player
{
private:
	Animation m_animation;
	AnimatedSprite m_animated_sprite;
	Player();

public:
	Player(const AnimatedSprite&);
	~Player();
	AnimatedSprite m_animated_spriteArray[7];
	AnimatedSprite& getAnimatedSprite();
	void handleInput(Input, AnimatedSprite array[]);
	void update();
};

#endif // !PLAYER_H
