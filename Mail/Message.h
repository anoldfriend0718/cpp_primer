#pragma once
#include <string>
#include <memory>
#include <set>
#include <vector>

class Folder;

class Message
{
public:
	Message(std::string text):m_message(std::move(text)) {}
	~Message();
	Message(const Message&);
	Message& operator=(const Message&);
	void save(const std::shared_ptr<Folder>&);
	void remove(std::shared_ptr<Folder>);
	std::vector<std::string> get_folder_titles();
private:
	std::string m_message;
	std::set<std::shared_ptr<Folder>> m_folders;
	void add_to_folders(const Message&) const ;
	void remove_from_folders();
	
};

