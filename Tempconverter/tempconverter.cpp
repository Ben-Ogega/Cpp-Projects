#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void fahrenheitConversion(double fahrenheit);
void celsiusConversion(double celsius);
void kelvinConversion(double kelvin);
void showMenu();

int main() {
    int choice;
    double temperature;

    do {
        showMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter temperature in Fahrenheit: ";
                cin >> temperature;
                fahrenheitConversion(temperature);
                break;
            case 2:
                cout << "Enter temperature in Celsius: ";
                cin >> temperature;
                celsiusConversion(temperature);
                break;
            case 3:
                cout << "Enter temperature in Kelvin: ";
                cin >> temperature;
                kelvinConversion(temperature);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 4);

    return 0;
}

void showMenu() {
    cout << "\nTemperature Converter Menu:\n";
    cout << "1. Fahrenheit to Celsius & Kelvin\n";
    cout << "2. Celsius to Fahrenheit & Kelvin\n";
    cout << "3. Kelvin to Celsius & Fahrenheit\n";
    cout << "4. Exit\n";
    cout << "Enter your choice (1-4): ";
}

void fahrenheitConversion(double fahrenheit) {
    const double KELVIN_CONSTANT = 273.15;
    double celsius = (fahrenheit - 32) * 5 / 9;
    double kelvin = celsius + KELVIN_CONSTANT;
    cout << fixed << setprecision(2) << fahrenheit << "°F = " << celsius << "°C = " << kelvin << "K\n";
}

void celsiusConversion(double celsius) {
    const double KELVIN_CONSTANT = 273.15;
    double fahrenheit = (celsius * 9/5) + 32;
    double kelvin = celsius + KELVIN_CONSTANT;
    cout << fixed << setprecision(2) << celsius << "°C = " << fahrenheit << "°F = " << kelvin << "K\n";
}

void kelvinConversion(double kelvin) {
    const double KELVIN_CONSTANT = 273.15;
    double celsius = kelvin - KELVIN_CONSTANT;
    double fahrenheit = (celsius * 9/5) + 32;
    cout << fixed << setprecision(2) << kelvin << "K = " << celsius << "°C = " << fahrenheit << "°F\n";
}
