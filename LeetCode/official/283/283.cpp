class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;
        int read = 0;
        int size = nums.size() - 1;
        while (read <= size) {
            if (nums[read] != 0) {
                nums[write] = nums[read];
                ++write;
            }
            ++read;
        }
        while (write <= size) {
            nums[write] = 0;
            ++write;
        }
    }
};
