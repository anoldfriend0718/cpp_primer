#pragma once
#include <ostream>
#include <memory>
#include "Query.h"
#include "NotQuery.h"
#include "AddQuery.h"
#include "OrQuery.h"

inline std::ostream& operator<<(std::ostream& os,const Query& query)
{
	os << query.rep();
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const QueryResult& query)
{
	for(auto num:*(query.get_locs()))
	{
		os << "\t(line " << num + 1 << ") " << *(query.get_file()->begin() + num) << std::endl;
	}
	return os;
}

inline Query operator~(const Query& operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

inline Query operator&(const Query &lhs,const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AddQuery(lhs,rhs));
}

inline Query operator| (const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
