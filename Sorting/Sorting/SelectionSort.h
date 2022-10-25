using namespace std;
#include <vector>

class SelectionSort {
    public:
    static void sort(vector<int> &nums, bool iteration) {
        if (iteration) {
            iterationSort(nums);
        } else {
            recursiveSort(nums);
        }
    }

    private:
    static void iterationSort(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++) {
            
            int min_index = i;

            for (int j = i + 1 ; j < nums.size() ; j++) {
                if (nums[j] < nums[min_index]) {
                    min_index = j;
                }
            }
            
            if (min_index != i) {
                // if this can be done while going through the loop
                // that would become bubble sort
                swap(nums, min_index, i);
            }
        }
    }

    static void recursiveSort(vector<int>& nums, int i = 0) {
        int min_index = i;

        if (min_index == nums.size()) return;

        for (int j = i + 1 ; j < nums.size() ; j++) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        
        if (min_index != i) {
            swap(nums, min_index, i);
        }

        recursiveSort(nums, ++i);
    }

    static void swap(vector<int>& nums, int indexA, int indexB) {
        int a = nums[indexA];
        nums[indexA] = nums[indexB];
        nums[indexB] = a;
    }
};