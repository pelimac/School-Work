/* Brandon McFarlane
CISC 2200
DecimalToBinary.cpp
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to convert decimal to binary using a vector
void decimalToBinary(int decimal) {
    vector<int> binary; // Create a vector to store the binary equivalent
    while (decimal > 0) {
        binary.push_back(decimal % 2); // Add the remainder of decimal divided by 2 to the binary vector
        decimal /= 2; // Divide decimal by 2
    }
    cout << "Binary equivalent: ";
    for (int i = binary.size() - 1; i >= 0; i--) {
        cout << binary[i]; // Print each binary digit
    }
    cout << endl;
}

int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal; // Get decimal number from user
    decimalToBinary(decimal); // Convert decimal to binary and print the result
    return 0;
}