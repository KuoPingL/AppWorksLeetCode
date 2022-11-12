using namespace std;

#include <vector>
#include "SelectionSort.h"
#include "InsertionSort.h"

class BucketSort {
    public:
    static void sort(vector<int>& nums, int min, int max) {
        int n = nums.size();
        int range = (max - min)/n + 1;

        vector<int> buckets[n];

        for (int i = 0; i < n; i++) {
            int v = nums[i];
            int index = ((v - min) / range);
            buckets[index].push_back(v);
        }

        for (int i = 0; i < n; i++) {
            bucketSort(buckets[i]);
        }

        int curIndex = 0;
        for (int i = 0; i < n; i++) {
            int bucketSize = buckets[i].size();
            for (int j = 0; j < bucketSize; j++) {
                nums[curIndex] = buckets[i][j];
                // cout << "[i][j] = " << i << ", " << j << " value " << nums[curIndex] << "\n";
                curIndex ++;
            }
        }
    }

    private:
    static void bucketSort(vector<int>& nums) {

        // cout << '{';
        // for (auto i : nums) {
        //     cout << i << ", ";
        // }
        // cout << "}\n";
        // SelectionSort::sort(nums, true);
        InsertionSort::sort(nums, true);

        // cout << '{';
        // for (auto i : nums) {
        //     cout << i << ", ";
        // }
        // cout << "}\n";
    }


};