#ifndef MEM_TEST_ENTITY_H
#define MEM_TEST_ENTITY_H
#pragma once

class Entity {
public:
	Entity(int health, int armor, int total_hp) : m_health{ health }, m_armor{ armor }, m_total_hp{ total_hp } {}
protected:
	int m_health;
	int m_armor;
	int m_total_hp;
};

#endif
