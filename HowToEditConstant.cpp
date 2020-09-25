#include <iostream>

using namespace std;

int main()
{
	const char str[] = "Ala ma kota.";
	int addr = (int)&str[2];
	*(char*)addr = 'x';

	cout << str;

	cin.get();
}