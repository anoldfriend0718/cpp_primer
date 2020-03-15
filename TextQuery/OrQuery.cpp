#include "OrQuery.h"
#include <memory>

QueryResult OrQuery::eval(const TextQuery& tq) const
{
	const auto left = m_lhs.eval(tq);
	const auto right = m_rhs.eval(tq);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.get_locs()->cbegin(), left.get_locs()->cend());
	ret_lines->insert(right.get_locs()->cbegin(), right.get_locs()->cend());
	return QueryResult(rep(), ret_lines, left.get_file());
}
