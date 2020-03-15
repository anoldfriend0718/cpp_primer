#include "Folder.h"

void Folder::add_message(const Message* message)
{
	m_messages.insert(message);
}

void Folder::remove_message(const Message& message)
{
	const auto it = std::find(m_messages.begin(), m_messages.end(), &message);
	if (it == m_messages.end()) return;
	m_messages.erase(it);
}
