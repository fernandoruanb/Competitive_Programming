#include <iostream>
#include <vector>

class Solution {
	public:
		static int detectMissingNumber(std::vector<int>& nums) {
			int size = nums.size();
			int res = size * (size + 1) / 2;
			int sum = 0;

			for (int n: nums)
				sum += n;
			return (res - sum);
		}
};

int main(void) {
	std::vector<int> nums = {1, 2, 3, 5};
	std::cout << Solution::detectMissingNumber(nums) << std::endl;
	return (0);
}
