#include <iostream>
#include <cstdlib>
#include <ctime>

#include "random_value.h"

int value_generator(int max_value)
{

	//const int max_value = 100;

	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % max_value;

	//std::cout << random_value << std::endl;

	return random_value;
};
