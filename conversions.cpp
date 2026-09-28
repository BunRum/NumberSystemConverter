//
// Created by av53503 on 9/8/2026.
//
#include "conversions.h"

#include <algorithm>
#include <format>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <variant>

// 1
int BinaryToDecimal(const std::string &binary) {
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
std::string DecimalToBinary(const int input) {
    int n = input;
    if (n == 0) {
        return "0";
    }

    std::string bin = "";
    while (n > 0) {
        // checking the mod
        const int bit = n % 2;
        bin.push_back('0' + bit);
        n /= 2;
    }

    // reverse the string
    std::reverse(bin.begin(), bin.end());
    return bin;
}


// 3
std::string DecimalToHexadecimal(const int input) {
    // These characters are used to represent values 0 through 15 in hexadecimal.
    static constexpr char hexDigits[] = "0123456789ABCDEF";

    std::string inHex;

    // Divide this value by 16 until there is nothing left to convert.
    int quotient = input;

    do {
        // The remainder is the next hexadecimal digit, from right to left.
        const int remainder = quotient % 16;
        quotient /= 16;

        // Use the remainder as an index to find its hexadecimal character.
        inHex.push_back(hexDigits[remainder]);

    } while (quotient != 0);

    // The remainders were collected backwards, so reverse them for the final result.
    std::ranges::reverse(inHex);

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
        else 
        {
            decimal += (hex[i] - '0') * pow(16, hex.length() - i - 1);
        }

    }

    return decimal;
}

// 5
std::string BinaryToHexadecimal(const std::string &input) {
    // Each hexadecimal digit represents four binary bits.
    static constexpr char hexDigits[] = "0123456789ABCDEF";
    std::string hexadecimal;

    // Ignore leading zeroes so the result does not start with unnecessary zeroes.
    std::size_t firstBit = 0;
    while (firstBit < input.size() && input[firstBit] == '0') {
        ++firstBit;
    }

    // If every bit was zero, the hexadecimal value is simply zero.
    if (firstBit == input.size()) {
        return "0";
    }

    // The first group may have fewer than four bits; every later group has four.
    const std::size_t bitCount = input.size() - firstBit;
    const std::size_t firstGroupSize = bitCount % 4 == 0 ? 4 : bitCount % 4;

    // Read one binary group at a time and turn it into one hexadecimal digit.
    for (std::size_t groupStart = firstBit, groupSize = firstGroupSize;
         groupStart < input.size();
         groupStart += groupSize, groupSize = 4) {
        int value = 0;
        for (std::size_t bit = 0; bit < groupSize; ++bit) {
            const char digit = input[groupStart + bit];

            // Binary input can only contain a 0 or 1.
            if (digit != '0' && digit != '1') {
                return "Invalid binary digit " + std::string(1, digit);
            }

            // Shift the current value left and add this bit.
            value = value * 2 + (digit - '0');
        }

        // Use the binary group's decimal value as an index into the hex digits.
        hexadecimal.push_back(hexDigits[value]);
    }

    return hexadecimal;
}

// 6
std::string HexadecimalToBinary(const std::string &input) {
    std::string binary;

    // Skip a leading "0x" or "0X", if present.
    const std::size_t start = input.size() >= 2 && input[0] == '0' &&
                                      (input[1] == 'x' || input[1] == 'X')
                                  ? 2
                                  : 0;

    for (std::size_t i = start; i < input.size(); ++i) {
        switch (input[i]) {
            case '0': binary += "0000"; break;
            case '1': binary += "0001"; break;
            case '2': binary += "0010"; break;
            case '3': binary += "0011"; break;
            case '4': binary += "0100"; break;
            case '5': binary += "0101"; break;
            case '6': binary += "0110"; break;
            case '7': binary += "0111"; break;
            case '8': binary += "1000"; break;
            case '9': binary += "1001"; break;
            case 'A':
            case 'a': binary += "1010"; break;
            case 'B':
            case 'b': binary += "1011"; break;
            case 'C':
            case 'c': binary += "1100"; break;
            case 'D':
            case 'd': binary += "1101"; break;
            case 'E':
            case 'e': binary += "1110"; break;
            case 'F':
            case 'f': binary += "1111"; break;
            case '.': binary += '.'; break;
            default: return "Invalid hexadecimal digit " + std::string(1, input[i]);
        }
    }

    return binary;
}
