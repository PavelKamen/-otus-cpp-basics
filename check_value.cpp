#include <iostream>

#include "check_value.h"

int choise_logic(int target_value) {

	//const int target_value = 54;
	int current_value = 0;
	//bool not_win = true;
	int try_counter=0;
	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;

		if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
			++try_counter;
		}
		else if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
			++try_counter;
		}
		else {
			std::cout << "you win!" << std::endl;
			++try_counter;
			break;
		}

	} while(true);
	
	return try_counter;
}
