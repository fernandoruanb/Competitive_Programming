class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int left = i + 1;
        int right = nums.size() - 1;
        vector<vector<int>> result;
        while (i < nums.size() - 1) {
	    //avoid duplicates
            if (i > 0 && nums[i] == nums[i - 1]) {
                ++i;
                continue ;
            }
            left = i + 1;
            right = nums.size() - 1;

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
                } else if (sum < 0)
                    ++left;
                else
                    --right;
            }
            ++i;
    }
    return result;
}
};
