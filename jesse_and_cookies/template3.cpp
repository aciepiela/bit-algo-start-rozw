#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &sweetness, int minimum_sweetness) {
    // Your code
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sweetness(n);
    for (int i = 0; i < n; i++) {
        cin >> sweetness[i];
    }
    cout << solve(sweetness, n, k) << endl;;
    return 0;
}
