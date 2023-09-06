/*
    split the array half to only one element which is sorted.
    merge the splited arrays and sort recursively.

    Time Complexity: O(N log(N))
    Auxiliary Space: O(N)
*/
#include<iostream>
#include<vector>
using std::vector, std::cout;

void printVector(vector<int>&);
void merge(vector<int> &v, int left, int middle, int right)
{
    vector<int> l(v.begin()+left, v.begin()+middle+1);
    vector<int> r(v.begin()+middle+1, v.begin()+right+1);
    //printVector(l);
    //printVector(r);
    int il = 0;
    int ir = 0;
    int iv = left;
    while (il<l.size() && ir<r.size())
    {
        if (l[il] < r[ir])
        {
            v[iv] = l[il];
            il++;
        }
        else
        {
            v[iv] = r[ir];
            ir++;
        }
        iv++;
    }
    while (il<l.size())
    {
        v[iv] = l[il];
        iv++;
        il++;
    }
    while (ir<r.size())
    {
        v[iv] = r[ir];
        iv++;
        ir++;
    }
}

void mergeSort(vector<int> &v, int left, int right)
{
    if (left < right)
    {
        int middle = left+(right-left)/2;
        mergeSort(v, left, middle);    
        mergeSort(v, middle+1, right);
        merge(v, left, middle, right);
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
    vector<int> v = {52, 3, 17, 89, 8, 2, 7, 10};
    printVector(v);
    mergeSort(v, 0, v.size()-1);
    printVector(v);
    return 0;
}