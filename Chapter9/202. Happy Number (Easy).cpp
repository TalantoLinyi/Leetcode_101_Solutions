class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        int fast = n, slow = n;
        do {
            fast = next(next(fast));
            slow = next(slow);
            if (fast == 1) return true;
        } while (fast != slow);
        return false;
    }

    int next(int num) {
        int ans = 0, last;
        while (num) {
            last = num % 10;
            ans += last * last;
            num /= 10;
        }
        return ans;
    }
};
