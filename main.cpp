#include <iostream>
#include <string>
#include <fstream>

#include "random_value.h"
#include "check_value.h"

 

int main(int argc, char** argv) {

	int max_value = 100;

	if (argc >= 2) {
	//	std::cout << "We have one more argument!" << std::endl;
	//	std::cout << "argv[1] = " << argv[1] << std::endl;

		std::string arg1_value{ argv[1] };
		if (arg1_value == "-max") {
			//std::cout << "-parameter argument was detected!" << std::endl;

			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:
			int parameter_value = 0;
			if (argc < 3) {
				std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
				return -1;
			}
			// We need to parse the string to the int value
			parameter_value = std::stoi(argv[2]);
			//std::cout << "The '-max' value = " << parameter_value << std::endl;
			max_value = parameter_value;
		}
	}
	 
	//std::cout << "Max parameter now = " << max_value << std::endl;
	 
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string name;  
	std::cin >> name;
	
	// Реализация функций генерации random_value.cpp
	const int true_value = value_generator(max_value);
	
	// Цикл проверки значения на соответствие
	int trycounter = choise_logic(true_value);
	std::cout << " " << "trycounter " << trycounter; 
	
       
		const std::string high_scores_filename = "high_scores.txt";
		std::ifstream in_file{high_scores_filename};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		std::cout << "High scores table:" << std::endl;

		std::string username;
		int high_score = 0;
		while (true) {
			// Read the username first
			in_file >> username;
			// Read the high score next
			in_file >> high_score;
			// Ignore the end of line symbol
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}

			// Print the information to the screen
			std::cout << username << '\t' << high_score << std::endl;
		}
 
		
	
	// запись резульатов в таблицу рекордов
	//write_to_record_table(name, trycounter);
	
	
	//TODO hiscore and result_rable

	return 0;

}
