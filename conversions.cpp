//
// Created by av53503 on 9/8/2026.
//
#include "conversions.h"

#include <format>
#include <iostream>
#include <cmath>

// 1
int BinaryToDecimal(const int input) {
    int quotient = input;
    int inDecimal = 0;
    int step = 0;

    do {
        const int remainder = quotient % 10;
        quotient /= 10;
        inDecimal += remainder * static_cast<int>(pow(2, step));
        step++;
    } while (quotient != 0);

    return inDecimal;
}

// 2
int DecimalToBinary(const int input) {
    int quotient = input;
    int inBinary = 0;
    int step = 0;

    do {
        const int remainder = quotient % 2;
        quotient /= 2;
        inBinary += remainder * static_cast<int>(pow(10, step));
        step++;
    } while (quotient != 0);

    return inBinary;
}

// 3
std::string DecimalToHexadecimal(const int input) {
    std::string inHex = std::format("{:X}", input);
    return inHex;
}

// 4
std::string HexadecimalToDecimal(const std::string &input) {
    return "";
}

// 5
std::string BinaryToHexadecimal(const int input) {
    // converts it from Binary to Decimal
    const int toDecimal = BinaryToDecimal(input);

    // convert from decimal to hexadecimal
    std::string toHexadecimalString = DecimalToHexadecimal(toDecimal);

    return toHexadecimalString;
}

// 6
std::string HexadecimalToBinary(const std::string &input) {
    return "";
}
