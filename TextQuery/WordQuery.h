#pragma once
#include <utility>
#include "Query_base.h"
#include "QueryResult.h"

class WordQuery:public Query_base
{
	friend class Query;
	WordQuery(std::string word):query_word(std::move(word)){}
	QueryResult eval(const TextQuery& tq) const override { return tq.query(query_word); }
	std::string rep() const override { return query_word; }
	std::string query_word;
};
