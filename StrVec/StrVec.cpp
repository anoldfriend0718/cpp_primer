#include "StrVec.h"
#include <iostream>

std::allocator<std::string> StrVec:: alloc;

StrVec::StrVec(const StrVec& vec)
{
	copy_from(vec);
}

StrVec& StrVec::copy_from(const StrVec& vec)
{
	const auto data = alloc_n_copy(vec.begin(), vec.end());
	elements = data.first;
	first_free = data.second;
	cap = data.second;
	return *this;
}

StrVec& StrVec::operator=(const StrVec& vec)
{
	if (this == &vec)
		return *this;
	free();
	copy_from(vec);
	return *this;
	
}

StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const std::string& element)
{
	chk_n_alloc();
	alloc.construct(first_free++, element);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* begin, const std::string* end)
{
	auto data=alloc.allocate(end - begin);
	auto data_end=std::uninitialized_copy(begin, end, data);
	return std::make_pair(data, data_end);
}

void StrVec::free()
{
	if(elements)
	{
		for(auto p=first_free;p==elements;)
		{
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	const auto newcapacity = size() ? 2 * size() : 1;
	const auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i=0;i!=size();++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
	std::cout << "capacity reallocated" << std::endl;
}
