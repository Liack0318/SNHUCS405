// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <cstring>
#include <string> // Needed for std::string and std::getline

int main()
{
	std::cout << "Buffer Overflow Example" << std::endl;

	// TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
	//  even though it is a constant and the compiler buffer overflow checks are on.
	//  You need to modify this method to prevent buffer overflow without changing the account_number
	//  variable, and its position in the declaration. It must always be directly before the variable used for input.
	//  You must notify the user if they entered too much data.

	const std::string account_number = "CharlieBrown42";
	char user_input[20];

	std::string temp_input;
	char try_again = 'y';

	while (try_again == 'y' || try_again == 'Y') {
		std::cout << "Enter a value: ";
		std::getline(std::cin, temp_input); // safe input

		if (temp_input.length() >= sizeof(user_input)) {
			std::cerr << "ERROR: Input too long! Only 19 characters allowed." << std::endl;
			std::memset(user_input, 0, sizeof(user_input)); // clear buffer
		}
		else {
			strncpy_s(user_input, sizeof(user_input), temp_input.c_str(), _TRUNCATE); // safe copy
			std::cout << "You entered: " << user_input << std::endl;
		}

		std::cout << "Account Number = " << account_number << std::endl;

		std::cout << "\nTry again? (y/n): ";
		std::getline(std::cin, temp_input);
		if (!temp_input.empty()) {
			try_again = temp_input[0];
		}
		else {
			try_again = 'n';
		}
	}

	std::cout << "\nGoodbye!" << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
