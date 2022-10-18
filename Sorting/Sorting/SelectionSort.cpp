using namespace std;
#include <iostream>
#include <vector>

class SelectionSort {
    public:
    static void sort(vector<int> &nums) {
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
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 9, 3, 1, 2, 8, 4, 7, 6};//{9, 8, 7, 6, 5, 4, 3, 2, 1};

    SelectionSort::sort(nums);

    cout << '{';
    for (auto i : nums) {
        cout << i << ", ";
    }
    cout << "}";

    return 0;
}
