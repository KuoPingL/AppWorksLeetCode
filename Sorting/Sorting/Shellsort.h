using namespace std;
#include <vector>

class Shellsort {
    public:
    static void sort (vector<int>& nums, bool iteration) {

        cout << '{';
        for (auto i : nums) {
            cout << i << ", ";
        }
        cout << "}\n";

        if (iteration) {
            iterativeSort(nums);
        } else {

        }
    }

    private:
    static void iterativeSort(vector<int>& nums) {
        int n = nums.size();
        int gap = n / 2;

        while(gap >= 1) {
            int groups = n / gap;
            // cout << "h = " << gap << "\n";

            for (int i = 0; i <= groups; i ++ ){
                iterativeInsertionSort(nums, i, gap);
            }

            // cout << '{';
            // for (auto i : nums) {
            //     cout << i << ", ";
            // }
            // cout << "}\n";
            gap = gap / 2;
        }
    }

    static void iterativeInsertionSort(vector<int>& nums, int start, int gap) {
        int n = nums.size();
        
        for (int i = start + gap; i < n; i += gap) {
            int currentValue = nums[i];
            int currentIndex = i;
            
            for (int j = i - gap; j >= start; j -= gap) {
                if (nums[j] > currentValue) {
                    nums[currentIndex] = nums[j];
                    currentIndex = j;
                }
            }

            if (currentIndex != i) {
                nums[currentIndex] = currentValue;
            }
            
        }
    }

    static void recursiveSort(vector<int>& nums, int gap) {
        if (gap < 1) return;
        int group = n / gap;
        
        for (int i = 0; i <= groups; i ++ ){
            iterativeInsertionSort(nums, i, gap);
        }

        recursiveSort(nums, gap / 2);
    }

    static void recursiveInsertionSort(vector<int>& nums, int value, int targetIndex, int gap) {
        if (nums[targetIndex] > value) {
            nums[targetIndex + gap] = nums[targetIndex];
        } else {
            targetIndex += gap;
        }
    }
};