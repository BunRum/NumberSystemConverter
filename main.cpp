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


int main() {
    cout << "====================================" << endl;
    cout << "      NUMBER SYSTEM CONVERTER       " << endl;
    cout << "====================================" << endl;

    cout << "1. Binary to Decimal" << endl;
    cout << "2. Decimal to Binary" << endl;
    cout << "3. Decimal to Hexadecimal" << endl;
    cout << "4. Hexadecimal to Decimal" << endl;
    cout << "5. Binary to Hexadecimal" << endl;
    cout << "6. Hexadecimal to Binary" << endl;
    cout << "7. Exit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    string inputString;
    int decimalInput;

    cout << "Enter your input: ";


    switch (choice) {
        case 1:
            cin >> decimalInput;
            cout << BinaryToDecimal(decimalInput) << endl;
            break;
        case 2:
            cin >> decimalInput;
            cout << DecimalToBinary(decimalInput) << endl;
            break;
        case 3:
            cin >> decimalInput;
            cout << DecimalToHexadecimal(decimalInput) << endl;
            break;
        case 4:
            cin >> inputString;
            cout << HexadecimalToDecimal(inputString) << endl;
            break;
        case 5:
            cin >> decimalInput;
            cout << BinaryToHexadecimal(decimalInput) << endl;
            break;
        case 6:
            cin >> inputString;
            cout << HexadecimalToBinary(inputString) << endl;
            break;
        default:
            cin >> inputString;
            cout << inputString << endl;
            break;
    }

    return 0;
}
