#include <iostream>
#include <vector>

using namespace std;

int max_contiguous_sub_array(vector<int> &arr) {
    // Your code
    return 0;
}

int max_non_contiguous_sub_array(vector<int> &arr) {
    // Your code
    return 0;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        cout << max_contiguous_sub_array(arr) << " " << max_non_contiguous_sub_array(arr) << endl;
    }
    return 0;
}
