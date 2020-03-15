#pragma once
#include <string>
#include <utility>
#include "QueryResult.h"
#include "Query_base.h"
#include "WordQuery.h"

class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(std::string word):m_query(new WordQuery(std::move(word))){}
	QueryResult eval(const TextQuery& tq) const { return m_query->eval(tq); }
	std::string rep() const { return m_query->rep(); }
private:
	Query(std::shared_ptr<Query_base> query) :m_query(std::move(query)){}
	std::shared_ptr<Query_base> m_query;
};

