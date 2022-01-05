#include "game.h"

int Game::get_user_input() {
	show_menu();
	int user_option = get_user_option();
	return user_option;
}

void Game::show_menu() {
    /*
    Options:
        - Show game details: view details about game and players
        - Attack: Attack opponent but risk damage
        - Heal: Heal Player
        - Reset Game: Resets the game to original state
        - Debug Data: Shows debug data for game
        - Surrender: End Game
    */
    std::cout << "Game Menu:" << std::endl;
    std::cout << "0 - Show Game Details" << std::endl;
    std::cout << "1 - Attack!!" << std::endl;
    std::cout << "2 - Heal!" << std::endl;
    std::cout << "3 - Reset Game" << std::endl;
    std::cout << "4 - Debug Data (Windows Only)" << std::endl;
    std::cout << "5 - Quit" << std::endl;
}

int Game::get_user_option() {
    int i_user_option;
    std::cout << "Enter Option: ";

    std::string user_option;

    getline(std::cin >> std::ws, user_option);

    try {
        i_user_option = std::stoi(user_option);
    } catch(...) {
        return -1;
    }
    return i_user_option;
}

void Game::debug_data() {
    TCHAR szFileName[MAX_PATH];
    
    HANDLE game_process_handle = GetCurrentProcess();
    DWORD procId = GetProcessId(game_process_handle);
    GetModuleFileName(NULL, szFileName, MAX_PATH);

    std::cout << "Game Debug Data: " << std::endl;
    std::wcout << "Full File Path: " << szFileName << std::endl;
    std::cout << "Process ID: " << procId << std::endl;
}

void Game::reset_game() {
    for (Player& player : playerList) {
        reset_player_stats(player);
    }
}

void Game::reset_player_stats(Player& player) {
    player.set_health(100);
    player.set_armor(50);
    player.set_total_hp();
}

void Game::battle(Player& player1, Player& player2) {
    // Attack banner
    std::string battle_banner = "Battle Arena!";
    banner(battle_banner);

    std::vector<int> game_log;

    int player_damage = player1.attack();
    player2.take_damage(player_damage);
    game_log.push_back(player_damage);
    if (check_game_over(player1, player2)) {
        game_log_banner(game_log);
        // Show winner banner
        show_winner(player1, player2);
        return;
    }
    

    int enemy_damage = player2.attack();
    player1.take_damage(enemy_damage);
    game_log.push_back(enemy_damage);
    if (check_game_over(player1, player2)) {
        game_log_banner(game_log);
        // Show winner banner
        show_winner(player1, player2);
        return;
    }
    
    // The show goes on...
    game_log_banner(game_log);
}

void Game::battle_heal(Player& player1, Player& player2) {
    // Attack banner
    std::string battle_banner = "Healing Tent!";
    banner(battle_banner);

    std::vector<int> game_log;

    int player1_heal = player1.heal();
    game_log.push_back(player1_heal);
    player1.heal_player(player1_heal);

    int player2_heal = player2.heal();
    game_log.push_back(player2_heal);
    player2.heal_player(player2_heal);

    game_heal_banner(game_log);
}

Player* Game::get_winner(Player& player1, Player& player2) {
    if (player1.get_total_hp() == 0) {
        m_progress = false;
        return &player2;
    }
    else if (player2.get_total_hp() == 0) {
        m_progress = false;
        return &player1;
    }
    return NULL;
}

std::string Game::winner_title(Player* winner) {
    std::string player_title;
    if (winner->player_id == 0) {
        player_title = "Player Wins!";
        return player_title;
    }
    else if (winner->player_id == 1) {
        player_title = "Enemy Wins!";
        return player_title;
    } 
    else {
        throw std::invalid_argument("received invalid player id");
    }
}

bool Game::check_game_over(Player& player1, Player& player2) {
    if ((player1.get_total_hp() == 0) || (player2.get_total_hp() == 0)) {
        return true;
    }
    return false;
}

void Game::show_winner(Player& player1, Player& player2) {
    Player* winning_player = get_winner(player1, player2);

    int winning_player_total_hp = winning_player->get_total_hp();
    int winning_player_health = winning_player->get_health();
    int winning_player_armor = winning_player->get_armor();

    std::string end_game_winner_text = winner_title(winning_player);

    winner_banner(end_game_winner_text, winning_player);
}

void Game::winner_banner(std::string player_winner_message, Player* winning_player) {
    std::string banner_case = "=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    std::string pad_row = "| \t\t\t | \n";

    // Player card title
    std::string banner_message_f = "|\t" + player_winner_message + "\t |\n";

    int wp_total_hp = winning_player->get_total_hp();
    int wp_health = winning_player->get_health();
    int wp_armor = winning_player->get_armor();

    // Player card info
    std::string banner_player_total_hp = "|Total HP: " + std::to_string(wp_total_hp) + "\t\t |\n";
    std::string banner_player_health = "|Health: " + std::to_string(wp_health) + "\t\t |\n";
    std::string banner_player_armor = "|Armor: " + std::to_string(wp_armor) + "\t\t |\n";

    std::string banner = banner_case + pad_row + banner_message_f + banner_player_total_hp + banner_player_health + banner_player_armor + pad_row + banner_case;
    std::cout << banner << std::endl;
}