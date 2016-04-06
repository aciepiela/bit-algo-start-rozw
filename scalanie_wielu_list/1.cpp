/*
 Autor: Aleksander Ciepiela
 Zlozonosc rozwiazania: O(m lg n)
 m - ilosc elementow we wszystkich listach
 n - ilosc list

 Wersja 'almost C only' (i/o oraz new/delete z C++ dla wygody)

 Uwaga: ogolna implementacja kolejki priorytetowej nie zawiera sprawdzania poprawnosci operacji (np. czy wykonywana jest
 operacja extract_min na pustej kolejce)
 */

#include <iostream>

using namespace std;

struct node {
    int value;
    node *next;
};

struct priority_queue {
    node **values;
    int size;
};

int parent(int index) {
    return (index - 1) / 2;
}

int left(int index) {
    return 2 * index + 1;
}

int right(int index) {
    return 2 * index + 2;
}

void swap(node **arr, int p1, int p2) {
    node *tmp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = tmp;
}

priority_queue *init(int max_number_of_elements) {
    priority_queue *queue = new priority_queue;
    queue->values = new node *[max_number_of_elements];
    queue->size = 0;
    return queue;
}


void bubble_up(priority_queue *queue, int p) {
    while (p != 0 and queue->values[p]->value < queue->values[parent(p)]->value) {
        swap(queue->values, p, parent(p));
        p = parent(p);
    }
}

void insert(priority_queue *queue, node *value) {
    queue->values[queue->size] = value;
    bubble_up(queue, queue->size);
    queue->size++;
}

void bubble_down(priority_queue *queue, int p) {
    int min = p;
    if (left(p) < queue->size and queue->values[left(p)]->value < queue->values[min]->value) {
        min = left(p);
    }
    if (right(p) < queue->size and queue->values[right(p)]->value < queue->values[min]->value) {
        min = right(p);
    }
    if (min != p) {
        swap(queue->values, min, p);
        bubble_down(queue, min);
    }
}

node *extract_min(priority_queue *queue) {
    int last = queue->size - 1;
    swap(queue->values, 0, last);
    queue->size--;
    bubble_down(queue, 0);
    return queue->values[last];
}

bool is_queue_empty(priority_queue *queue) {
    return queue->size == 0;
}

int main() {
    int n;
    cin >> n; // ilosc list
    priority_queue *queue = init(n);
    for (int i = 0; i < n; i++) {
        int k; // ilosc elementow w liscie
        cin >> k;
        node *p = new node;
        cin >> p->value;
        p->next = NULL;
        insert(queue, p); //wrzucam do kolejki wskaznik na pierwszy element listy
        k--;
        while (k > 0) { // wczytuje pozostale elementy listy, bez wrzucania do kolejki
            node *p1 = new node;
            p1->next = NULL;
            cin >> p1->value;
            p->next = p1;
            p = p1;
            k--;
        }
    }
    while (!is_queue_empty(queue)) {    // dopoki kolejka nie jest pusta wyciagam wskaznik z najmniejszym elementem
        node *min = extract_min(queue); // wypisuje go, a do kolejki wrzucam jego nastepny element z listy (jezeli istnieje)
        cout << min->value << " ";
        if (min->next != NULL) {
            insert(queue, min->next);
        }
        delete min;
    }
    delete[] queue->values;
    delete queue;
    return 0;
}
