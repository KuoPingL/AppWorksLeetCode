using namespace std;
#include <vector>

class BubbleSort {
    public:
    static void sort(vector<int> &nums, bool iteration) {
        if (iteration) {
            iteratorSort_2(nums);
        } else {
            recursiveSort(nums);
        }
    }

    private:

    /**
     * @brief Bubble sort through iteration
     * 
     * @param nums : input vector<int>
     * 
     */
    static void iteratorSort(vector<int> &nums) {

        // for (int i = 0 ; i < nums.size() - 1 ; i++) {

        //     int t_index = nums.size() - 1;

        //     for (int j = t_index - 1 ; j >= i ; j--) {
        //         int t = nums[t_index];
        //         int c = nums[j];

        //         if (t < c) {
        //             // swap 
        //             nums[t_index] = c;
        //             nums[j] = t;
        //             t_index = j;
        //         } else {
        //             t_index = j;
        //         }
        //     }
        // }

        for (int i = 0 ; i < nums.size() - 1 ; i++) {

            bool swapped = false;

            for (int j = nums.size() - 1 ; j > i ; j--) {

                if (nums[j] < nums[j-1]) {
                    swapped = true;
                    swap(nums, j, j-1);
                }
            }

            if (!swapped) break;
        }
    }

    static void iteratorSort_2(vector<int> &nums) {
        // improved
        for (int i = nums.size() ; i > 0 ; i--) {
            bool swapped = false;
            for (int j = 0 ; j < i - 1 ; j++) {
                if (nums[j] > nums[j+1]) {
                    swapped = true;
                    swap(nums, j+1, j);
                }
            }
            if (!swapped) break;
        }
    }

    static void recursiveSort(vector<int> &nums, int i = 1) {
        int t_index = nums.size() - 1;

        if (i == nums.size() - 1) return;

        bool swapped = false;

        for (int j = nums.size() - 1 ; j > i ; j--) {
            if (nums[j] < nums[j-1]) {
                swapped = true;
                swap(nums, j, j-1);
            }
        }

        if (!swapped) return;

        recursiveSort(nums, ++i);
    }

    static void swap(vector<int>& nums, int indexA, int indexB) {
        int a = nums[indexA];
        nums[indexA] = nums[indexB];
        nums[indexB] = a;
    }
};