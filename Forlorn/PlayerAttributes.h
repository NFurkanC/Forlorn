#pragma once
class PlayerAttributes
{
public:
	PlayerAttributes();
	virtual ~PlayerAttributes();
	//core stats
	float currentHealth;
	float maxHealth;
	float defence;//uninitialized

	//offensive stats
	float attack;//uninitialized
	float attackSpeed;//uninitialized
	float critChance;//uninitialized
	float critDamage;//uninitialized

	//experience stats
	uint16_t currentExperience;
	uint8_t thoughtLevel;
	uint8_t skillPoints;

	bool isDead();
	bool isInvincible;
	void damageReduction();

	std::vector<uint8_t> buffs; // store buffs in a dynamic array

	void init();

	sf::Vector3f triFate;//Tri-Fate Progression Vector

	void healthManager();
	void experienceManager();
	void attackManager();
};

