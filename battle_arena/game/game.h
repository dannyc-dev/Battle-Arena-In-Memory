#ifndef MEM_TEST_GAME_H
#define MEM_TEST_GAME_H
#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "windows.h"
#include "../player/player.h"

class Game {
public:
	Game(Player* player1, Player* player2) {
		playerList = { player1, player2 };
	}
	std::vector<Player*> playerList;
	bool m_progress = true;
	bool m_menu = true;
	int get_user_input();
	void debug_data();
	void reset_game();
	void battle();
	void battle_heal();
	Player* get_winner(Player* player1, Player* player2);
	bool check_game_over(Player* player1, Player* player2);
protected:
	void show_menu();
	int get_user_option();
	void reset_player_stats(Player* player);
	std::string winner_title(Player* winner);
	void show_winner(Player* player1, Player* player2);
	void winner_banner(std::string player_winner_message, Player* winning_player);
};

#endif