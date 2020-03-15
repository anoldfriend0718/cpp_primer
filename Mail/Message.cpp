#include "Message.h"
#include "Folder.h"
#include <iostream>

Message::~Message()
{
	std::cout << "about to destruct Message: "<<m_message<< std::endl;
	remove_from_folders();
	std::cout << "Message destruct: " << m_message << std::endl;
}

Message::Message(const Message& message):m_message(message.m_message),m_folders(message.m_folders)
{
	add_to_folders(message);
}

Message& Message::operator=(const Message& message)
{
	if (this == &message)
	{
		return *this;
	}
	remove_from_folders();
	m_message = message.m_message;
	m_folders = message.m_folders;
	add_to_folders(message);
	return *this;
}

void Message::save(const std::shared_ptr<Folder>& folder)
{
	m_folders.insert(folder);
	folder->add_message(this);
}

void Message::remove(std::shared_ptr<Folder> folder)
{
	const auto it=std::find_if(m_folders.begin(), m_folders.end(), 
	                           [&folder](const std::shared_ptr<Folder>& element) {return element.get() == folder.get(); });
	if (it == m_folders.end()) return;
	m_folders.erase(it);
	folder->remove_message(*this);
}

std::vector<std::string> Message::get_folder_titles()
{
	std::vector<std::string> vect;
	for (const auto& f : m_folders)
	{
		vect.push_back(f->get_title());
	}
	return vect;
}

void Message::add_to_folders(const Message& message) const
{
	for(const auto& f: message.m_folders)
	{
		if(f) f->add_message(this);
	}
}

void Message::remove_from_folders()
{
	for(const auto& f:m_folders)
	{
		if (f)
		{
			f->remove_message(*this);
		}
	}
}
