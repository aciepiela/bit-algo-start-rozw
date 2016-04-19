#include <iostream>
#include <stack>

using namespace std;

class MaxStack {

private:
    // Class variables here

public:
    void push(long long int x) {
        // Your code
    }

    void pop() {
        // Your code
    }

    long long int get_max() {
        // Your code
        return 0;
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
