#pragma once
#include "Query.h"

class NotQuery:public Query_base
{
	friend Query operator~(const Query& query);
	NotQuery(const Query& query):m_query(query){}
	std::string rep() const
	{
		return "~(" + m_query.rep() + ")";
	}
	QueryResult eval(const TextQuery&) const override;
	Query m_query;
};

