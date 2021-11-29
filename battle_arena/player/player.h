#ifndef MEM_TEST_PlAYER_H
#define MEM_TEST_PLAYER_H
#pragma once

#include <iostream>
#include <tuple>
#include "../entity/entity.h"
#include "../utils/utils.h"

class Player : public Entity {
public:
	Player(int id) : Entity(100, 50, 150), player_id{ id } {}
	int player_id;
	int get_total_hp() { return m_total_hp; };
	int get_health() { return m_health; };
	int get_armor() { return m_armor; };
	void set_total_hp();
	void set_armor(int armor);
	void set_health(int health);
	void take_damage(int dmg);
	void show_player_health(std::string player_name);
	int attack(int damage = -1);
};

#endif