class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0, sum;
        string ans;
        while (carry || i >= 0 || j >= 0) {
            int vala = 0, valb = 0;
            if (i >= 0 && a[i] == '1') {
                vala = 1;
            }
            if (j >= 0 && b[j] == '1') {
                valb = 1;
            }
            sum = vala + valb + carry;
            ans += '0' + sum % 2;
            carry = sum / 2;
            i--, j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
