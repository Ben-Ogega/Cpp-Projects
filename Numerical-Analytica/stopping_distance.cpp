/*
The Challenge: Write a program that calculates the stopping distance of a vehicle 
based on its speed and the driver's reaction time.
*/

#include <iostream>
#include <cmath> // Needed for the pow() function
#include <iomanip> // Needed for setw() to make clean tables
using namespace std;

double calculateStoppingDistance(double speed, double reactionTime);
const double G = 9.81; // Acceleration due to gravity in meters per second squared, 9.80665 m/s²

int main() {
    double speed; // Speed in miles per hour
    double reactionTime; // Reaction time in seconds

    cout << "Enter the speed of the vehicle (in mph): ";
    cin >> speed;

    cout << "Enter the driver's reaction time (in seconds): ";
    cin >> reactionTime;

    // Convert speed from mph to feet per second
    double speedFPS = speed * 1.467; // 1 mph = 1.467 feet per second

    // Calculate the stopping distance
    double stoppingDistance = calculateStoppingDistance(speed, reactionTime);

    cout << fixed << setprecision(2); // Set precision for output
    cout << "The stopping distance of the vehicle is: " << stoppingDistance << " metres or " 
    << stoppingDistance * 3.28084 << " feet" << endl;

    return 0;
}

double calculateStoppingDistance(double speed, double reactionTime) {
    // Convert speed from mph to feet per second
    double speedFPS = speed * 1.467; // 1 mph = 1.467 feet per second
    double speedMPS = speed * 0.44704; // 1 mph = 0.44704 meters per second

    // Calculate the stopping distance in meters using the formula:
    // Stopping Distance = (Speed in feet per second * Reaction Time) + ((Speed in feet per second)^2 / (2 * Acceleration due to gravity))
    return (speedMPS * reactionTime) + ((speedMPS * speedMPS) / (2 * G)); // 9.81 m/s² is the acceleration due to gravity
}