#include <iostream>

using namespace std;

class StackTable
{
private:
    int top_ = -1;
    int stack_[5]{};

public:
    int Size() 
    { 
        return top_ + 1; 
    }
    bool Empty()
    {
        if (top_ == -1) return true;
        else return false;
    }
    void Push(int element)
    {
        if (top_ == size(stack_) - 1)
        {
            cout << "stack is full" << endl;
        }
        else
        {
            top_++;
            stack_[top_] = element;
        }
    }
    int Pop()
    {
        if (top_ == -1)
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        else
        {
            top_--;
            return stack_[top_ + 1];
        }
    }
};

int main()
{
    StackTable stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    stack.Push(6); // overflow error

    cout << stack.Pop() << "\n";
    cout << stack.Pop() << "\n";
    cout << stack.Pop() << "\n";
    cout << stack.Pop() << "\n";
    cout << stack.Pop() << "\n";
    cout << stack.Pop() << "\n"; // underflow error

    cin.get();
}