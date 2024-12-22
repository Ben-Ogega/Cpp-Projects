/**
 * @brief Constructor with parameters to initialize a BankAccount object.
 * @param name The name of the account holder.
 * @param number The account number.
 * @param initialDeposit The initial deposit amount.
 */

/**
 * @brief Default constructor to initialize a BankAccount object with default values.
 */

/**
 * @brief Deposits a specified amount into the bank account.
 * @param amount The amount to be deposited.
 * @throws invalid_argument if the deposit amount is not positive.
 */

/**
 * @brief Withdraws a specified amount from the bank account.
 * @param amount The amount to be withdrawn.
 * @throws invalid_argument if the withdrawal amount is not positive.
 * @throws runtime_error if the withdrawal amount exceeds the current balance.
 */

/**
 * @brief Checks and displays the current balance of the bank account.
 */

/**
 * @brief Saves the account information to a file.
 * @throws runtime_error if the file cannot be opened for saving.
 */

/**
 * @brief Loads the account information from a file based on the account number.
 * @param accountNum The account number to be loaded.
 * @throws runtime_error if the account is not found or the file cannot be opened for loading.
 */


/*
    Author: Benard Ogega
    Date: 22/12/2024
*/

#include "BankAccount.h"

using namespace std;

// Constructor with parameters
BankAccount::BankAccount(const string &name, int number, double initialDeposit) {
    accountHolder = name;
    accountNumber = number;
    balance = initialDeposit;

    // Save account info to file upon creation
    saveToFile();
}

// Default constructor
BankAccount::BankAccount() {
    accountHolder = "Unknown";
    accountNumber = 0;
    balance = 0.0;
}

// Deposit function
void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        throw invalid_argument("Deposit amount must be positive.");
    }
    balance += amount;
    cout << "Deposited: " << amount << ". Current Balance: " << balance << endl;
}

// Withdraw function
void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw invalid_argument("Withdrawal amount must be positive.");
    }
    if (amount > balance) {
        throw runtime_error("Insufficient balance.");
    }
    balance -= amount;
    cout << "Withdrew: " << amount << ". Current Balance: " << balance << endl;
}

// Check balance function
void BankAccount::checkBalance() const {
    cout << "Account Holder: " << accountHolder << "\nAccount Number: " << accountNumber
         << "\nCurrent Balance: " << balance << endl;
}

// Save account information to a file
void BankAccount::saveToFile() const {
    ofstream file("accounts.txt", ios::app);  // Open file in append mode
    if (file.is_open()) {
        file << accountNumber << " " << accountHolder << " " << balance << endl;
    } else {
        throw runtime_error("Unable to open file for saving.");
    }
    file.close();
}

// Load account information from file (given account number)
void BankAccount::loadFromFile(int accountNum) {
    ifstream file("accounts.txt");
    if (file.is_open()) {
        while (file >> accountNumber >> accountHolder >> balance) {
            if (accountNumber == accountNum) {
                cout << "Account loaded: \n";
                checkBalance();
                return;
            }
        }
        throw runtime_error("Account not found.");
    } else {
        throw runtime_error("Unable to open file for loading.");
    }
    file.close();
}

// Destructor (No specific cleanup in this case)
BankAccount::~BankAccount() {
    cout << "Bank Account for " << accountHolder << " has been closed.\n";
}
