#include "utils.h"

void clear_screen() {
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || (__APPLE__)
        std::system("clear");
    #endif
}

void banner(std::string banner_message) {
    std::string banner_case = "=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    std::string banner_message_f = "\t" + banner_message + "\t\n";
    std::string banner = banner_case + banner_message_f + banner_case;
    std::cout << banner << std::endl;
}

void welcome_banner(std::string banner_message) {
    std::string author = "By: dannyc_dev";
    std::string banner_case = "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    std::string banner_message_f = "\t" + banner_message + "\t\n";
    std::string banner_message_a = "\t  " + author + "\t\n";
    std::string banner = banner_case + banner_message_f + banner_message_a + banner_case;
    std::cout << banner << std::endl;
}

void end_game_banner(std::string banner_message) {
    std::string banner_case = "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    std::string banner_message_f = "\t" + banner_message + "\t\n";
    std::string banner = banner_case + banner_message_f + banner_case;
    std::cout << banner << std::endl;
}

void player_banner(std::string player_banner_message, int total_hp, int health, int armor, int player_id) {
    std::string banner_case = "=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    std::string pad_row = "| \t\t\t | \n";

    // Player card title
    std::string banner_message_f = "|\t" + player_banner_message + "\t |\n";

    // Player card info
    /*std::string banner_player_id = "|Player ID: " + std::to_string(player_id) + "\t\t |\n";*/
    std::string banner_player_total_hp = "|Total HP: " + std::to_string(total_hp) + "\t\t |\n";
    std::string banner_player_health = "|Health: " + std::to_string(health) + "\t\t |\n";
    std::string banner_player_armor = "|Armor: " + std::to_string(armor) + "\t\t |\n";

    std::string banner = banner_case + pad_row + banner_message_f + banner_player_total_hp + banner_player_health + banner_player_armor + pad_row + banner_case;
    std::cout << banner << std::endl;
}

void game_log_banner(std::vector<int> game_events) {
    std::string banner_case = "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    std::string pad_row = "| \t\t\t\t\t|\n";
    std::string banner;

    if (game_events.size() == 1) {
        std::string banner_dmg = std::to_string(game_events[0]);
        std::string banner_message_f = "|\tPlayer dealt " + banner_dmg + " to enemy \t|\n";
        banner = banner_case + pad_row + banner_message_f + pad_row + banner_case;
    }
    else if (game_events.size() == 2) {
        std::string player_dmg = std::to_string(game_events[0]);
        std::string enemy_dmg = std::to_string(game_events[1]);
        std::string player_message = "|\tPlayer dealt " + player_dmg + " to enemy \t|\n";
        std::string enemy_message = "|\tEnemy dealt " + enemy_dmg + " to player \t|\n";

        banner = banner_case + pad_row + player_message + enemy_message + pad_row + banner_case;
    }
    
    std::cout << banner << std::endl;
}

void game_heal_banner(std::vector<int> game_events) {
    std::string banner_case = "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    std::string pad_row = "| \t\t\t\t\t\t|\n";
    std::string banner;

    if (game_events.size() == 2) {
        std::string player_heal = std::to_string(game_events[0]);
        std::string enemy_heal = std::to_string(game_events[1]);
        std::string player_message = "|\tPlayer regained " + player_heal + " health from potion \t|\n";
        std::string enemy_message = "|\tEnemy regained " + enemy_heal + " health from potion \t|\n";

        banner = banner_case + pad_row + player_message + enemy_message + pad_row + banner_case;
    }

    std::cout << banner << std::endl;
}

