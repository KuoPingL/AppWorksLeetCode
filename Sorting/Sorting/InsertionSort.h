using namespace std;
#include <vector>

class InsertionSort {
    public:
    static void sort(vector<int>& nums, bool iteration) {

        if (nums.size() <= 1) return;
        
        if (iteration) {
            iterationSort(nums);
            // alrightChiu(nums);
        } else {
            recursiveSort(nums);
        }

    }
    
    static void iterationSort(vector<int>& nums) {
        
        for (int i = 1 ; i < nums.size() ; i++) {
            for (int j = i; j > 0 && lessThan(nums[j], nums[j-1]); j--) {
                swap(nums, j, j-1);
            }
        }
    }

    static void recursiveSort(vector<int>& nums, int index = 1) {
        if (index == nums.size()) return;
        for (int j = index; j > 0 && lessThan(nums[j], nums[j-1]); j--) {
            swap(nums, j, j-1);
        }

        recursiveSort(nums, index+1);
    }

    static void alrightChiu(vector<int>& nums) {
        int size = nums.size();
        for (int i = 1; i < size; i++) {
            int key = nums[i];
            int j = i - 1;
            while (key < nums[j] && j >= 0) {
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key;
        }
    }

    static bool lessThan(int a, int b) {
        return a < b;
    }

    static void swap(vector<int>& nums, int indexA, int indexB) {
        int a = nums[indexA];
        nums[indexA] = nums[indexB];
        nums[indexB] = a;
    }
};