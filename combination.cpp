// method 1: fix elemets and recur
// method 2: which is mainly based on Pascal’s Identity, i.e. ncr = n-1cr + n-1cr-1
// reference: https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

#include<iostream>
#include<vector>

using std::cout, std::vector;

class Combination
{
private:
    // temporary to store combination
    vector<int> m_data;
    // parameters: array, start, end, current index, size k
    void combinate_until(vector<int>, int, int, int, int);
    // parameters: array, size_k, current index of data, index of array
    void combinate_pascals_iden(vector<int>, int, int, int);
public:
    void print_combination(vector<int> , int);
};

void Combination::combinate_until(
    vector<int> arr, int start, int end, int idx, int size_k) {
    if (idx == size_k) {
        for (auto i : m_data) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i=start; i<=end && end-i+1 >= size_k-idx; i++) {
        m_data[idx] = arr[i];
        combinate_until(arr, i+1, end, idx+1, size_k);
    }
}

void Combination::combinate_pascals_iden(vector<int> arr, int size_k, int idx, int idx_arr) {
    if (idx == size_k) {
        for (auto i : m_data) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    if (idx_arr >= arr.size()) return;
    m_data[idx] = arr[idx_arr];
    // include current index
    combinate_pascals_iden(arr, size_k, idx+1, idx_arr+1);
    // exlcude current index
    combinate_pascals_iden(arr, size_k, idx, idx_arr+1);
}

void Combination::print_combination(vector<int> arr, int size_k) {
    m_data = vector<int>(size_k);
    cout << "method 1:\n";
    combinate_until(arr, 0, arr.size()-1, 0, size_k);
    m_data = vector<int>(size_k);
    cout << "\nmethod 2:\n";
    combinate_pascals_iden(arr, size_k, 0, 0);
    cout << '\n';
}

int main() {
    Combination c;
    c.print_combination(vector<int>{1,2,3,4,5}, 3);
    return 0;
}