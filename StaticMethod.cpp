#include <iostream>

using namespace std;

class ExampleClass
{
private:
    static int val;

public:
    static void ExampleMethod() { val++; }
    static int ShowValue() { return val; }

};
int ExampleClass::val = 0;

int main()
{
    ExampleClass::ExampleMethod();
    ExampleClass::ExampleMethod();
    cout << ExampleClass::ShowValue() << endl;

    ExampleClass obj;
    obj.ExampleMethod();
    cout << ExampleClass::ShowValue();

    cin.get();
}