#pragma once
#include "BinaryQuery.h"
class OrQuery :
	public BinaryQuery
{
	friend Query operator| (const Query&, const Query&);
	OrQuery(const Query &lhs,const Query &rhs):
		BinaryQuery(lhs,rhs,"|"){}
	QueryResult eval(const TextQuery&) const override;
};

