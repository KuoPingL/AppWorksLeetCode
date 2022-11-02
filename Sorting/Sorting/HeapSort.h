using namespace std;

#include <vector>

class HeapSort {
    public:
    static void sort(vector<int>& arr, bool iteration) {
        if (iteration) {
            sortIteration(arr);
        } else {
            sortRecursion(arr);
        }
    }

    private:
    static void sortIteration(vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1 ; i >= 0 ; i-- ) {
            int max = i;
            do {
                max = heapifyIteration(arr, max, n);
            } while(max != -1);

        }

        for (int i = n - 1; i >= 0; i--) {
            swap(arr, 0, i);
            int max = 0;
            do {
                max = heapifyIteration(arr, max, i);
            } while(max != -1);
        }
    }

    static int heapifyIteration(vector<int>& tree, int root, int length) {
        int c1 = 2*root + 1; // left Index 
        int c2 = 2*root + 2; // right Index
        int max = root;      // init as parent root

        if (c1 < length && tree[c1] > tree[max]) {
            max = c1;
        }

        if (c2 < length && tree[c2] > tree[max]) {
            max = c2;
        }

        if (max != root) {
            swap(tree, max, root);
            return max;
        }
        return -1;
    }

    static void sortRecursion(vector<int>& arr) {
        // loop through all parent nodes 
        for (int i= (arr.size() - 1) / 2 ; i >= 0 ; i--) {
            heapify(arr, i, arr.size());
        }

        for (int i = arr.size() ; i > 0 ; i--) {
            swap(arr, 0, i - 1);
            heapify(arr, 0, i - 1);
        }
    }

    static void heapify(vector<int>& tree, int root, int length) {
        
        int c1 = 2*root + 1; // left Index 
        int c2 = 2*root + 2; // right Index
        int max = root;      // init as parent root

        if (c1 < length && tree[c1] > tree[max]) {
            max = c1;
        }

        if (c2 < length && tree[c2] > tree[max]) {
            max = c2;
        }

        if (max != root) {
            swap(tree, max, root);
            heapify(tree, max, length);
        }
    }

    // Swap 
    static void swap(vector<int>& tree, int a, int b) {
        int temp = tree[a];
        tree[a] = tree[b];
        tree[b] = temp;
    }
};