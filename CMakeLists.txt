cmake_minimum_required(VERSION 3.5)

project(guess_the_number)

add_executable( guess_the_number
	main.cpp
	check_value.h
	check_value.cpp
	random_value.h
	random_value.cpp
)

#add_executable( 03_homework
#	random_value.h
#	random_value.cpp
#)

#add_executable( 03_homework
#	check_value.h
#	check_value.cpp
#)

#add_executable(
#	high_scores
#	high_scores.cpp
#)

#add_executable(
#	argument
#	argument.cpp
#)

set_target_properties(guess_the_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)


 
