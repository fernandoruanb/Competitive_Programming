class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        int size1 = nums1.size() - 1;
        int size2 = nums2.size() - 1;
        int i = 0;
        int j = 0;
        while (i <= size1 && j <= size2) {
            if (nums1[i] == nums2[j]) {
                if (result.empty() || result.back() != nums1[i])
                    result.push_back(nums1[i]);
                ++i;
                ++j;
            }
            else if (nums1[i] < nums2[j])
                ++i;
            else if (nums1[i] > nums2[j])
                ++j;
        }
        return result;
    }
};
