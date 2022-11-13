class Solution {
public:
    bool judgeSquareSum(int c) {
        //这里要用long long 不然数值会溢出
        long long left = 0, right = (int)sqrt(c);
        long long sum;
        while (left <= right) {
            sum = left * left + right * right;
            if (sum == c) return true;
            if (sum > c) right--;
            else left++;
        }
        return false;
    }
};
