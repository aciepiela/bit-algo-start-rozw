/**

      Zadanie: Find The Median
      Autor: Aleksander Ciepiela

      Rozwiazanie wzorcowe

      Zlozonosc rozwizania: O(n)

    **/

#include <iostream>

using namespace std;

void swap(int tab[], int i, int j) {

    int temp = tab[j];
    tab[j] = tab[i];
    tab[i] = temp;
}

int partition(int tab[], int l, int r) {
    int x = tab[r];
    int j = l - 1;

    for (int i = l; i < r; i++) {
        if (tab[i] <= x) {
            j++;
            swap(tab, i, j);
        }
    }
    j++;
    swap(tab, r, j);
    return j;
}

// znajduje k-ty co do wielkosci element w tablicy
int quick_find(int arr[], int begin, int end, int k) {
    int pivot = partition(arr, begin , end);
    if(pivot == k) {
        return arr[pivot];
    }
    if(pivot > k) {
        return quick_find(arr, begin, pivot - 1, k);
    }
    return quick_find(arr, pivot + 1, end, k);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << quick_find(arr, 0, n - 1, n / 2);
    return 0;
}