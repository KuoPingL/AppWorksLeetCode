using namespace std;
#include <iostream>
#include <vector>
#include "BucketSort.h"

int main(int argc, char const *argv[])
{
    vector<int> nums = {19, 39, 6, 23, 20, 31, 19, 27, 3};//{9, 8, 7, 6, 5, 4, 3, 2, 1};

    BucketSort::sort(nums, 3, 39);

    cout << '{';
    for (auto i : nums) {
        cout << i << ", ";
    }
    cout << "}";

    return 0;
}