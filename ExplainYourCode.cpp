// ExplainYourCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>


struct f
{
	void operator() (int n)
	{
		//do something
		std::cout << n;
		
	}
};

int main()
{
	std::vector<int> v;
	
	// more code, not shown here.
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	f funct;

	std::for_each(v.begin(), v.end(), funct);

	std::cin.get();

    return 0;
}

