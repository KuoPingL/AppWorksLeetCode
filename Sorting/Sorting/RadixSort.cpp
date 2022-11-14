using namespace std;
#include <iostream>
#include <vector>
#include "RadixSort.h"

int main(int argc, char const *argv[])
{
    vector<int> nums = {195, 29, 3, 193, 20, 81, 17, 6};//{9, 8, 7, 6, 5, 4, 3, 2, 1};

    RadixSort::sort(nums, RadixSort::MSD, 195);

    cout << '{';
    for (auto i : nums) {
        cout << i << ", ";
    }
    cout << "}\n";

    return 0;
}