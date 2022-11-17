class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = n & 1;
        n >>= 1;
        while (n > 0) {
            if ((n & 1) == pre) return false;
            pre = n & 1;
            n >>= 1;
        }
        return true;
    }
};
