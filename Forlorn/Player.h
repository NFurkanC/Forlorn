#pragma once
#include "Movement.h"
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture playerTexture;
	//sf::Vector2u imageCount;
	sf::Vector2u currentFrame;
	//float totalTime;
	//float switchTime;
	
	void TextureInitializer();
	void SpriteInitializer();
	float totalTime = 0.f;
public:
	Player();
	virtual ~Player();
	//Functions
	const sf::FloatRect getGlobalBounds() const;
	void setPosition(float x, float y);
	void move();
	bool inAir = !onGround;
	bool onGround;
	void gravTest();
	void update();//Update player
	void render(sf::RenderTarget& target);//Render player
	Movement* movement;
};

