#pragma once
#include <memory>
#include "Message.h"
#include <iostream>

class Folder
{
public:
	Folder(std::string title):m_title(std::move(title)) {}
	~Folder() 
	{
		std::cout << "about to destruct Folder: " << m_title << std::endl;
	}
	void add_message(const Message* message);
	void remove_message(const Message&);
	std::string get_title() const { return m_title; }
private:
	std::set<const Message*> m_messages;
	std::string m_title;
	
};

