class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pairs;
        int index = 0;
        for (int value: nums) {
            pairs.push_back({value, index});
            ++index;
        }
        sort(pairs.begin(), pairs.end());
        int size = nums.size();
        vector<int> result;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = pairs[left].first + pairs[right].first;
            if (sum == target) {
                result.push_back(pairs[left].second);
                result.push_back(pairs[right].second);
                return (result);
            }
            else if (sum > target)
                --right;
            else if (sum < target)
                ++left;
        }
        return result;
    }    
};

