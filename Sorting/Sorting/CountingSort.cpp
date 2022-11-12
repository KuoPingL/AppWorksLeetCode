using namespace std;
#include <iostream>
#include <vector>
#include "CountingSort.h"

int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 9, 3, 1, 2, 8, 4, 0, 7, 6, 5, 7, 3, 8};//{9, 8, 7, 6, 5, 4, 3, 2, 1};

    CountingSort::sort(nums, true, 9);

    cout << '{';
    for (auto i : nums) {
        cout << i << ", ";
    }
    cout << "}";

    return 0;
}