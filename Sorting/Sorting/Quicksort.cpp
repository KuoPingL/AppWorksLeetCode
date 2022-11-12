using namespace std;
#include <iostream>
#include <vector>
#include "Quicksort.h"

int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 9, 3, 1, 2, 8, 4, 7, 6};//{9, 8, 7, 6, 5, 4, 3, 2, 1};

    Quicksort::sort(nums, true);

    cout << '{';
    for (auto i : nums) {
        cout << i << ", ";
    }
    cout << "}";

    return 0;
}