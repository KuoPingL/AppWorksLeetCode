using namespace std;
#include <vector>
#include <iostream>

class MergeSort {
    public:
    static void sort(vector<int>& nums, bool iteration) {
        if (iteration) {
            sortIterativelyCorrectly(nums);
        } else {
            sortRecursively(nums, 0, nums.size() - 1);
        }
    }

    private:
    static const int debug = true;
    static void sortIteratively(vector<int>& nums) {

        int step = 2;
        int n = nums.size();
        int counter = 0;
        int whileCounter = 0;

        if (n < 2) return;
        
        while(n > step) {
            if (debug) {
                cout << "step = " << step << "\n";
                whileCounter ++;
            }
            for (int i = 0; i < n; i += step) {


                int start = i;
                int end = i + step - 1;
                int mid = (end - start) / 2 + start;

                if (end > n - 1) {
                    end = n - 1;
                    mid = i + step / 2 - 1;

                    if (start == end) mid = start;
                }

                if (debug)
                    cout << "index = [ " << start << " , " << mid << " , " << end << " ]\n"; 

                merge(nums, start, mid, end);
                counter ++;
            }

            step *= 2;
        }

        step /= 2;

        if (debug)
            printf("index = [ 0 , %d , %d ]\n", step - 1, n - 1);
        merge(nums, 0, step, n - 1);
        counter ++;

        if (debug)
            {
                cout << "counter = " << counter << "\n";
                cout << "while counter = " << whileCounter << "\n";}
    }

    static void sortIterativelyCorrectly(vector<int>& nums) {

        int step = 2;
        int n = nums.size();
        int counter = 0;
        int whileCounter = 0;

        if (n < 2) return;
        
        while(n > step) {
            if (debug) {
                cout << "step = " << step << "\n";
                whileCounter ++;
            }
            for (int i = 0; i < n; i += step) {
                int start = i;
                int end = min(start + step - 1, n - 1);
                int mid = min(start + step/2 - 1, n - 1);

                if (debug)
                    cout << "index = [ " << start << " , " << mid << " , " << end << " ]\n"; 

                merge(nums, start, mid, end);
                counter ++;
            }

            step *= 2;
        }

        step /= 2;

        if (debug)
            printf("index = [ 0 , %d , %d ]\n", step - 1, n - 1);
        if (step < n) {
            merge(nums, 0, step - 1, n - 1);
            counter ++;
        }
        

        if (debug)
            {
                cout << "counter = " << counter << "\n";
                cout << "while counter = " << whileCounter << "\n";}
    }

    static void sortRecursively(vector<int>& nums, int start, int end) {
            if (start >= end) return;

            int mid = (end - start) / 2 + start;

            // left child
            sortRecursively(nums, start, mid);
            // right child
            sortRecursively(nums, mid+1, end);

            merge(nums, start, mid, end);
    }

    static void merge(vector<int>& nums, int start, int mid, int end) {
        int currInd = 0;
        int size = end - start + 1;
        int result[size];
        int i = start, j = mid + 1;

        while(i <= mid && j <= end) {
            if (nums[i] < nums[j]) {
                result[currInd] = nums[i];
                i++;
            } else {
                result[currInd] = nums[j];
                j++;
            }

            currInd++;
        }

        if (i <= mid) {
            for (int k = i; k <= mid; k++) {
                result[currInd] = nums[k];
                currInd++;
            }
        } else if (j <= end) {
            for (int k = j; k <= end; k++) {
                result[currInd] = nums[k];
                currInd++;
            }
        }

        for (int k = 0; k < size; k++) {
            nums[k + start] = result[k];
        }

        if (debug) {
            cout << '{';
            for (auto n : nums) {
                cout << n << ", ";
            }
            cout << '}';
            cout << "\n";
        }
    }
};
