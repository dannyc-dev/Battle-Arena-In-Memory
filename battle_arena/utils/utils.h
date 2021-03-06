#ifndef MEM_TEST_UTILS_H
#define MEM_TEST_UTILS_H
#pragma once

#include "../player/player.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

void clear_screen();
void banner(std::string banner_message);
void welcome_banner(std::string banner_message);
void end_game_banner(std::string banner_message);
void player_banner(std::string player_banner_message, int total_hp, int health, int armor, int player_id);
void game_log_banner(std::vector<int> game_events);
void game_heal_banner(std::vector<int> game_events);

#endif
