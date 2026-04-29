/*
The Challenge: Write a program that compares a Linear Model (y = mx + b) and an Exponential Model (y = P₀ *a^t).
*/

#include <iostream>
#include <cmath>   // Needed for the pow() function
#include <iomanip> // Needed for setw() to make clean tables

using namespace std;

// Function Prototypes (Declaring them at the top)
double linearModel(double initial, double slope, double time);
double exponentialModel(double initial, double growthFactor, double time);

int main() {
    // 1. Setup your constants from a Chapter 1 problem
    double p0 = 100.0;     // Initial population
    double m = 10.0;       // Linear growth (10 units per year)
    double a = 1.10;       // Exponential growth (10% per year)
    int duration = 20;

    cout << "Numerical Comparison: Linear vs Exponential" << endl;
    cout << "Year | Linear | Exponential" << endl;
    cout << "----------------------------" << endl;

    for (int t = 0; t <= duration; t++) {
        cout << setw(4) << t << " | " 
             << setw(6) << linearModel(p0, m, t) << " | " 
             << setw(11) << exponentialModel(p0, a, t) << endl;
    }

    return 0;
}

// Function Definitions (Writing the logic at the bottom)
double linearModel(double initial, double slope, double time) {
    return initial + (slope * time);
}

double exponentialModel(double initial, double growthFactor, double time) {
    return initial * pow(growthFactor, time);
}