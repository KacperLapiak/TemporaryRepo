#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Return the containter that contains iterators  
// on indicated element(v) that are contain in container(c).
template <typename C, typename V>
vector<typename C::iterator> countOccurance(C& c, V v)
{
	vector<typename C::iterator> vec;
	for (auto itr = c.begin(); itr != c.end(); itr++)
		if (*itr == v) 
			vec.push_back(itr);
	return vec;
}

int main()
{
	string str = "alice";
	vector<string::iterator> viter = countOccurance(str, 'a');

	for (auto x : viter)
		cout << *x << " ";

	static char* ch = new char[1024 * 1024]{'x'};

	cout << endl << "str: " << &str;
	cout << endl << "heap: " << &ch;

	cin.get();
}