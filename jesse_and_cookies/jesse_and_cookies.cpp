/*
 * Rozwiazanie wzorcowe z wykorzystaniem kolejki priorytetowej
 * Zlozonosc O(nlog(n))
 * Autor: Aleksander Ciepiela
 * */

#include <iostream>
#include <queue>

using namespace std;

bool compare(int x, int y) {
    return x - y > 0;
}

int solve(int sweetness[], int n, int minimum_sweetness) {
    priority_queue<int, vector<int>, function<bool(int, int)>> queue(compare);
    for (int i = 0; i < n; i++) {
        queue.push(sweetness[i]);
    }
    int operations = 0;
    while (queue.top() < minimum_sweetness) {
        if (queue.size() < 2) {
            return -1;
        }
        int least_sweet = queue.top();
        queue.pop();
        int second_least_sweet = queue.top();
        queue.pop();
        queue.push(least_sweet + 2 * second_least_sweet);
        operations++;
    }
    return operations;
}

int main() {
    int n, k;
    cin >> n >> k;
    int sweetness[n];
    for (int i = 0; i < n; i++) {
        cin >> sweetness[i];
    }
    cout << solve(sweetness, n, k);
    return 0;
}
