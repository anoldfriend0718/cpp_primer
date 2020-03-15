#include "AddQuery.h"
#include <memory>
#include <set>
#include <algorithm>
#include <iterator>

QueryResult AddQuery::eval(const TextQuery& tq) const
{
	const auto left = m_lhs.eval(tq);
	const auto right = m_rhs.eval(tq);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	const auto left_locs = left.get_locs();
	const auto right_locs = right.get_locs();
	std::set_intersection(left_locs->begin(), left_locs->end(), 
		right_locs->begin(), right_locs->end(),
		std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
	
}
