
using namespace std;
#include <vector>
#include <iostream>

class BubbleSort {
    public:
    
    void sort(vector<int> &nums, bool iteration) {
        if (iteration) {
            iteratorSort(nums);
        } else {
            throw runtime_error("no RECURSIVE SORT has implemented");
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
    void iteratorSort(vector<int> &nums) {

        int counter = 0;

        for (int i = 0 ; i < nums.size() - 1 ; i++) {

            int t_index = nums.size() - 1;

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
                counter ++;
            }
            cout << counter;
            counter = 0;
        }
    }

    void recursiveSort(vector<int> &nums) {
        
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 9, 3, 1, 2, 8, 4, 7, 6};//{9, 8, 7, 6, 5, 4, 3, 2, 1};

    BubbleSort* sort = new BubbleSort();
    sort->sort(nums, true);


    cout << '{';
    for (auto i : nums) {
        cout << i << ", ";
    }
    cout << "}";

    return 0;
}

