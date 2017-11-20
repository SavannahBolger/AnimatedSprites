#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite &Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::handleInput(Input in, AnimatedSprite array[])
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	case Input::Action::IDLE:
		//std::cout << "Player Idling" << std::endl;
		m_animation.idle();
		break;
	case Input::Action::UP:
		//std::cout << "Player Up" << std::endl;
		m_animation.climbing();
		break;
	case Input::Action::LEFT:
		//std::cout << "Player Left" << std::endl;
		m_animation.walking();
		break;
	case Input::Action::RIGHT:
		//std::cout << "Player Right" << std::endl;
		m_animation.walking();
		break;
	case Input::Action::SPACE:
		//std::cout << "Player Jumping" << std::endl;
		m_animation.jumping();
		break;
	case Input::Action::DOWN:
		//std::cout << "Player Shoveling" << std::endl;
		m_animation.shoveling();
		break;
	case Input::Action::S:
		//std::cout << "Player Swordsmanship" << std::endl;
		m_animation.swordsmanship();
		break;
	case Input::Action::H:
		//std::cout << "Player Hammering" << std::endl;
		m_animation.hammering();
		break;
	default:
		break;
	}

	m_animated_spriteArray[0] = array[0];
	m_animated_spriteArray[1] = array[1];
	m_animated_spriteArray[2] = array[2];
	m_animated_spriteArray[3] = array[3];
	m_animated_spriteArray[4] = array[4];
	m_animated_spriteArray[5] = array[5];
	m_animated_spriteArray[6] = array[6];

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_animated_spriteArray[1].addFrame(sf::IntRect(3, 88, 84, 84));
		m_animated_spriteArray[1].addFrame(sf::IntRect(88, 88, 84, 84));
		m_animated_spriteArray[1].addFrame(sf::IntRect(173, 88, 84, 84));
		m_animated_spriteArray[1].addFrame(sf::IntRect(258, 88, 84, 84));
		m_animated_spriteArray[1].addFrame(sf::IntRect(343, 88, 84, 84));
		m_animated_spriteArray[1].addFrame(sf::IntRect(428, 88, 84, 84));
		m_animated_sprite = m_animated_spriteArray[1];
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_animated_spriteArray[1].addFrame(sf::IntRect(3, 88, 84, 84));
		m_animated_spriteArray[1].addFrame(sf::IntRect(88, 88, 84, 84));
		m_animated_spriteArray[1].addFrame(sf::IntRect(173, 88, 84, 84));
		m_animated_spriteArray[1].addFrame(sf::IntRect(258, 88, 84, 84));
		m_animated_spriteArray[1].addFrame(sf::IntRect(343, 88, 84, 84));
		m_animated_spriteArray[1].addFrame(sf::IntRect(428, 88, 84, 84));
		m_animated_sprite = m_animated_spriteArray[1];
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_animated_spriteArray[3].addFrame(sf::IntRect(3, 258, 84, 84));
		m_animated_spriteArray[3].addFrame(sf::IntRect(88, 258, 84, 84));
		m_animated_spriteArray[3].addFrame(sf::IntRect(173, 258, 84, 84));
		m_animated_spriteArray[3].addFrame(sf::IntRect(258, 258, 84, 84));
		m_animated_spriteArray[3].addFrame(sf::IntRect(343, 258, 84, 84));
		m_animated_spriteArray[3].addFrame(sf::IntRect(428, 258, 84, 84));

		m_animated_sprite = m_animated_spriteArray[3];
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_animated_spriteArray[4].addFrame(sf::IntRect(3, 343, 84, 84));
		m_animated_spriteArray[4].addFrame(sf::IntRect(88, 343, 84, 84));
		m_animated_spriteArray[4].addFrame(sf::IntRect(173, 343, 84, 84));
		m_animated_spriteArray[4].addFrame(sf::IntRect(258, 343, 84, 84));
		m_animated_spriteArray[4].addFrame(sf::IntRect(343, 343, 84, 84));
		m_animated_spriteArray[4].addFrame(sf::IntRect(428, 343, 84, 84));
		m_animated_sprite = m_animated_spriteArray[4];
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_animated_spriteArray[2].addFrame(sf::IntRect(3, 173, 84, 84));
		m_animated_spriteArray[2].addFrame(sf::IntRect(88, 173, 84, 84));
		m_animated_spriteArray[2].addFrame(sf::IntRect(173, 173, 84, 84));
		m_animated_spriteArray[2].addFrame(sf::IntRect(258, 173, 84, 84));
		m_animated_spriteArray[2].addFrame(sf::IntRect(343, 173, 84, 84));
		m_animated_spriteArray[2].addFrame(sf::IntRect(428, 173, 84, 84));
		m_animated_sprite = m_animated_spriteArray[2];
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_animated_spriteArray[6].addFrame(sf::IntRect(3, 513, 84, 84));
		m_animated_spriteArray[6].addFrame(sf::IntRect(88, 513, 84, 84));
		m_animated_spriteArray[6].addFrame(sf::IntRect(173, 513, 84, 84));
		m_animated_spriteArray[6].addFrame(sf::IntRect(258, 513, 84, 84));
		m_animated_spriteArray[6].addFrame(sf::IntRect(343, 513, 84, 84));
		m_animated_spriteArray[6].addFrame(sf::IntRect(428, 513, 84, 84));
		m_animated_sprite = m_animated_spriteArray[6];
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		m_animated_spriteArray[5].addFrame(sf::IntRect(3, 428, 84, 84));
		m_animated_spriteArray[5].addFrame(sf::IntRect(88, 428, 84, 84));
		m_animated_spriteArray[5].addFrame(sf::IntRect(173, 428, 84, 84));
		m_animated_spriteArray[5].addFrame(sf::IntRect(258, 428, 84, 84));
		m_animated_spriteArray[5].addFrame(sf::IntRect(343, 428, 84, 84));
		m_animated_spriteArray[5].addFrame(sf::IntRect(428, 428, 84, 84));
		m_animated_sprite = m_animated_spriteArray[5];
	}
	else
	{
		m_animated_spriteArray[0].addFrame(sf::IntRect(3, 3, 84, 84));
		m_animated_spriteArray[0].addFrame(sf::IntRect(88, 3, 84, 84));
		m_animated_spriteArray[0].addFrame(sf::IntRect(173, 3, 84, 84));
		m_animated_spriteArray[0].addFrame(sf::IntRect(258, 3, 84, 84));
		m_animated_spriteArray[0].addFrame(sf::IntRect(343, 3, 84, 84));
		m_animated_spriteArray[0].addFrame(sf::IntRect(428, 3, 84, 84));
		m_animated_sprite = m_animated_spriteArray[0];
	}
}

void Player::update()
{
	
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite.update();

}