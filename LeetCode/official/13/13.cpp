class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> myMap = {
            {'I', 1},  
            {'V', 5}, 
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
            {'\0', 0}
    };
    int index = 0;
    int result = 0;
    while (s[index]) {
        auto curr = myMap.find(s[index]);
        auto next = myMap.find(s[index + 1]);
        if (curr == myMap.end() || next == myMap.end())
            return (-1);
        if (curr->second < next->second) {
            result = result + (next->second - curr->second);
            index += 2;
            continue ;
        }
        else
            result += curr->second;
        ++index;
    }
        return result;
    }
};
