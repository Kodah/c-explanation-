// This is a functor that overrides the function call () operator 
struct F {
	void operator() (int x)	{
		// do something
		std::cout << x;
	}
};
int main() {
	std::vector<int> v;
	// more code, not shown here.

	std::for_each(v.begin(), v.end(), F());
	/*
	The third parameter of the for_each algorithm can be function pointer or a move constructible function object.
	Every iterator in the vector is dereferenced and passed to the function as a parameter 
	You could have a inline lambda if you wanted [](int x) -> void {std::cout << x; }
	It must match the signature required by for_each, so a Unary function
	otherwise you will get an error like 'no matching overloaded function found'.
	 */

	// The prototype possible implementation
	template<class InputIterator, class Function>
	Function for_each(InputIterator first, InputIterator last, Function f)
	{
		for (; first != last; ++first) {
		f(*first);
		return f;
	}
	/*
	For_each is a function template, the compiler generates code at compile time.
	F() makes instance of the functor which gets destroyed when for_each finishes. 
	You could make an instance of F f; and use that without the brackets if you wanted
	to access the struct again for any reason.
	std::for_each(v.begin(), v.end(), f);
	*/
	
	// random notes R-value? deep copy? -.-
}

