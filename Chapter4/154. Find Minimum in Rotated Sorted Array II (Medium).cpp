class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] == nums[right]) {
                right--;
            } else if (nums[left] < nums[right]) {
                right = left;
            } else if (nums[left] > nums[right]) {
                int mid = left + (right - left) / 2;
                if (nums[mid] >= nums[left]) left = mid + 1;
                else {
                    right = mid;
                }
            }
        }
        return nums[left];
    }
};
