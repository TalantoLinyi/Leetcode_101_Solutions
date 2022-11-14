class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, two = nums.size() - 1;
        for (int i = 0; i <= two; ++i) {
            if(nums[i] == 0) swap(nums[i], nums[zero++]);
            else if (nums[i] == 2) swap(nums[two--], nums[i--]);
        }   
    }
};
