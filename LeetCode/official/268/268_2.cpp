#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	// put static to test
    static int missingNumber(vector<int>& nums) {
        int loop = nums.size(), original = loop;
        while (loop-- >= 0) {
            int target = 0;
            int result = Solution::binarySearch(nums, target);
            if (result == -1) 
                return (target);
	    ++target;
        }
        return (original);
    }
    static int binarySearch(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) end = mid - 1;
            else if (nums[mid] < target) start = mid + 1;
        }
        return -1;
    }
};

int main(void) {
	vector<int> nums = {1, 0};
	sort(nums.begin(), nums.end());
	int result = Solution::missingNumber(nums);
	cout << result << endl;
	return (0);
}
