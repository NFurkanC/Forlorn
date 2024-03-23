#pragma once
class Movement
{
private:
	
	float maxVelocity;
	float acceleration;
	float deacceleration;
	float minVelocity;
	float gravity;
	float maxFallVelocity;
public:
	Movement();
	virtual ~Movement();
	float dt;
	void init();
	void update();
	void render(sf::RenderTarget& target);
	void move(const float dir_x, const float dir_y);
	void stop(const float dir_x, const float dir_y);
	void grav();
	void resetVelocityY();
	const sf::Vector2f& getVelocity() const;
	sf::Vector2f velocity;
};

