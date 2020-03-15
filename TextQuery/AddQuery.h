#pragma once
#include "BinaryQuery.h"
class AddQuery :
	public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AddQuery(const Query& lhs, const Query& rhs):BinaryQuery(lhs,rhs,"&"){}
	QueryResult eval(const TextQuery&) const override;
};

