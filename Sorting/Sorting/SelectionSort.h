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
        for(int i = 0 ; i < nums.size() - 1 ; i++) {
            
            int min_index = i;

            for (int j = i + 1 ; j < nums.size() ; j++) {
                if (nums[j] < nums[min_index]) {
                    min_index = j;
                }
            }
            
            if (min_index != i) {
                int min = nums[min_index];
                nums[min_index] = nums[i];
                nums[i] = min;
            }
        }
    }

    static void recursiveSort(vector<int>& nums, int index = 0) {
        int min_index = index;

        if (min_index == nums.size()) return;

        for (int j = index + 1 ; j < nums.size() ; j++) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        
        if (min_index != index) {
            int min = nums[min_index];
            nums[min_index] = nums[index];
            nums[index] = min;
        }

        recursiveSort(nums, ++index);
    }
};