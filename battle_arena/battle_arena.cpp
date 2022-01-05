#include <iostream>
#include <string>
#include "player/player.h"
#include "game/game.h"
#include "utils/utils.h"
#include <windows.h>

// Globals
static Player player(0);
static Player enemy(1);
static Game game(player, enemy);

int main() {
    // Create and size console window
    HWND console = GetConsoleWindow();
    SetConsoleTitle(L"Battle Arena");

    RECT ConsoleRect;
    const int width = 1100;
    const int height = 700;

    GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.right / 2 - width / 3, ConsoleRect.bottom / 2 - height / 3, width, height, TRUE);
    clear_screen();

    const std::string w_banner = "Battle Arena In Memory!";
    const std::string player_name = "My Player";
    const std::string enemy_name = "Enemy Player";

    srand((unsigned)time(0));
    welcome_banner(w_banner);
    player.show_player_health(player_name);
    enemy.show_player_health(enemy_name);

    // Game loop
    do {
        int user_opt = game.get_user_input();
        switch (user_opt) {
            case 0: {
                // Show Game Details for Game
                clear_screen();
                std::cout << "Showing Game Details: " << std::endl;
                player.show_player_health(player_name);
                enemy.show_player_health(enemy_name);
                break;
            }
            case 1: {
                // Attack
                clear_screen();
                game.battle(player, enemy);
                if (game.m_progress) {
                    player.show_player_health(player_name);
                    enemy.show_player_health(enemy_name);
                }
                else {
                    // Game over 
                    system("pause");
                }
                break;
            }
            case 2: {
                // Heal 
                clear_screen();
                game.battle_heal(player, enemy);
                if (game.m_progress) {
                    player.show_player_health(player_name);
                    enemy.show_player_health(enemy_name);
                }
                else {
                    // Game over 
                    system("pause");
                }
                break;
            }
            case 3: {
                // Reset player stats
                clear_screen();
                game.reset_game();
                player.show_player_health(player_name);
                enemy.show_player_health(enemy_name);
                break;
            }
            case 4: {
                // Show Debug Info
                clear_screen();
                game.debug_data();
                break;
            }
            case 5: {
                // Surrender
                clear_screen();
                std::cout << "Game Over. Goodbye." << std::endl;
                game.m_progress = false;
                break;
            }
            default: {
                clear_screen();
                std::cout << user_opt << " is not a valid choice" << std::endl;
            }
        }

    } while (game.m_progress);


    return 0;
}