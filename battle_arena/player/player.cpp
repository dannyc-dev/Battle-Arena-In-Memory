#include "player.h"
#include "../utils/utils.h"

void Player::take_damage(int dmg) {
    if (m_armor >= dmg) {
        m_armor -= dmg;
        set_total_hp();
    }
    else if ((dmg > m_armor) && ((dmg - m_armor) < m_health)) {
        m_health = m_health - (dmg - m_armor) ;
        m_armor = 0;
        set_total_hp();
    }
    else {
        m_armor = 0;
        m_health = 0;
        set_total_hp();
    }
}

void Player::set_total_hp() {
    m_total_hp = m_armor + m_health;
}

void Player::set_armor(int armor) {
    m_armor = armor;
}

void Player::set_health(int health) {
    m_health = health;
}

void Player::show_player_health(std::string player_name) {
    player_banner(player_name, m_total_hp, m_health, m_armor, player_id);
}

int Player::attack(int damage) {
    // RNG parameters
    int max = 100;
    int min = 0;

    // RNG
    int rng_damage = std::rand() % ((max - min + 1) + min);

    return rng_damage;
}

