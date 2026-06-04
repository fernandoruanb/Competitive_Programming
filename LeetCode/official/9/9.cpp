class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long int copy = x;
        long long int test = 0;
        while (copy) {
            test *= 10;
            long long int num = copy % 10;
            test += num;
            copy /= 10;
        }
        if (x == test)
            return true;
        return false;
    }
};
