/*
    time complexity: O(log n)
    auxiliary space: O(1)
    x | 0  1  2  3  4  5  6  7  8
  f(x)| 0  1  1  2  3  5  8 13 21
               __f(6)[8]_______  (n_1)
              /                \  
             /   +- f(4)        \
            /                    \
          f(5)[5]____            f(4)[11] 
         /           \ +- f(3)    /      \  +- f(2)
        /             \          /        \
       f(4)[3]        f(3)[7]  f(3)[10]   f(2)[12]
      /     \ +- f(1) /         /
    f(3)[2] f(2)[4] f(2)[6]   f(2)[9]
    /
   f(2)[1]
*/

#include<iostream>
#include<vector>
#include<algorithm>

using std::vector, std::cout;
void printVector(const vector<int> &v) 
{
    cout << "arrar [ ";
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i];
        if ( i < v.size()-1)
            cout << ", ";
    }
    cout << " ]\n";
}
class solution {
    public:
    int f_search(vector<int> &v, int x)
    {
        int n = v.size();
        int fib_n = 1; 
        int fib_n_1 = 1;
        int fib_n_2 = 0;
        while (fib_n < n)
        {
            fib_n_2 = fib_n_1;
            fib_n_1 = fib_n;
            fib_n = fib_n_1 + fib_n_2;
        }
        // fib_n_1 <= n;
        int offset = -1;
        while (fib_n > 1)
        {
            // make sure the idx is valid
            int idx = std::min(offset+fib_n_2, n-1);
            if (v[idx] == x)
            {
                return idx;
            }
            if (v[idx] > x)
            {
                fib_n = fib_n_2;
                fib_n_1 = fib_n_1 - fib_n_2;
                fib_n_2 = fib_n - fib_n_1;
            }
            if (v[idx] < x)
            {
                fib_n = fib_n_1;
                fib_n_1 = fib_n_2;
                fib_n_2 = fib_n - fib_n_1;
                offset = idx;
            }
            // compare the last element
            if (fib_n_1 && v[offset+1] == x)
            {
                return offset + 1;
            }
        }
        return -1;
    }
    int fibonacci(int n)
    {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fibonacci(n-1) + fibonacci(n-2);
    }
};

int main()
{
    solution s;
    vector<int> a{ 2, 5, 17, 26, 38, 42, 59, 60, 65 ,72 ,87, 93 };
    int x = 58;
    printVector(a);
    cout << "find index of array of " << x << " = " << s.f_search(a, x) << "\n";
    return 0;
}