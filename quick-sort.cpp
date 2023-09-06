/*
    partition array with the last element.
    group A < pivot < group B
    recoursively sort the group A and group B

    Time Complexity:
    Best Case:  Ω (N log (N))
    Average Case:  θ ( N log (N))
    Worst Case: O(N^2)
    Auxiliary Space: O(1), if we don’t consider the recursive stack space. 
    If we consider the recursive stack space then, in the worst case quicksort could make O(N).
*/
#include<iostream>
#include<vector>
#include<algorithm>
using std::vector, std::cout;

int pivot(vector<int> &v, int lo, int hi)
{
    int j = lo - 1;
    for (int i=lo; i<hi; i++)
    {
        if (v[i] < v[hi])
        {
            j++;
            std::swap(v[i], v[j]);
        }        
    }
    std::swap(v[hi], v[j+1]);
    return j+1;
}

void quickSort(vector<int> &v, int lo, int hi)
{
    if (lo < hi)
    {
        int p = pivot(v, lo, hi);
        quickSort(v, lo, p-1);
        quickSort(v, p+1, hi);
    }
}
void printVector(vector<int> &v)
{
    for (auto e : v)
    {
        cout << e << " ";
    }    
    cout << '\n';
}

int main()
{
    vector<int> v = {52, 3, 17, 89, 70, 8, 2, 7, 10};
    printVector(v);
    quickSort(v, 0, v.size()-1);
    printVector(v);
    return 0;
}