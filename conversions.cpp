//
// Created by av53503 on 9/8/2026.
//
#include "conversions.h"

#include <format>
#include <iostream>
#include <cmath>

// 1
int BinaryToDecimal(const int input) {
    std::string binary = std::to_string(input);

    int decimal = 0; //decimal values

    for (long i = binary.length() - 1; i >= 0; i--) //Starts from the right (last bit) then goes left (first bit).  binary.length() - 1 initalizes to last bit and moves left
    {
        if (binary[i] == '1') //checks to see if index has a 1 bit
        {
            decimal = (pow(2,binary.length() - i - 1)) + decimal; //pow does 2^n where n is position of bit.  binary.length() -i - 1 makes rightmost bit to have power 0 and leftmost to have power 7
        }

    }

    return decimal;
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
int HexadecimalToDecimal(const std::string &hex) {

    int decimal = 0; //decimal value

    for (int i = 0; i < hex.length(); i++)
    {
        if (hex[i] == 'A' || hex[i] == 'a')
        {
            decimal += 10 * pow(16, hex.length() - i -1);
        }
        else if (hex[i] == 'B' || hex[i] == 'b')
        {
            decimal += 11 * pow(16, hex.length() - i -1);
        }
        else if (hex[i] == 'C' || hex[i] == 'c')
        {
            decimal += 12 * pow(16, hex.length() - i - 1);
        }
        else if (hex[i] == 'D' || hex[i] == 'd')
        {
            decimal += 13 * pow(16, hex.length() - i -1);
        }
        else if (hex[i] == 'E' || hex[i] == 'e')
        {
            decimal += 14 * pow(16, hex.length() - i -1);
        }
        else if (hex[i] == 'F' || hex[i] == 'f')
        {
            decimal += 15 * pow(16, hex.length() - i -1);
        }
        else if (hex[i] != '0')
        {
            decimal += (hex[i] - '0') * pow(16, hex.length() - i - 1);
        }

    }

    return decimal;
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
int HexadecimalToBinary(const std::string &input) {
    const int toDecimal = HexadecimalToDecimal(input);
    const int toBinary = DecimalToBinary(toDecimal);
    return toBinary;
}
