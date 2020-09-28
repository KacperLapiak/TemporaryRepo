#include <iostream>

using namespace std;

class ClassA
{
public:
    void methodA()
    {
        cout << "Alice has a cat." << endl;
    }
};

class ClassB : public virtual ClassA { };
class ClassC : public virtual ClassA { };
class ClassD : public ClassB, public ClassC { };

int main()
{
    ClassD obj;
    obj.methodA();

    cin.get();
}