class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prev = {1};
        vector<int> curr = {1, 1};
        result.push_back(prev);
        if (numRows == 1)
            return result;
        if (numRows == 2) {
            result.push_back(curr);
            return result;
        }
        result.push_back(curr);
        int size = 3;
        prev = curr;
        while (size <= numRows) {
            vector<int> r;
            r.push_back(1);
            for (int counter = 1; counter < size - 1; ++counter) {
                r.push_back(prev[counter - 1] + prev[counter]);
            }
            r.push_back(1);
            prev = r;
            result.push_back(r);
            ++size;
        }
        return result;
    }
};
