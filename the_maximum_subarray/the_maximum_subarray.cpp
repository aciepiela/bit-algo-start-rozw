/*
 * Rozwiazanie wzorcowe
 * Zlozonosc: O(n)
 * Autor: Aleksander Ciepiela
 */

#include <iostream>

using namespace std;

int max_contiguous_sub_array(int *arr, int n) {
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];
        max_sum = max(curr_sum, max_sum);
        if (curr_sum < 0) {
            curr_sum = 0;
        }
    }
    return max_sum;
}

int max_non_contiguous_sub_array(int *arr, int n) {
    bool has_non_negatives = false;
    int max_negative = INT_MIN;
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            has_non_negatives = true;
            max_sum += arr[i];
        }
        else {
            max_negative = max(max_negative, arr[i]);
        }
    }
    return has_non_negatives ? max_sum : max_negative;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        cout << max_contiguous_sub_array(arr, n) << " " << max_non_contiguous_sub_array(arr, n) << endl;
    }
    return 0;
}
