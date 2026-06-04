class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int size = grid.size();
        int negativeNumbers = 0;
        while (size) {
            int index = 0;
            for (int n: grid[size - 1])
                if (n < 0) negativeNumbers += 1;
            --size;
        }
        return negativeNumbers;
    }
};
