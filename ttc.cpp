/**
 * @file ttc.cpp
 * @brief A simple console-based Tic-Tac-Toe game implementation
 *
 * This program implements a Tic-Tac-Toe game where a human player competes against
 * a computer opponent. The game is played on a 3x3 grid where players take turns
 * marking spaces with 'X' (player) and 'O' (computer).
 *
 * Functions:
 * @function drawBoard - Displays the current state of the game board
 * @function checkWinner - Checks if either player has won the game
 * @function checkTie - Checks if the game has ended in a tie
 * @function playerMove - Handles the human player's move
 * @function computerMove - Handles the computer's move
 *
 * Game Rules:
 * - Player uses 'X' marker
 * - Computer uses 'O' marker 
 * - Players take alternating turns
 * - First to get 3 in a row (horizontal, vertical, or diagonal) wins
 * - Game ends in tie if no winner and board is full
 *
 * Implementation Details:
 * - Uses 1D char array to represent 3x3 board
 * - Implements random number generation using modern C++ (std::mt19937)
 * - Input validation for player moves
 * - Automatic win/tie detection
 *
 * @author Benard N. Ogega
 * @date 22/12/2024
 */
// This is a simple Tic-Tac-Toe game
// The game is played by two players and covers concepts in 2D arrays, loops, conditions, vectors, and functions.


#include <iostream>
#include <ctime>   // for time()
#include <random>  // for std::mt19937
#include <cstdlib> // for system(), srand() and rand()
// system() is a C function, so we don't need using declaration

// Function prototypes

void drawBoard(char* spaces);
bool checkWinner(char* spaces, char player, char computer);
bool checkTie(char* spaces);
void playerMove(char* spaces, char player);
void computerMove(char* spaces, char computer);


int main()

{
    
     // Create a random device to provide randomness
    std::random_device rd;
    
    // Seed the random number generator with the random device
    std::mt19937 gen(rd());  // Mersenne Twister engine
    
    // Alternatively, you can fall back to `time(0)` if `random_device` is not available
    // std::mt19937 gen(static_cast<unsigned int>(time(0))); // Old fallback, less ideal
    
    // Create a uniform distribution for integers between 1 and 100
    std::uniform_int_distribution<> dis(0, 9);
    
    // Generate a random number
    int number = dis(gen);
    
    // Print the random number
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while(running){
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
    }
    std::cout << "Thanks for playing!\n";

    return 0;
}


void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}


void playerMove(char *spaces, char player){
    int number;


    do{
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' '){
           spaces[number] = player;
           break; 
        }
    }
    while(!number > 0 || !number < 8);
}

void computerMove(char *spaces, char computer){
    int number;
    while(true){
        // number--;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}


bool checkWinner(char *spaces, char player, char computer){

    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }

    else{
        return false;
    }

    return true;
}
bool checkTie(char *spaces){

    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout << "IT'S A TIE!\n";
    return true;
}
