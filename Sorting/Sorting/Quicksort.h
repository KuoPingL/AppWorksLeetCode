using namespace std;
#include <vector>
#include <iostream>
#include <stack>

class Quicksort {
    public:
    static void sort(vector<int>& nums, bool iteration) {
        if (iteration) {
            iterativeSort(nums, 0, nums.size() - 1);
        } else {
            recursiveSort(nums, 0, nums.size() - 1);
        }
    }

    private:
    static void iterativeSort(vector<int>& nums, int low, int high) {
        if (low >= high || low < 0) return;
        stack<int> ranges;

        ranges.push(low);
        ranges.push(high);

        while(ranges.size() > 0) {
            high = ranges.top();
            ranges.pop();
            low = ranges.top();
            ranges.pop();

            if (low >= high || low < 0) continue;

            int p = partition(nums, low, high);

            ranges.push(p + 1);
            ranges.push(high);

            ranges.push(low);
            ranges.push(p - 1);

            // if (p + 1 < high) {
            //     ranges.push(p + 1);
            //     ranges.push(high);
            // }

            // if (p - 1 >= low) {
            //     ranges.push(low);
            //     ranges.push(p - 1);
            // }
        }
    }

    static void recursiveSort(vector<int>& nums, int low, int high) {

        if (low >= high || low < 0) return;

        int pivot = partition(nums, low, high);

        recursiveSort(nums, low, pivot - 1);
        recursiveSort(nums, pivot + 1, high);
    }

    static int partition(vector<int>& nums, int low, int high) {

        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums, i, j);
            }
        }

        i++;
        swap(nums, i, high);
        return i;
    }

    static void swap(vector<int>& nums, int a, int b) {

        // printf("Swap [%d, %d] = {%d, %d}\n", a, b, nums[a], nums[b]);

        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }


};
