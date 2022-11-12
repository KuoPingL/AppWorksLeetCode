using namespace std;

#include<vector>

class CountingSort {
    public:
    static void sort(vector<int>& nums, bool iteration, int max) {

        if (iteration) {
            iterationSort(nums, nums.size(), max);
        }

    }

    private:
    static void iterationSort(vector<int>& arr, int n, int k) {
        int b[n]; int c[k + 1];

        for (int i = 0; i <= k; i++) {
            c[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            c[arr[i]] = c[arr[i]] + 1;
        }

        for (int i = 1; i <= k; i++) {
            c[i] = c[i] + c[i - 1];
        }

        for (int i = 0; i < n; i++) {
            b[c[arr[i]] - 1] = arr[i];
            c[arr[i]] = c[arr[i]] - 1;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = b[i];
        }
    }
};