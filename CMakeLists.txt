cmake_minimum_required(VERSION 3.5)

project(guess_the_number)

add_executable( guess_the_number
	main.cpp
	check_value.h
	check_value.cpp
	random_value.h
	random_value.cpp
	score_printing.h
	score_printing.cpp
)

set_target_properties(guess_the_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)


 
