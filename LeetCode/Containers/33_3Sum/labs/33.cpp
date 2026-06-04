#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
	public:
		Solution() {};
		static vector<vector<int>> threeSum(vector<int> nums) {
			sort(nums.begin(), nums.end());
			vector<vector<int>> result;
			int i = 0;
			while (i < nums.size()) {
				// avoid duplicates i like 1 1 1 1 just only 1
				if (i > 0 && nums[i] == nums[i - 1]) {
					++i;
					continue ;
				}
				int left = i + 1;
				int right = nums.size() - 1;
				while (left < right) {
					int sum = nums[i] + nums[left] + nums[right];
					if (sum == 0) {
						result.push_back({nums[i], nums[left], nums[right]});
						//avoid duplicates
						while (left < right && nums[left] == nums[left + 1])
							++left;
						while (left < right && nums[right] == nums[right - 1])
							--right;
						//avoid the final duplicate
						++left;
						--right;
					} else if (sum > 0)
						--right;
					else if (sum < 0)
						++left;
				}
				++i;
			}
			return result;
		}
};

int main(void) {
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> result = Solution::threeSum(nums);

	for (const auto& triplet: result) {
		cout << "[" << " ";
		for (int n: triplet)
			cout << n << " ";
		cout << "]" << " ";
	}
	cout << endl;
	return (0);
}
