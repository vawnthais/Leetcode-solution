class heap {
public:
    int parent(int i) {return (i-1) / 2;}
    int left(int i) {return 2*i +1;}
    int right(int i) {return 2*i + 2;}
    vector<int> arr_heap;

    void clim(int i) {
        while (i >= 0 and arr_heap[i] > arr_heap[parent(i)]) {
            std::swap(arr_heap[i], arr_heap[parent(i)]);
            i = parent(i);

        }
    }

    void down(int a) {
        int max_num = a;
        int lf = left(a);
        int ri = right(a);

        if (lf < arr_heap.size() && arr_heap[lf] > arr_heap[max_num]) max_num = lf;
        if (ri < arr_heap.size() && arr_heap[ri] > arr_heap[max_num]) max_num = ri;
        if (max_num == a) return;
        swap(arr_heap[max_num], arr_heap[a]);
        down(max_num);
    }
    void insert(int num) {
        arr_heap.push_back(num);
        clim(arr_heap.size() -1);
    }

    void pop() {
        if (is_empty()) return;
        arr_heap[0] = arr_heap.back();
        arr_heap.pop_back();
        if (!is_empty()) down(0);

    }

    int top() {
        return arr_heap.empty() ? -1 : arr_heap[0];
    }

    bool is_empty() {return arr_heap.empty();}

    int size() {return arr_heap.size();}
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        heap heap;
        for (int x : stones) {
            heap.insert(x);
        }
        while (heap.size() > 1) {
            int stone_y = heap.top();
            heap.pop();
            int stone_x = heap.top();
            heap.pop();
            
            if (stone_y == stone_x) continue;
            if (stone_x != stone_y) {
                int new_stone = stone_y - stone_x;
                heap.insert(new_stone);
            }
        }
        return heap.is_empty() ? 0 : heap.top();
    }
};