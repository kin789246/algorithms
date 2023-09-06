/*
    Time Complexity: O(N^2)
    Auxiliary Space: O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using std::vector, std::cout;

void bubble_sort(vector<int> &v)
{
    int n = v.size();
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (v[i] < v[j])
            {
                std::swap(v[i], v[j]);
            }
        }
    }
}
void print_vector(vector<int> &v)
{
    for (auto e : v)
    {
        cout << e << " ";
    }    
    cout << '\n';
}

int main()
{
    vector<int> v = {52, 3, 17, 89, 2, 7, 10};
    print_vector(v);
    bubble_sort(v);
    print_vector(v);
    return 0;
}