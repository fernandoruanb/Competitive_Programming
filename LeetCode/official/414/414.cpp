class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long int maximum = 2147483649; // long long int, int with 8 bytes not only 4 bytes
        int counter = 0;
        int right = nums.size() - 1;
        int first = nums[right];
        while (right >= 0) {
            if (nums[right] < maximum) {
                maximum = nums[right];
                ++counter;
            }
            if (counter == 3)
                return static_cast<int>(maximum);
            --right;
        }
        return first;
    }
};
