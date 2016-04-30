/*
 * Rozwiazanie wzorcowe
 * Autor: Aleksander Ciepiela
 */

#include <stack>
#include <iostream>

using namespace std;

class MaxStack {

private:
    stack<long long int> normal_stack;
    stack<long long int> max_stack;

public:
    void push(long long int x) {
        normal_stack.push(x);
        if (max_stack.empty() or max_stack.top() <= x) {
            max_stack.push(x);
        }
    }

    void pop() {
        long long int top = normal_stack.top();
        normal_stack.pop();
        if (top >= max_stack.top()) {
            max_stack.pop();
        }
    }

    long long int get_max() {
        return max_stack.top();
    }
};

int main() {
    int n;
    cin >> n;
    MaxStack stack;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            long long int x;
            cin >> x;
            stack.push(x);
        } else if (type == 2) {
            stack.pop();
        } else {
            cout << stack.get_max() << endl;
        }
    }
    return 0;
}