using namespace std;
#include <vector>

class BubbleSort {
    public:
    static void sort(vector<int> &nums, bool iteration) {
        if (iteration) {
            iteratorSort(nums);
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

            for (int j = nums.size() - 1 ; j > i ; j--) {

                if (nums[j] < nums[j-1]) {
                    // swap 
                    int t = nums[j];
                    nums[j] = nums[j-1];
                    nums[j-1] = t;
                }
            }
        }
    }

    static void recursiveSort(vector<int> &nums, int i = 1) {
        int t_index = nums.size() - 1;

        if (i == t_index) return;

        for (int j = t_index - 1 ; j >= i ; j--) {
            int t = nums[t_index];
            int c = nums[j];

            if (t < c) {
                // swap 
                nums[t_index] = c;
                nums[j] = t;
                t_index = j;
            } else {
                t_index = j;
            }
        }

        recursiveSort(nums, ++i);
    }
};