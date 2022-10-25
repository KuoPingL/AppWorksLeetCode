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
            int t = nums[i];
            int j = i;

            while (j != 0) {
                if (nums[j - 1] > t) {
                    nums[j] = nums[j - 1];
                    
                } else {
                    // break;
                }
                j--;
            }

            nums[j] = t;

            // for (int j = i ; j > 0 ; j--) {
            //     if (nums[j - 1] > t) {
            //         nums[j] = nums[j - 1];
            //     } else {
            //         nums[j] = t;
            //         break;
            //     }

            //     if (j - 1 == 0) {
            //         nums[j - 1] = t;
            //         break; 
            //     }
            // }
        }
    }

    static void recursiveSort(vector<int>& nums, int i = 1) {
        if (i == nums.size()) return;
        int t = nums[i];
        int j = i;

        while (j != 0) {
            if (nums[j - 1] > t) {
                nums[j] = nums[j - 1];
                j--;
            } else {
                break;
            }
        }

        nums[j] = t;

        recursiveSort(nums, i+1);
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