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

// This needs to be rewritten lol
void Player::heal_player(int health) {
    int max_armor = 50;
    int max_health = 100;
    int current_health = get_total_hp();
    
    if (m_total_hp == 150) {
        return;
    }

    if (current_health > 100) {
        int t_armor = m_armor + health;
        if (t_armor > max_armor) {
            t_armor = max_armor;
        }
        m_armor = t_armor;
        set_total_hp();
    }
    else {
        int t_health = m_health + health;
        if (t_health > max_health) {
            int armor_health = t_health - max_health;
            if (armor_health > max_armor) {
                m_armor = max_armor;
                m_health = max_health;
                set_total_hp();
            }
            else {
                m_armor = armor_health;
                m_health = max_health;
                set_total_hp();
            }
        }
        else {
            m_health = t_health;
            set_total_hp();
        }

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

int Player::heal() {
    // RNG parameters
    int max = 100;
    int min = 0;

    // RNG
    int health = std::rand() % ((max - min + 1) + min);

    return health;
}

