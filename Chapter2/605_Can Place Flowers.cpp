class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {     
        for (int i = 0; i < flowerbed.size() ; i += 2) {
            if (flowerbed[i] == 0) {
                if (i == flowerbed.size() - 1 || flowerbed[i+1] == 0) {
                    --n;
                }
                else {
                    ++i;
                }
            }
        }
        return n <= 0; 
    }
};
