/*
This is a simple calculator that takes input and prints the results on the console
concepts: input/output, conditionals, and functions
          if/else, switch, loops, basics arithmetic
*/

#include <iostream>
#include <string>

using namespace std;


int main(int argc, const char** argv) {

    double num1;
    double num2;
    char op;

    char continuePlaying;

    // Counter for limiting the number of trials
    int counter = 5;
    int trial = 0;

    // Loop for performing calculations
    while (trial < counter) {
        cout << "Enter first number: ";
        cin >> num1;
        
        cout << "Enter second number: ";
        cin >> num2;
        
        cout << "Choose operator (+, -, *, /): ";
        cin >> op;
    switch (op)
    {
    case '+':
        cout << "The sum  of "<< num1 << " and " << num2 << " is: " << num1 + num2 << endl;
        break;
    case '-':
        cout << "The difference  between "<< num1 << " and " << num2 << " is: " << num1 - num2 << endl;
        break;

    case '*':
        cout << "The product  of "<< num1 << " and " << num2 << " is: " << num1 * num2 << endl;
        break;

    case '/':
        // Handle division by zero
            if (num2 != 0) {
                cout << "The division of " << num1 << " and " << num2 << " is: " << num1 / num2 << endl;

            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
            }
            break;
    default:
        cout << "Invalid operator" << endl;
        break;

    }
    
    // Ask the user if they want to continue
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continuePlaying;

        if (continuePlaying != 'y' && continuePlaying != 'Y') {
            cout << "Exiting program. Goodbye!"<< " \u1F600" << endl;
            break;  // Exit the loop if user doesn't want to continue
        }

        trial++;  // Increment the trial counter
    }
    
    return 0;
}