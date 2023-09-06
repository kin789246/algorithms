/* 
    compare two elements if v[i] > v[i+1] swap v[i], v[i+1]
    then compare previous element with v[i] to the head.
    Time Complexity: O(N^2)
    Auxiliary Space: O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using std::vector, std::cout;

void insertion_sort(vector<int> &v)
{
    int n = v.size();
    int i;
    int key;
    int j;
    for (i=1; i<n; i++)
    {
        key = v[i];
        j = i-1;
        while(j>=0 && v[j]>key)
        {
            v[j+1] = v[j];
            j -= 1;
        }
        v[j+1] = key;
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
    insertion_sort(v);
    print_vector(v);
    return 0;
}