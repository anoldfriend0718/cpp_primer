#include <iostream>
#include <fstream>
#include "TextQuery.h"
#include "Query.h"
#include "QueryOperators.h"

int main()
{
	std::ifstream infile("contents.txt");
	const TextQuery text_query(infile);
	const Query query = Query("fiery") & Query("bird") | ~Query("it");
	std::cout << "Executing Query for: "<<query<<std::endl;
	std::cout << query.eval(text_query) << std::endl;
	return 0;
}
