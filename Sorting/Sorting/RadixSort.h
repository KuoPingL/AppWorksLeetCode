using namespace std;
#include <vector>
#include <algorithm>


class RadixSort {
    public:
    enum RadixType {
        LSD, MSD,
    };

    static void sort(vector<int>& nums, RadixType type, int max) {
        switch (type)
        {
        case LSD:
            lsdSortLinkList(nums, max);
            break;
        
        default:

            int radix = 1;
            while(radix < max) {
                radix *= 10;
            }

            radix /= 10;
            msdSort(nums, nums, radix, 0);
            break;
        }
    }

    private:

    static void lsdSort(vector<int>& nums, int max) {
    }

    static void lsdSortLinkList(vector<int>& nums, int max) {
        // create buckets 
        node** buckets = new node*[10];
        int radix = 1;

        // init
        for (int i = 0; i < 10; i++) {
            buckets[i] = nullptr;
        }

        while(radix < max) {
            for (int i = 0; i < nums.size(); i++) {
                int bucket = (nums[i] / radix) % 10;
                append(buckets[bucket], nums[i]);
            }

            int bucket = 0;
            int index = 0;
            while(bucket < 10) {
                while(buckets[bucket] != nullptr) {
                    nums[index++] = popFirst(buckets[bucket]);
                }
                bucket++;
            }

            radix *= 10;
        }
    }


    static void lsdSortVector(vector<int>& nums, int max) {
        // 0 to 9
        vector<int> buckets[10];
        int counters[10] = { 0 };
        int radix = 1;

        while(radix < max) {

            for (int i = 0; i < nums.size(); i++) {
                int v = nums[i];
                int di = nums[i] / radix;
                int bucket = di % 10;
                buckets[bucket].push_back(v);
                counters[bucket] += 1;
            }

            // gather 
            int index = 0;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < counters[i]; j++) {
                    nums[index] = buckets[i][j];
                    index ++;
                }
            }

            for (int i = 0; i < 10; i++) {
                while(!buckets[i].empty()) {
                    buckets[i].pop_back();
                }
            }

            fill(begin(counters), end(counters), 0);

            radix *= 10;
        }
    }

    static void msdSort(vector<int>& nums, vector<int>& original, int radix, int index) {

        if (radix == 0) return;
        
        node**buckets = new node*[10];

        for (int i = 0; i < 10; i++) {
            buckets[i] = nullptr;
        }

        // scatter
        for (int i = 0; i < nums.size(); i++) {
            append(buckets[(nums[i] / radix) % 10], nums[i]);
        }

        if (radix == 1) {
            int currentIndex = index;
            for (int i = 0; i < 10; i++) {
                while(buckets[i] != nullptr) {
                    original[currentIndex++] = popFirst(buckets[i]);
                }
            }

            cout << '{';
            for (auto i : original) {
                cout << i << ", ";
            }
            cout << "}\n";
        } else {
            int nextIndex = index;
            for(int i = 0; i < 10; i++) {
                vector<int> nextNum;
                
                while(buckets[i] != nullptr) {
                    nextNum.push_back(popFirst(buckets[i]));
                }

                if (!nextNum.empty()) {
                    msdSort(nextNum, original, radix / 10, nextIndex);
                    nextIndex += nextNum.size();
                    nextNum.clear();
                }
            }
        }

    }

    private:
    /**
     * @brief Below contains all class and fucntions for link list
     * 
     */
    // Node : https://www.geeksforgeeks.org/radix-sort/
    struct node {
        int data;
        node* next;
    };

    static struct node* create(int data) {
        node* temp = new node();
        temp->data = data;
        temp->next = nullptr;
        return temp;
    }

    static void append(node*& header, int data) {
        if(header == nullptr) {
            header = create(data);
            return;
        }

        node* t = header;

        while(t->next != nullptr) {
            t = t->next;
        }
        t->next = create(data);
    }

    static int popFirst(node*& header) {

        if (header == nullptr) {
            return 0;
        }

        node* t = header;
        int data = t->data;

        header = header->next;
        
        delete t;
        return data;
    }
};