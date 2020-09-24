#include <iostream>
#include <algorithm>

using namespace std;

template <typename T, int n>
class vector
{
private:
    T* v_;
    size_t size_;

public:
    explicit vector()
    {
        if (n < 0)
            throw invalid_argument{ "negative_value" };
        v_ = new T[n];
        size_ = n;
    }
    ~vector() { delete[] v_; }
    size_t size() { return size_; }
    T& operator[] (size_t i) 
    { 
        if (i < 0 || i >= size())
            throw out_of_range{ "out_of_range" };

        return v_[i]; 
    }
    T* begin() { return &v_[0]; }
    T* end() { return &v_[size_]; }
};

int main()
{
    vector<int, 10> v;

    for (int i = 0; i < v.size(); i++)
        v[i] = i;

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    for (int x : v)
        cout << x << " ";
    cout << endl;

    try 
    {
        cout << v[10];
    }
    catch (out_of_range &err)
    {
        cout << err.what();
    }

    int val = 4;
    int cntr = count_if(v.begin(), v.end(), [&val](int a) { return a > val; });
    cout << endl << cntr << endl;

    reverse(v.begin(), v.end());
    for (int x : v)
        cout << x << " ";
    cout << endl;

    cin.get();
}