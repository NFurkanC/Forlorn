#include "stdafx.h"
#include "Player.h"
class Game
{
private:
	sf::RenderWindow window;
	sf::Event event;

	Player* player;
	void initWindow();
	void isClosed();
	void initPlayer();
	
public:
	void run();
	virtual ~Game();
	Game();
	//Functions
	void updatePlayer();
	void checkCollision();
	void update();
	void render();
	const sf::RenderWindow& getWindow() const;
};

