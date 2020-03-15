#include "NotQuery.h"
#include <memory>

QueryResult NotQuery::eval(const TextQuery& tq) const
{
	const auto result = m_query.eval(tq);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	const auto sz=result.get_file()->size();
	auto begin = result.get_locs()->begin();
	const auto end = result.get_locs()->end();
	for(size_t n=0;n!=sz;++n)
	{
		if(begin==end || *begin!=n)
		{
			ret_lines->insert(n);
		}
		else if(begin!=end)
		{
			++begin;
		}
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}
