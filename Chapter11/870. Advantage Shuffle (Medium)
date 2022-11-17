class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<int> ids(n); 
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return nums2[i] < nums2[j];
            });
        int left = 0, right = n - 1;
        vector<int> ans(n);
        for (int num: nums1) {
            if (num > nums2[ids[left]]) {
                ans[ids[left++]] = num;
            } else {
                ans[ids[right--]] = num;
            }
        }
        return ans;
    }
};
