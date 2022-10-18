using namespace std;
#include <iostream>
#include "SelectionSort.h"


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
