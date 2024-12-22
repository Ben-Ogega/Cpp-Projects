#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

class BankAccount {
private:
    std::string accountHolder;
    int accountNumber;
    double balance;

public:
    // Constructors
    BankAccount(const std::string &name, int number, double initialDeposit = 0);
    BankAccount();

    // Member Functions
    void deposit(double amount);
    void withdraw(double amount);
    void checkBalance() const;
    void saveToFile() const;
    void loadFromFile(int accountNum);

    // Destructor
    ~BankAccount();
};

#endif
