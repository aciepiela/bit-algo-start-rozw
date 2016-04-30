/*
 * Rozwiazanie wzorcowe
 * Kazda operacja dziala w czasie O(log(n)), gdzie n to przedzial na jakim operuje drzewo (b - e)
 * Autor: Aleksander Ciepiela
*/

#include <algorithm>
#include <iostream>

using namespace std;

class CountingTree {

private:
    int size;
    long *values;

public:
    CountingTree(int numberOfElements) {
        int size = 1;
        while (size < numberOfElements) {
            size *= 2;
        }
        this->size = size;
        int realSize = 2 * size - 1;
        this->values = new long[realSize];
        for (int i = 0; i < realSize; i++) {
            this->values[i] = 0;
        }
    }

    ~CountingTree(){
        delete[] this->values;
    }

private:
    int left(int index) {
        return 2 * index + 1;
    }

    int right(int index) {
        return 2 * index + 2;
    }

    int parent(int index) {
        return (index - 1) / 2;
    }

    bool isLeftChild(int index) {
        return index == left(parent(index));
    }

    bool isRightChild(int index) {
        return index == right(parent(index));
    }

public:

    void add(int index, int value) {
        int lb = 0;
        int rb = this->size - 1;
        int p = 0;
        this->values[p] += value;
        while (lb != rb) {
            int middle = (lb + rb) / 2;
            if (index <= middle) {
                rb = middle;
                p = left(p);
            }
            else {
                lb = middle + 1;
                p = right(p);
            }
            this->values[p] += value;
        }
    }

    long count(int begin, int end) {
        int lp = this->size - 1 + begin;
        int rp = this->size - 1 + end;
        long count = this->values[lp];
        if (lp != rp) {
            count += this->values[rp];
        }
        while (parent(lp) != parent(rp)) {
            if (isLeftChild(lp)) {
                count += this->values[right(parent(lp))];
            }
            if (isRightChild(rp)) {
                count += this->values[left(parent(rp))];
            }
            lp = parent(lp);
            rp = parent(rp);
        }
        return count;
    }
};

int main() {
    int lowerBound, upperBound, numberOfQueries;
    cin >> lowerBound >> upperBound >> numberOfQueries;
    CountingTree tree(upperBound - lowerBound + 1);
    for (int i = 0; i < numberOfQueries; i++) {
        string command;
        cin >> command;
        if (command == "add") {
            int lb, value;
            cin >> lb >> value;
            tree.add(lb - lowerBound, value);
        }
        else {
            int lb, rb;
            cin >> lb >> rb;
            lb -= lowerBound;
            rb -= lowerBound;
            cout << tree.count(lb, rb) << endl;
        }
    }
}

