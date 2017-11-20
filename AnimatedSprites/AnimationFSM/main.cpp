#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>

using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	std::cout << "Don't press anything for the Idling state" << std::endl;
	std::cout << "Press the Left or Right key for the Walking state" << std::endl;
	std::cout << "Press the Up key for the Climbing state" << std::endl;
	std::cout << "Press the Spacebar for the Jumping state" << std::endl;
	std::cout << "Press the Down key for the Shoveling state" << std::endl;
	std::cout << "Press S for the Swordsmanship state" << std::endl;
	std::cout << "Press H for the Hammering state" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	// Setup Players Default Animated Sprite
	AnimatedSprite m_animated_sprite(texture);
	AnimatedSprite m_animated_spriteIdle(texture);
	AnimatedSprite m_animated_spriteWalk(texture);
	AnimatedSprite m_animated_spriteJump(texture);
	AnimatedSprite m_animated_spriteClimb(texture);
	AnimatedSprite m_animated_spriteShovel(texture);
	AnimatedSprite m_animated_spriteHammer(texture);
	AnimatedSprite m_animated_spriteSword(texture);

	/*m_animated_spriteWalk.addFrame(sf::IntRect(3, 88, 84, 84));
	m_animated_spriteWalk.addFrame(sf::IntRect(88, 88, 84, 84));
	m_animated_spriteWalk.addFrame(sf::IntRect(173, 88, 84, 84));
	m_animated_spriteWalk.addFrame(sf::IntRect(258, 88, 84, 84));
	m_animated_spriteWalk.addFrame(sf::IntRect(343, 88, 84, 84));
	m_animated_spriteWalk.addFrame(sf::IntRect(428, 88, 84, 84));

	m_animated_spriteClimb.addFrame(sf::IntRect(3, 258, 84, 84));
	m_animated_spriteClimb.addFrame(sf::IntRect(88, 258, 84, 84));
	m_animated_spriteClimb.addFrame(sf::IntRect(173, 258, 84, 84));
	m_animated_spriteClimb.addFrame(sf::IntRect(258, 258, 84, 84));
	m_animated_spriteClimb.addFrame(sf::IntRect(343, 258, 84, 84));
	m_animated_spriteClimb.addFrame(sf::IntRect(428, 258, 84, 84));

	m_animated_spriteShovel.addFrame(sf::IntRect(3, 343, 84, 84));
	m_animated_spriteShovel.addFrame(sf::IntRect(88, 343, 84, 84));
	m_animated_spriteShovel.addFrame(sf::IntRect(173, 343, 84, 84));
	m_animated_spriteShovel.addFrame(sf::IntRect(258, 343, 84, 84));
	m_animated_spriteShovel.addFrame(sf::IntRect(343, 343, 84, 84));
	m_animated_spriteShovel.addFrame(sf::IntRect(428, 343, 84, 84));

	m_animated_spriteJump.addFrame(sf::IntRect(3, 173, 84, 84));
	m_animated_spriteJump.addFrame(sf::IntRect(88, 173, 84, 84));
	m_animated_spriteJump.addFrame(sf::IntRect(173, 173, 84, 84));
	m_animated_spriteJump.addFrame(sf::IntRect(258, 173, 84, 84));
	m_animated_spriteJump.addFrame(sf::IntRect(343, 173, 84, 84));
	m_animated_spriteJump.addFrame(sf::IntRect(428, 173, 84, 84));

	m_animated_spriteSword.addFrame(sf::IntRect(3, 513, 84, 84));
	m_animated_spriteSword.addFrame(sf::IntRect(88, 513, 84, 84));
	m_animated_spriteSword.addFrame(sf::IntRect(173, 513, 84, 84));
	m_animated_spriteSword.addFrame(sf::IntRect(258, 513, 84, 84));
	m_animated_spriteSword.addFrame(sf::IntRect(343, 513, 84, 84));
	m_animated_spriteSword.addFrame(sf::IntRect(428, 513, 84, 84));

	m_animated_spriteHammer.addFrame(sf::IntRect(3, 428, 84, 84));
	m_animated_spriteHammer.addFrame(sf::IntRect(88, 428, 84, 84));
	m_animated_spriteHammer.addFrame(sf::IntRect(173, 428, 84, 84));
	m_animated_spriteHammer.addFrame(sf::IntRect(258, 428, 84, 84));
	m_animated_spriteHammer.addFrame(sf::IntRect(343, 428, 84, 84));
	m_animated_spriteHammer.addFrame(sf::IntRect(428, 428, 84, 84));

	m_animated_spriteIdle.addFrame(sf::IntRect(3, 3, 84, 84));
	m_animated_spriteIdle.addFrame(sf::IntRect(88, 3, 84, 84));
	m_animated_spriteIdle.addFrame(sf::IntRect(173, 3, 84, 84));
	m_animated_spriteIdle.addFrame(sf::IntRect(258, 3, 84, 84));
	m_animated_spriteIdle.addFrame(sf::IntRect(343, 3, 84, 84));
	m_animated_spriteIdle.addFrame(sf::IntRect(428, 3, 84, 84));*/
	
	AnimatedSprite m_animated_spriteCurrent[7] = {  m_animated_spriteIdle,
	 m_animated_spriteWalk,
	 m_animated_spriteJump,
	 m_animated_spriteClimb,
	 m_animated_spriteShovel,
	 m_animated_spriteHammer,
	 m_animated_spriteSword };

	// Setup the Player
	Player player(m_animated_sprite);
	Input input;

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					input.setCurrent(Input::Action::LEFT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					input.setCurrent(Input::Action::RIGHT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					input.setCurrent(Input::Action::UP);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					input.setCurrent(Input::Action::DOWN);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					input.setCurrent(Input::Action::SPACE);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					input.setCurrent(Input::Action::S);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
				{
					input.setCurrent(Input::Action::H);
				}
				break;
			default:
				input.setCurrent(Input::Action::IDLE);
				break;
			}
		}

		// Handle input to Player
		player.handleInput(input, m_animated_spriteCurrent);

		// Update the Player
		player.update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};