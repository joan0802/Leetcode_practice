class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = -1, r = 1;
        int len = flowerbed.size();
        for(int cur = 0; cur < len; ++cur) {
            if(len == 1)
                return (n > 1) ? false : (flowerbed[cur] == 0 || n == 0) ? true : false;
            if(r >= len) {
                if(flowerbed[l] == 0 && flowerbed[cur] == 0)
                    n--;
            }
            else if(l < 0) {
                if(flowerbed[r] == 0 && flowerbed[cur] == 0) {
                    n--;
                    flowerbed[cur] = 1;
                }
            }
            else if(flowerbed[l] == 0 && flowerbed[r] == 0 && flowerbed[cur] == 0) {
                n--;
                flowerbed[cur] = 1; 
            }
            l++, r++;
        }
        cout << "n = " << n << endl;
        return (n > 0) ? false : true;
    }
};