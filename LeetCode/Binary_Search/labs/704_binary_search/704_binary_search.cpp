#include <iostream>
#include <vector>

class BinarySearch {
	public:
		static int findNumber(std::vector<int> nums, int target) {
			int start = 0;
			int end = nums.size() - 1;
	
			while (start <= end) {
				int mid = start + (end - start) / 2; // more recommended to avoid big numbers

				if (nums[mid] == target) return mid;
				else if (nums[mid] > target) end = mid - 1;
				else if (nums[mid] < target) start = mid + 1;
			}
			return (-1);
		}
};

int main(void) {
	std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
	int target = -5;

	int result = BinarySearch::findNumber(nums, target);
	std::cout << result << std::endl;
	return (0);
}
