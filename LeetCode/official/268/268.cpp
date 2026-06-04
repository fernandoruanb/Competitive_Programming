#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// put static to test
    static int missingNumber(vector<int>& nums) {
	int size = nums.size();
	int res = size * (size + 1) / 2;
	int sum = 0;

	for (int n: nums)
		sum += n;

	return (res - sum);	
    }
};

int main(void) {
	vector<int> nums = {1, 0};
	int result = Solution::missingNumber(nums);
	cout << result << endl;
	return (0);
}
