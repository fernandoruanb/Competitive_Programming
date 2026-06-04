//#include <iostream>
//#include <vector>

class Solution {
public:
	// put static before int to test without an object
    int search(std::vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};

/*int main(void) {
	std::vector<int> nums = {1, 2, 3, 4, 5, 6};
	int target = 6;
	int result = Solution::search(nums, target);
	std::cout << result << std::endl;
	return (0);
}*/
