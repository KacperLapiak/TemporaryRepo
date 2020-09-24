#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Entry
{
	int key_ = 0;
	string str_ = "";

	bool operator < (Entry x)
	{
		return this->key_ < x.key_;
	}
};

int main()
{
	Entry e;
	vector<Entry> v;

	for (int i = 9; i >= 0; i--)
	{
		e.key_ = i;
		e.str_ = "dane " + to_string(i);
		v.push_back(e);
	}

	for (Entry x : v)
		cout << x.key_ << " | " << x.str_ << endl;

	sort(v.begin(), v.end());
	cout << endl;

	for (Entry x : v)
		cout << x.key_ << " | " << x.str_ << endl;

	cin.get();
}