/**

      Zadanie: Scalanie wielu list.
      Autor: Bartomiej Szczepanik

      Rozwiazanie wzorcowe (wersja C++)

      Zlozonosc rozwizania: O(m lg n)

    **/

    #include <algorithm>
    #include <cstdio>
    #include <vector>

    using namespace std;

    vector<vector<int>> load_numbers() {
      int lists_count;
      scanf("%d", &lists_count);

      vector<vector<int>> lists;
      lists.resize(lists_count);

      for(int i=0; i<lists_count; ++i) {
        int size;
        scanf("%d", &size);

        for(int j=0; j<size; ++j) {
          int value;
          scanf("%d", &value);

          lists[i].push_back(value);
        }
      }

      return lists;
    }

    typedef pair<int, int> ValueListId;

    template<class T>
    class MinHeap {
      vector<T> data;

      int parent(int i) {
        return (i+1)/2-1;
      }

      void heapify_from_last() {
        int position = data.size() - 1;
        while(position > 0 && data[parent(position)] > data[position]) {
          swap(data[parent(position)], data[position]);
          position = parent(position);
        }
      }

      void heapify_from_top() {
        int position = 0;
        for(;;) {
          int left_child = position * 2 + 1;
          int right_child = position * 2 + 2;

          T min_of_three = data[position];
          if(left_child < data.size()) {
            min_of_three = min(min_of_three, data[left_child]);
          }
          if(right_child < data.size()) {
            min_of_three = min(min_of_three, data[right_child]);
          }

          if(left_child < data.size() && data[left_child] == min_of_three) {
            swap(data[left_child], data[position]);
            position = left_child;
          }
          else if(right_child < data.size() && data[right_child] == min_of_three) {
            swap(data[right_child], data[position]);
            position = right_child;
          }
          else {
            break;
          }
        }
      }

     public:
      void push(T element) {
        data.push_back(element);
        heapify_from_last();
      }

      T top() {
        return data[0];
      }

      void pop() {
        swap(data[0], data[data.size()-1]);
        data.pop_back();
        heapify_from_top();
      }

      bool empty() {
        return data.empty();
      }
    };

    int main() {
      vector<vector<int>> lists = load_numbers();

      vector<int> current_positions;
      current_positions.resize(lists.size(), 0);

      MinHeap<ValueListId> first_elements;

      for(int i=0; i<lists.size(); ++i) {
        int list_id = i;
        int first_element_value = lists[i][0];

        first_elements.push({first_element_value, i});
      }

      while(!first_elements.empty()) {
        pair<int, int> min_element = first_elements.top();
        first_elements.pop();

        int value = get<0>(min_element);
        int list_id = get<1>(min_element);

        printf("%d ", value);
        current_positions[list_id]++;
        int position = current_positions[list_id];

        if(position < lists[list_id].size()) {
          first_elements.push({lists[list_id][position], list_id});
        } 
      }

      return 0;
    }