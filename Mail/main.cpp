// Mail.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Message.h"
#include "Folder.h"
#include <algorithm>

int main()
{
    Message message("email1");
    const auto folder1=std::make_shared<Folder>("folder1");
    const auto folder2 = std::make_shared<Folder>("folder2");
	message.save(folder1);
	message.save(folder2);
	auto folder_titles = message.get_folder_titles();
	std::for_each(folder_titles.begin(), folder_titles.end(),
		[](const std::string& title) {std::cout<<title<<" "; });
    std::cout << std::endl;
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
