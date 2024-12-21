#include <iostream>
#include <random>  // For std::rand() and std::srand()
#include <ctime>    // For std::time()


using namespace std;

int main() {
    // Initialize variables
    int secretNumber;
    int userGuess;
    int attempts = 0;
    const int maxAttempts = 10;

    // Generate a random secret number between 1 and 100
     // Create a random device to seed the random number engine
    std::random_device rd;

    // Use the random device to seed a default random engine
    std::default_random_engine engine(rd());

    // Define a distribution range for random integers between 1 and 100
    std::uniform_int_distribution<int> dist(1, 100);

    // // Generate a random number in the range 1 to 100
    secretNumber = dist(engine);

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Guess the secret number between 1 and 100." << std::endl;

    // Start the game loop
    while (userGuess != secretNumber && attempts < maxAttempts) {
        // Ask the user to make a guess
        std::cout << "Enter your guess: ";
        std::cout << " " << std::endl;
        std::cin >> userGuess;

        // Increase the attempt count
        attempts++;

        // Provide feedback to the user based on the guess
        if (userGuess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
            std::cout << " " << std::endl;
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
            std::cout << " " << std::endl;
            std::cout << "You have " << maxAttempts - attempts << " attempts left." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << std::endl;
            std::cout << " " << std::endl;
            break;  // Exit the loop because the user has guessed correctly
        }
    }

    // If the user reaches the maximum attempts without guessing the correct number
    if (userGuess != secretNumber) {
        std::cout << "Sorry! You've used all your attempts. The secret number was: " << secretNumber << std::endl;
    }

    std::cout << "Thank you for playing the Number Guessing Game!" << std::endl;

    return 0;
}