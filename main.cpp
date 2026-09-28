#include <cassert>
#include <iostream>

#include "conversions.h"
using namespace std;

/*
Name: Adam Ventura
Course: CMPR 154 - Fall 2026
Date: September 3, 2026
Assignment: Group Project # 1 - Number System Converter
Collaboration:
 Adam Ventura
 Muhammad Jafri
 Punam Thapa
*/

static void displayChoices() {
    cout << "====================================\n"
        "      NUMBER SYSTEM CONVERTER       \n"
        "====================================\n";
    cout << "1. Binary to Decimal" << endl;
    cout << "2. Decimal to Binary" << endl;
    cout << "3. Decimal to Hexadecimal" << endl;
    cout << "4. Hexadecimal to Decimal" << endl;
    cout << "5. Binary to Hexadecimal" << endl;
    cout << "6. Hexadecimal to Binary" << endl;
    cout << "7. Exit" << endl;
}

/*
 * This function helps me display the conversion results with decorations
*/
static void displayConversion(const string &from, const string &input,
                              const string &to, const string &output) {
    cout << "\n====================================\n"
            "          CONVERSION RESULT         \n"
            "====================================\n"
            << from << ": " << input << '\n'
            << to << ": " << output << '\n'
            << "====================================\n\n";


    std::cin.ignore();

    cout << "Press ENTER to continue...";
    cin.get();
}

static void runStressTests() {
    constexpr int maxTestValue = 100000;

    for (int number = 1; number <= maxTestValue; number++) {
        const string binary = DecimalToBinary(number);
        const string hexadecimal = DecimalToHexadecimal(number);

        assert(BinaryToDecimal(binary) == number);
        assert(HexadecimalToDecimal(hexadecimal) == number);
        assert(BinaryToHexadecimal(binary) == hexadecimal);
        assert(BinaryToDecimal(HexadecimalToBinary(hexadecimal)) == number);
    }

    cout << std::format("STRESS TESTS: {} values checked", maxTestValue) << endl;
    cout << "ALL STRESS TESTS PASSED" << endl << endl;
}

int main() {
    runStressTests();

    while (true) {
        displayChoices();

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(std::numeric_limits<int>::max(), '\n');

        if (choice == 7) {
            cout << "Exiting..." << endl;
            break;
        }

        if (choice < 1 || choice > 6) {
            cout << "Invalid choice." << endl;
            continue;
        }

        string input;
        cout << "Enter your input: ";
        cin >> input;

        switch (choice) {
            case 1:
                displayConversion("Binary", input, "Decimal",
                                  to_string(BinaryToDecimal(input)));
                break;
            case 2:
                displayConversion("Decimal", input, "Binary",
                                  DecimalToBinary(stoi(input)));
                break;
            case 3:
                displayConversion("Decimal", input, "Hexadecimal",
                                  DecimalToHexadecimal(stoi(input)));
                break;
            case 4:
                displayConversion("Hexadecimal", input, "Decimal",
                                  to_string(HexadecimalToDecimal(input)));
                break;
            case 5:
                displayConversion("Binary", input, "Hexadecimal",
                                  BinaryToHexadecimal(input));
                break;
            case 6:
                displayConversion("Hexadecimal", input, "Binary",
                                  HexadecimalToBinary(input));
                break;
            default:
                break;
        }
    }

    return 0;
}
