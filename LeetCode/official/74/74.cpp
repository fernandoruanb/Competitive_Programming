class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size();
        while (size) {
            int index = 0;
            for (int n: matrix[size - 1])
                if (n == target) return true;
            --size;
        }
        return false;
    }
};
