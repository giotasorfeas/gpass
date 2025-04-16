#include <iostream>
#include <string>
using namespace std;

struct Password{
    string password;
    int length;
    bool hasLower = false;
    bool hasUpper = false;
    bool hasDigit = false;
    bool hasSpecial = false;
};

void evaluate(Password& password){
    int score = 0;
    if (password.length >= 8) ++score;
    if (password.hasLower) ++score;
    if (password.hasUpper) ++score;
    if (password.hasDigit) ++score;
    if (password.hasSpecial) ++score;
    if (password.length >= 12) ++score; // bonus

    string strength;
    string bar = "[";
    string colorStart, colorEnd = "\033[0m";

    if (score <= 2) {
        strength = "Weak";
        colorStart = "\033[1;31m"; // Red
    } else if (score <= 4) {
        strength = "Moderate";
        colorStart = "\033[1;33m"; // Yellow
    } else {
        strength = "Strong";
        colorStart = "\033[1;32m"; // Green
    }

    for (int i = 0; i < 6; ++i) {
        if (i < score) bar += "█";
        else bar += "░";
    }
    bar += "]";

    cout << "\nPassword Strength Score.........: " << score << " / 6" << endl;
    cout << "Result..........................: " << colorStart << bar << " " << strength << colorEnd << endl;
}

int main(void){
    Password password;
    cout << "\nEnter your password: ";
    cin >> password.password;
    cout << "\nYou entered: " << password.password << '\n';
    password.length = password.password.length();

    for (char c : password.password) {
        if (islower(c)) {
            password.hasLower = true;
        } else if (isupper(c)) {
            password.hasUpper = true;
        } else if (isdigit(c)) {
            password.hasDigit = true;
        } else {
            password.hasSpecial = true;
        }
    }

    cout << "\nPassword Analysis:\n";
    cout << "1. Length.......................: " << password.length << '\n';
    cout << "2. Contains lowercase...........: " << (password.hasLower ? "Yes" : "No") << '\n';
    cout << "3. Contains uppercase...........: " << (password.hasUpper ? "Yes" : "No") << '\n';
    cout << "4. Contains digits..............: " << (password.hasDigit ? "Yes" : "No") << '\n';
    cout << "5. Contains special characters..: " << (password.hasSpecial ? "Yes" : "No") << '\n';

    evaluate(password);

    return 0;
}