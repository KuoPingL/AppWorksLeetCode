using namespace std;
#include <iostream>
#include <vector>
#include "MergeSort.h"

int main(int argc, char const *argv[])
{
    vector<int> nums = {9, 8, 7, 6, 5, 4, 3, 2, 1};//{17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};//{11, 23, 34, 94, 14, 5, 9, 3, 1, 2, 8, 4, 7, 6, };//{9, 8, 7, 6, 5, 4, 3, 2, 1};

    MergeSort::sort(nums, true);

    cout << '{';
    for (auto i : nums) {
        cout << i << ", ";
    }
    cout << "}";

    return 0;
}