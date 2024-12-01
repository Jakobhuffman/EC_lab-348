/**
Jakob Huffman
2975499
This project takes a user string and that is a numeric value
and it will verify if the value is a valid input. 
 */


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double extractNumeric(const std::string& str) {
    int len = str.length(); // Using std::string::length() to get the size
    bool has_decimal = false, has_sign = false;
    bool valid = false;
    std::string numeric_part;

    for (int i = 0; i < len; ++i) {
        char c = str[i];

        if (c >= '0' && c <= '9') {
            numeric_part += c;
            valid = true;
        } 
        else if (c == '.' && !has_decimal) {
            numeric_part += c;
            has_decimal = true;
        } 
        else if ((c == '+' || c == '-') && i == 0 && !has_sign) {
            numeric_part += c;
            has_sign = true;
        } 
        else {
            return -999999.99;
        }
    }

    if (numeric_part == "+" || numeric_part == "-" || numeric_part == "." || !valid) { // Handle cases like "+" or "-" or "." which are invalid
        return -999999.99;
    }

    try {
        return std::stod(numeric_part); // Convert to double
    } catch (...) {
        return -999999.99; 
    }
}

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}