#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// function to convert
// Hexadecimal to Binary Number
// choice 2

string decToBinary(int n) {

    string bin = "";
    while (n > 0) {
        // checking the mod 
        int bit = n % 2;
        bin.push_back('0' + bit);
        n /= 2;
    }

    // reverse the string 
    reverse(bin.begin(), bin.end());
    return bin;
}


// funtion to convert decimal to binary
// choice 6
void HexToBin(string hexdec)
{
    //Skips "0x" if present at beggining of Hex string
    size_t i = (hexdec[1] == 'x' || hexdec[1] == 'X') ? 2 : 0;

    while (hexdec[i]) {

        switch (hexdec[i]) {
        case '0':
            cout << "0000";
            break;
        case '1':
            cout << "0001";
            break;
        case '2':
            cout << "0010";
            break;
        case '3':
            cout << "0011";
            break;
        case '4':
            cout << "0100";
            break;
        case '5':
            cout << "0101";
            break;
        case '6':
            cout << "0110";
            break;
        case '7':
            cout << "0111";
            break;
        case '8':
            cout << "1000";
            break;
        case '9':
            cout << "1001";
            break;
        case 'A':
        case 'a':
            cout << "1010";
            break;
        case 'B':
        case 'b':
            cout << "1011";
            break;
        case 'C':
        case 'c':
            cout << "1100";
            break;
        case 'D':
        case 'd':
            cout << "1101";
            break;
        case 'E':
        case 'e':
            cout << "1110";
            break;
        case 'F':
        case 'f':
            cout << "1111";
            break;
        case '.':
            cout << ".";
            break;
        default:
            cout << "\nInvalid hexadecimal digit "
                << hexdec[i];
        }
        i++;
    }
}

// driver code
int main()
{
    // get the decimal number
    int n;
    cout << "Enter the decimal number: ";
    cin >> n;
    // Convert the decimal number to binary
    cout << "\nbinary number : ";
    cout << decToBinary(n) << endl;

 // Get the Hexadecimal number
    char hexdec[100];
    cout << "Enter hexdecimal number: ";
    cin >> hexdec;

    // Convert HexaDecimal to Binary
    cout << "\nBinary value is : ";
    HexToBin(hexdec);

    return 0;
}