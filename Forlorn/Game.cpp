#include "stdafx.h"
#include "Game.h"

void Game::initWindow()
{
	this->window.create(sf::VideoMode(2560, 1440), "Forlorn", sf::Style::None);
	this->window.setFramerateLimit(165);
}

void Game::isClosed()
{
	while (this->window.pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window.close();
		else if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
			this->window.close();
	}
}

void Game::initPlayer()
{
	this->player = new Player();//create player in the memory
}

void Game::run()
{
	while (this->window.isOpen())
	{
		this->update();
		this->render();
	}
}

Game::~Game()
{
	delete this->player;//delete player from the memory
}

Game::Game()
{
	this->initWindow();
	this->initPlayer();
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::checkCollision()
{
		//Check collision
	if (this->player->getGlobalBounds().top + this->player->getGlobalBounds().height > this->window.getSize().y)
	{
		this->player->movement->resetVelocityY();
		this->player->setPosition(this->player->getGlobalBounds().left, this->window.getSize().y - this->player->getGlobalBounds().height);
		this->player->onGround = true;
	}
		else
	{
		this->player->onGround = false;
	}
}

void Game::update()
{
	this->isClosed();
	this->checkCollision();
	this->updatePlayer();
}

void Game::render()
{
	this->window.clear(sf::Color::Black);
	//Render
	this->player->render(this->window);//player renderer
	this->window.display();
}

const sf::RenderWindow& Game::getWindow() const
{
	return this->window;
}
