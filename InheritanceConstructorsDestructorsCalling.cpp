#include <iostream>

using namespace std;

class ClassA
{
public:
    ClassA() { cout << "ClassA constructor\n"; }
    ~ClassA() { cout << "ClassA destructor\n"; }
};

class ClassB : public ClassA
{
public:
    ClassB() { cout << "ClassB constructor\n"; }
    ~ClassB() { cout << "ClassB destructor\n"; }
};

class ClassC : public ClassB
{
public:
    ClassC() { cout << "ClassC constructor\n"; }
    ~ClassC() { cout << "ClassC destructor\n"; }
};

int main()
{
    ClassC* p = new ClassC;
    delete p;

    cin.get();
}