#include "stdafx.h"
#include "Player.h"



void Player::TextureInitializer()
{
	if(!this->playerTexture.loadFromFile("Textures\\tempest1.png"))
		std::cout << "ERROR::PLAYER::TEXTURE::NOT LOADED" << std::endl;
}

void Player::SpriteInitializer()
{
	this->sprite.setTexture(this->playerTexture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	this->sprite.setScale(7.f, 7.f);
	this->sprite.setPosition(400, 300);
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

Player::Player()
{
	this->TextureInitializer();
	this->SpriteInitializer();
	this->movement = new Movement();
}

Player::~Player()
{
}

void Player::setPosition(float x, float y)
{
		this->sprite.setPosition(x, y);
}

void Player::move()
{
#if 0

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->movement->move(0.f, -1.f);
	}
	else {
		this->movement->stop(0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->movement->move(-1.f, 0.f);
	else
		this->movement->stop(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->movement->move(0.f, 1.f);
	else
		this->movement->stop(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->movement->move(1.f, 0.f);
	else
		this->movement->stop(-1.f, 0.f);
	this->sprite.move(this->movement->velocity);
#endif // 0
	//do with the integration of inAir and onGround
	//if she is in air, she can only move left and right at a decreased speed
	//if she is on ground, she can move in all directions at full speed
	//she cannot jump if she is in air
	if (onGround) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			for (float i = 0.f; i < 10.f; i += this->movement->dt) {
				this->movement->move(0.f, -1.f);
			}
			this->movement->grav();
			this->movement->stop(0.f, 1.f);
		}
		else {
			this->movement->stop(0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			this->movement->move(-1.f, 0.f);
		else
			this->movement->stop(1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			this->movement->move(0.f, 1.f);
		else
			this->movement->stop(0.f, -1.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			this->movement->move(1.f, 0.f);
		else
			this->movement->stop(-1.f, 0.f);
		this->sprite.move(this->movement->velocity);
	}
	else if (inAir){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			this->movement->move(-0.5f, 0.f);
		else
			this->movement->stop(0.5f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			this->movement->move(0.5f, 0.f);
		else
			this->movement->stop(-0.5f, 0.f);
		this->sprite.move(this->movement->velocity);
	}
	else
		std::cout << "ERROR::PLAYER::MOVE::NEITHER ON GROUND NOR IN AIR" << std::endl;
}

void Player::gravTest()
{
	if (this->sprite.getPosition().y < 800){
		this->movement->grav();
		
		}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->movement->grav();
	}
	else
		this->movement->stop(0.f, 1.f);
	this->sprite.move(this->movement->velocity);
}

void Player::update()
{
	this->move();
	this->gravTest();
	//Everything related to player update
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
