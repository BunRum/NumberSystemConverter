

#include <iostream>

using namespace std;

void analyzeBinary(string binary);
void hexadecimalToDecimal(string hex);


int main()
{
    string t;
    cin >> t;
    hexadecimalToDecimal(t);

    
    return 0;
}





void hexadecimalToDecimal(string hex)
{
    int decimal = 0; //decimal value
    cout << hex.length() << endl;
    
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
    cout << decimal;
}


void analyzeBinary(string binary)
{
    int decimal = 0; //decimal values
    int numberOfOnes = 0; //the amount of digits in binary
    
    
    if (binary.length() != 8) //checks to see if input is 8 characters
    {
        cout << "Error: Invalid binary number must be 8 bits.\n\n";
        return;
    }
    
    for (int i = 0; i < binary.length(); i++) //checks if there are only 0 and 1 
    {
        if (binary[i] != '0' && binary[i] != '1')
        {
            cout << "Error: Invalid binary number can only contain 0 and 1.\n\n";
            return;
        }
    }
    
    
    for (long i = binary.length() - 1; i >= 0; i--) //Starts from the right (last bit) then goes left (first bit).  binary.length() - 1 initalizes to last bit and moves left
    {
        if (binary[i] == '1') //checks to see if index has a 1 bit
        {
            decimal = (pow(2,binary.length() - i - 1)) + decimal; //pow does 2^n where n is position of bit.  binary.length() -i - 1 makes rightmost bit to have power 0 and leftmost to have power 7
            numberOfOnes++; //counter for amount of 1 bits
        }
        
    }
    
    
    if (decimal % 2 == 0) //checks to see if decimal value is even or odd and displays decimal value and number of 1 bits
    {
        cout << "Decimal value: " << decimal << "\n";
        cout << "The number of 1 bits: " << numberOfOnes << "\n";
        cout << "The value is even.\n\n";
    }
    else
    {
        cout << "Decimal value: " << decimal << "\n";
        cout << "The number of 1 bits: " << numberOfOnes << "\n";
        cout << "The value is odd.\n\n";
    }
    
    
}
