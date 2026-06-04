class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size() - 1;
        int counter = 0;
        int candidate = 0;
        for (int n: nums) {
            if (counter == 0) {
                counter = 1;
                candidate = n;
            } else if (n == candidate)
                ++counter;
            else
                --counter;
        }
        return candidate;
    }
};
