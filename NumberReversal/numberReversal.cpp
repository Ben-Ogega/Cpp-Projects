/*
This is a simple program to reverse a number. The program takes an integer input from the user and reverses it.
i.e 1234 -> 4321
1000 -> 1
1001 -> 1001
4321 -> 1234
*/

#include <iostream>
#include <string>

using namespace std;

int reverseNumber(int number);

int main() {

    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Reversed number: " << reverseNumber(number) << endl;
    return 0;
}


int reverseNumber(int number) {
    int reversedNumber = 0;
    while (number > 0) {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }
    return reversedNumber;
}