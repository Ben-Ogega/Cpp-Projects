/*
This is a simple calculator that takes input and prints the results on the console
concepts: input/output, conditionals, and functions
          if/else, switch, loops, basics arithmetic
*/

#include <iostream>

using namespace std;


int main(int argc, const char** argv) {

    int a; 
    int b;

    cout <<"Enter first number: ";
    cin >> a;
    cout <<"Enter second number: ";
    cin >> b;

    cout << "The sum  of "<< a << " and " << b << " is: " << a + b << endl;
    cout << "The product  of "<< a << " and " << b << " is: " << a * b << endl;
    cout << "The division  of "<< a << " and " << b << " is: " << float(a) / float(b) << endl;
    cout << "The difference  between "<< a << " and " << b << " is: " << a - b << endl;

    
    return 0;
}