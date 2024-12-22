#include <iostream>
#include "BankAccount.h"
#include <stdexcept>
#include <limits>

using namespace std;

void showMenu() {
    cout << "\nBank Account System\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Check Balance\n";
    cout << "5. Load Account\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    BankAccount *account = nullptr;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        try {
            if (cin.fail()) {
                throw invalid_argument("Invalid input. Please enter a number between 1 and 6.");
            }

            switch (choice) {
                case 1: {
                    string name;
                    int number;
                    double deposit;

                    cout << "Enter account holder's name: ";
                    cin.ignore(); // Ignore leftover newline from previous input
                    getline(cin, name);

                    cout << "Enter account number: ";
                    cin >> number;

                    cout << "Enter initial deposit amount: ";
                    cin >> deposit;

                    account = new BankAccount(name, number, deposit);
                    cout << "Account created successfully!\n";
                    break;
                }

                case 2: {
                    if (account == nullptr) {
                        throw runtime_error("No account created yet. Please create an account first.");
                    }

                    double amount;
                    cout << "Enter deposit amount: ";
                    cin >> amount;

                    account->deposit(amount);
                    break;
                }

                case 3: {
                    if (account == nullptr) {
                        throw runtime_error("No account created yet. Please create an account first.");
                    }

                    double amount;
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;

                    account->withdraw(amount);
                    break;
                }

                case 4: {
                    if (account == nullptr) {
                        throw runtime_error("No account created yet. Please create an account first.");
                    }

                    account->checkBalance();
                    break;
                }

                case 5: {
                    int accNum;
                    cout << "Enter account number to load: ";
                    cin >> accNum;

                    account = new BankAccount();  // Reset account object
                    account->loadFromFile(accNum);
                    break;
                }

                case 6:
                    if (account != nullptr) {
                        delete account;
                    }
                    cout << "Exiting program.\n";
                    return 0;

                default:
                    throw invalid_argument("Invalid choice. Please choose between 1 and 6.");
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }

        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
