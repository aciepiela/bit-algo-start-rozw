#include <iostream>
#include <vector>
#include <queue>

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
    cout << solve(sweetness, k) << endl;;
    return 0;
}
