#include "stdafx.h"
#include "PlayerAttributes.h"

PlayerAttributes::PlayerAttributes()
{
	this->init();
}

PlayerAttributes::~PlayerAttributes()
{
}

bool PlayerAttributes::isDead()
{
	if(currentHealth <= 0)
		return true;
	else if (currentHealth > 0)
		return false;
}

void PlayerAttributes::damageReduction()
{
	//gradual defence reduction
}

void PlayerAttributes::init()
{
	this->currentHealth = 100.f;
	this->maxHealth = 100.f;
	this->defence = 10.f;
	this->attack = 10.f;
	this->attackSpeed = 10.f;
	this->critChance = 10.f;
	this->critDamage = 10.f;
	this->currentExperience = 0;
	this->thoughtLevel = 0;
	this->skillPoints = 0;
	this->triFate = sf::Vector3f(0.f, 0.f, 0.f);
	this->isInvincible = false;
}

void PlayerAttributes::healthManager()
{
	//health regeneration

	//health reduction

	//health cap

	//health bar


}

void PlayerAttributes::experienceManager()
{
	//experience gain

	//experience cap

	//experience bar

	//level up

	//skill points

	//thought level

}

void PlayerAttributes::attackManager()
{
	//adjust attack based on items

	//adjust attack based on level

	//adjust attack based on de/buffs

}


