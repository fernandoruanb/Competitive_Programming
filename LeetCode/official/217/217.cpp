class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size() - 1;
        int index = 1;
        int candidate = nums[0];
        while(index <= size) {
            if (nums[index] == candidate) return true ;
            else
                candidate = nums[index];
            ++index;
        }
        return false ;
    }
};
