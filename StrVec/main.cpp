// StrVec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include "StrVec.h"

int main()
{
    StrVec vect;
	vect.push_back("v1");
	vect.push_back("v2");
	vect.push_back("v3");
	vect.push_back("v4");
	vect.push_back("v5");
	vect.push_back("v6");
	std::cout << "size: " << vect.size() << std::endl;
	std::cout << "capacity: " << vect.capacity() << std::endl;
	std::for_each(vect.begin(), vect.end(), [](const std::string& str) {std::cout << str << " "; });
}