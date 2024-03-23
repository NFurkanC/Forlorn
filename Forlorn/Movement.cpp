#include "stdafx.h"
#include "Movement.h"

Movement::Movement()
{
	this->init();
}

Movement::~Movement()
{
}

void Movement::init()
{
	this->maxVelocity = 15.f;
	this->acceleration = 1.5f;
	this->deacceleration = 0.98f;
	this->minVelocity = 1.f;
	this->gravity = 1.5f;
	this->maxFallVelocity = 15.f;
	this->dt = 0.006f;
}

void Movement::update()
{
}

void Movement::render(sf::RenderTarget& target)
{
}

void Movement::move(const float dir_x, const float dir_y)
{
	
	//Acceleration
	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y += this->acceleration * dir_y;
	//Limit velocity
	if (this->velocity.x > this->maxVelocity)
		this->velocity.x = this->maxVelocity;
	else if (this->velocity.x < -this->maxVelocity)
		this->velocity.x = -this->maxVelocity;
	if (this->velocity.y > this->maxVelocity)
		this->velocity.y = this->maxVelocity;
	else if (this->velocity.y < -this->maxVelocity)
		this->velocity.y = -this->maxVelocity;
}

void Movement::stop(const float dir_x, const float dir_y)
{
	//Deacceleration
	this->velocity.x *= this->deacceleration;
	this->velocity.y *= this->deacceleration;
	//Limit deacceleration
	if (std::abs(this->velocity.x) < this->minVelocity)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->minVelocity)
		this->velocity.y = 0.f;
}

void Movement::grav()
{
	//Gravity
	this->velocity.y += this->gravity;
	if (this->velocity.y > this->maxFallVelocity)
		this->velocity.y = this->maxFallVelocity;
}

void Movement::resetVelocityY()
{
	this->velocity.y = 0.f;
}

const sf::Vector2f& Movement::getVelocity() const
{
	// TODO: insert return statement here
	return this->velocity;
}
