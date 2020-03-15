
#include <sstream>
#include "TextQuery.h"
#include "QueryResult.h"
#include <algorithm>
using namespace std;
TextQuery::TextQuery(std::ifstream& is):file(new vector<string>)
{
	string text;
	while(getline(is,text))
	{
		file->push_back(text);
		const auto no = file->size() - 1;
		std::replace(text.begin(), text.end(), ',', ' ');
		std::replace(text.begin(), text.end(), '.', ' ');
		istringstream line(text);
		string word;
		while(line>>word)
		{
			
			auto& lineNos = wm[word];
			if(!lineNos)
			{
				lineNos.reset(new set<line_no>);
			}
			lineNos->insert(no);
		}
		
	}
}

QueryResult TextQuery::query(const std::string& word) const
{
	static shared_ptr<set<line_no>> no_data(new set<line_no>);
	const auto loc = wm.find(word);
	if(loc!=wm.cend())
	{
		return QueryResult(word, loc->second, file);
	}
	return QueryResult(word, no_data, file);
}
