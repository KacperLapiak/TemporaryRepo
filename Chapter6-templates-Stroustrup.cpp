#include <iostream>
#include <algorithm>

using namespace std;

template <typename T, int n>
class vector
{
private:
    T* v_ = nullptr;
    int size_ = 0;

public:
    explicit vector()
    {
        if (n < 0)
            throw string{"Negative_size"};
        v_ = new T[n];
        size_ = n;
    }
    ~vector()
    {
        delete[] v_;
    }
    int size() const { return size_; }
    T& operator[](int i) 
    {
        if (i < 0 || i >= size_)
            throw string{"out_of_range"};
        return v_[i]; 
    }
    const T& operator[](int i) const { return v_[i]; }

    T* begin()
    {
        return size_ ? &v_[0] : nullptr;
    }
    T* end()
    {
        return size_ ? &v_[size_] : nullptr;
    }
};

template <typename T>
double sum(T& c)
{
    double sum = 0;
    for (auto x : c)
        sum += x;
    return sum;
}

template <typename T>
class functor
{
private:
    T val_ = 0;

public:
    functor(T val) : val_(val)
    {

    }

    bool operator()(const T& val) const 
    {
        return val_ < val;
    }
};

int main()
{
    vector<int, 10> v;
    for (int i = 0; i < v.size(); i++)
        v[i] = i;

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << "\n";

    for (int x : v)
        cout << x << " ";

    cout << "\n" << sum(v) << "\n";

    functor<int> f = 10;
    cout << f(100) << "\n";

    cout << count_if(v.begin(), v.end(), [&](int a){ return a > 5; });

    cin.get();
}