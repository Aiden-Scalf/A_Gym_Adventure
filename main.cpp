#include <iostream>
#include <cstdlib> // for rand, srand
#include <ctime>   // for time
#include <string>

using namespace std;

class Player {
public:
    string name;
    int score;

    Player(string player_name) : name(player_name), score(0) {
    }


    void update_score(int points) {
        score += points;
    }
};

class Game {
private:
    Player player;
    int turn;

public:
    Game(string name)
        : player(name), turn(1) {
    }

    void play_turn(int roll) {
        cout << "Turn " << turn << ": You rolled a " << roll << "!\n";
        player.update_score(roll);
        turn++;

        check_workout(); // Check if the player landed on a workout space
    }

    void display_scores() {
        cout << player.name << " has moved " << player.score << " places.\n";
    }

    bool has_won() {
        return player.score >= 30;
    }

    void check_workout() {
        int space = player.score;

        if (space == 1 || space == 11 || space == 21)
            cout << "\n Workout Time: Do 10 push-ups!\n";
        else if (space == 2 || space == 12 || space == 22)
            cout << "\n Workout Time: Do 10 squats!\n";
        else if (space == 3 || space == 13 || space == 23)
            cout << "\n Workout Time: Do 10 dips!\n";
        else if (space == 4 || space == 14 || space == 24)
            cout << "\n Workout Time: Do 10 burpees!\n";
        else if (space == 5 || space == 15 || space == 25)
            cout << "\n Workout Time: Do 10 sit-ups!\n";
        else if (space == 6 || space == 16 || space == 26)
            cout << "\n Workout Time: Do a 60-seconds of a plank!\n";
        else if (space == 7 || space == 17 || space == 27)
            cout << "\n Workout Time: Do 60 seconds of mountain-climbers!\n";
        else if (space == 8 || space == 18 || space == 28)
            cout << "\n Workout Time: Do 60 seconds of scissor-kicks!\n";
        else if (space == 9 || space == 19 || space == 29)
            cout << "\n Workout Time: Do 60 seconds of Super-mans!\n";
        else if (space == 10 || space == 20 || space == 30)
            cout << "\n Workout Time: Do 10 pistol squats!\n";
    }

    int get_score() {
        return player.score;
    }
};

// Dice roll function
int dice_roll() {
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }
    return (rand() % 6) + 1;
}

int main() {
    string realname;
    cout << "What is the player's name: ";
    cin >> realname;

    Game boardgame(realname);
    cin.ignore(); // Clear newline character after cin >> realname

    while (true) {
        cout << "\nPress Enter to roll the dice...";
        cin.get();

        int result = dice_roll();
        boardgame.play_turn(result);
        boardgame.display_scores();

        if (boardgame.has_won()) {
            cout << realname << " has reached 30 points and won the game!";
            break;
        }
    }

    return 0;
}
