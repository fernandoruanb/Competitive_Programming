#include <iostream>
#include <vector>

class Solution {
	public:
		static int binarySearch(std::vector<int>& nums, int target) {
			int start = 0;
			int end = nums.size() - 1;
			while (start <= end) {
				int mid = start + (end - start) / 2;
				if (nums[mid] == target) return mid;
				else if (nums[mid] > target)
					end = mid - 1;
				else if (nums[mid] < target)
					start = mid + 1;
			}
			return (-1);
		}

		static int detectMissingNumber(std::vector<int>& nums) {
			int loop = nums.size(), original = loop;
			while (--loop) {
				int target = loop;
				int result = Solution::binarySearch(nums, target);
				if (result == -1)
					return (target);
			}
			return (original);
		}
};

int main(void) {
	std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 9};
	std::cout << Solution::detectMissingNumber(nums) << std::endl;
	return (0);
}
