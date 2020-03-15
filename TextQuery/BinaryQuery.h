#pragma once
#include "Query_base.h"
#include "Query.h"
#include <utility>

class BinaryQuery:public Query_base
{
protected:
	BinaryQuery(const Query & lhs,const Query &rhs,std::string opSym):
		m_lhs(lhs),m_rhs(rhs), m_opSym(std::move(opSym)){}
	std::string rep() const override { return "(" + m_lhs.rep() + " " + m_opSym + " " + m_rhs.rep() + ") "; }

	Query m_lhs;
	Query m_rhs;
	std::string m_opSym;
};

