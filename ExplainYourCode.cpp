// ExplainYourCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>

// This is a functor that overrides the function call () operator 
struct F
{
	void operator() (int x)
	{
		// do something
		std::cout << x;
	}
};

int main()
{
	std::vector<int> v;
	
	// more code, not shown here.
	for (auto i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	 /*
	 The third parameter of the for_each algorithem can be any callable object. 
	 The callable object is applied to every dereferenced iterator between v.begin() and v.end()
	 You could have a inline lambda if you wanted [](int x) -> void {std::cout << x; }
	 */

	// The prototype 
	/*
	template<class InputIterator, class Function>
	Function for_each(InputIterator first, InputIterator last, Function f)
	{
		for (; first != last; ++first) {
		f(*first);
		return f;
	}

	Templated generates code at compile time. 
	F() makes instance of the functor. It must match the signature required by for_each, one parameter.
	otherwise you will get like 'no matching overloaded function found'

	functor destroyed when for_each finishes

	*/
	std::for_each(v.begin(), v.end(), F());

	std::cin.get();

    return 0;
}

