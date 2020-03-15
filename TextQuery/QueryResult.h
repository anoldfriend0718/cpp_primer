#pragma once
#include <string>
#include <memory>
#include <set>
#include <utility>
#include "TextQuery.h"

class QueryResult
{
public:
	QueryResult(std::string word,std::shared_ptr<std::set<TextQuery::line_no>> lineNos,
		std::shared_ptr<std::vector<std::string>> lineTexts):
		m_sought(std::move(word)), m_line_nos(std::move(lineNos)),
	    m_line_texts(std::move(lineTexts)){}

	std::shared_ptr<std::vector<std::string>> get_file() const { return m_line_texts; }
	std::shared_ptr<std::set<TextQuery::line_no>> get_locs() const { return m_line_nos; }
private:
	std::string m_sought;
	std::shared_ptr<std::set<TextQuery::line_no>> m_line_nos;
	std::shared_ptr<std::vector<std::string>> m_line_texts;
};

