/*
 Autor: Aleksander Ciepiela
 */

#include <algorithm>
#include <iostream>

using namespace std;

class Point {
private:
    Point *rep;
    int rank;

public:

    Point() {
        this->rep = this;
    }

    Point *find_rep() {
        Point *rep = this;
        while (rep->get_rep() != rep) {
            rep->set_rep(rep->get_rep()->get_rep());
            rep = rep->get_rep();
        }
        return rep;
    }

    Point *get_rep() {
        return this->rep;
    }

    void set_rep(Point *rep) {
        this->rep = rep;
    }

    void union_with(Point *other) {
        Point *rep1 = find_rep();
        Point *rep2 = other->find_rep();
        if (rep1 == rep2) {
            return;
        }
        if (rep1->get_rank() > rep2->get_rank()) {
            rep2->set_rep(rep1);
        }
        else {
            rep1->set_rep(rep2);
        }
        if (rep1->get_rank() == rep2->get_rank()) {
            rep2->set_rank(rep2->get_rank() + 1);
        }
    }

    int get_rank() {
        return this->rank;
    }

    void set_rank(int rank) {
        this->rank = rank;
    }
};

const int DY[] = {1, 0, 0, -1};
const int DX[] = {0, 1, -1, 0};
const int NUMBER_OF_POSSIBLE_MOVES = 4;

class Board {
private:
    int dim1;
    int dim2;
    Point ***points;
    int number_of_isles;

public:

    Board(int x, int y) {
        this->number_of_isles = 0;
        this->dim1 = x;
        this->dim2 = y;
        this->points = new Point **[x];
        for (int i = 0; i < x; i++) {
            this->points[i] = new Point *[y];
            for (int j = 0; j < y; j++) {
                this->points[i][j] = NULL;
            }
        }
    }

    ~Board(){
        for(int i = 0; i < dim1; i++){
            for(int j = 0; j < dim2; j++){
                delete this->points[i][j];
            }
            delete[] this->points[i];
        }
        delete[] this->points;
    }

    int get_number_of_isles() {
        return this->number_of_isles;
    }


    void add_point(int x, int y) {
        Point *new_point = new Point();
        this->points[x][y] = new_point;
        this->number_of_isles++;
        for (int i = 0; i < NUMBER_OF_POSSIBLE_MOVES; i++) {
            int newX = x + DX[i];
            int newY = y + DY[i];
            if (is_move_possible(newX, newY) && this->points[newX][newY]->find_rep() != new_point->find_rep()) {
                new_point->union_with(this->points[newX][newY]);
                this->number_of_isles--;
            }
        }
    }

private:
    bool is_move_possible(int x, int y) {
        return is_within_bounds(x, y) && this->points[x][y] != NULL;
    }

    bool is_within_bounds(int x, int y) {
        return x >= 0 && x < this->dim1 && y >= 0 && y < this->dim2;
    }
};

class Pair {
private:
    int left;
    int right;

public:

    int get_left() {
        return this->left;
    }

    void set_left(int left) {
        this->left = left;
    }

    int get_right() {
        return this->right;
    }

    void set_right(int right) {
        this->right = right;
    }
};

int main() {
    int dim1, dim2;
    cin >> dim1 >> dim2;
    Pair order[dim1 * dim2];
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            int a;
            cin >> a;
            order[a - 1].set_left(i);
            order[a - 1].set_right(j);
        }
    }
    Board *board = new Board(dim1, dim2);
    for (int i = 0; i < dim1 * dim2; i++) {
        Pair pair = order[i];
        board->add_point(pair.get_left(), pair.get_right());
        cout << board->get_number_of_isles() << " ";
    }
    delete board;
    return 0;
}
