#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int upper = nums.size() - 1;
        int lower = 0;
        int cur = 0;
        
        while (upper >= lower) {
            cur = lower + (upper - lower)/2;
            cout << cur << endl;
            if (nums[cur] == target) return cur;
            else if (nums[cur] >= target) upper = cur - 1;
            else lower = cur + 1;
        }
        
        return -1;
    }
};