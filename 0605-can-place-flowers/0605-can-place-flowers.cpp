class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // int m = flowerbed.size();
        
        // if (m >= 1 && flowerbed[0] == 0 && (m == 1 || flowerbed[1] != 1)) {
        //     flowerbed[0] = 1;
        //     n--;
        // }

        // if (m >= 2 && flowerbed[m-1] == 0 && flowerbed[m-2] != 1) {
        //     flowerbed[m-1] = 1;
        //     n--;
        // }

        // int i = 1;
        // while (i < m-1 && n > 0) {
        //     if (flowerbed[i] == 0 && flowerbed[i-1] != 1 && flowerbed[i+1] != 1) {
        //         flowerbed[i] = 1;
        //         n--;
        //     }
        //     i++;
        // }

        // return n <= 0;


        int m = flowerbed.size();
        for (int i = 0; i < m && n > 0; i++) {
            if (flowerbed[i] == 0) {
                int prev = (i == 0 ? 0 : flowerbed[i-1]);
                int next = (i == m-1 ? 0 : flowerbed[i+1]);
                
                if (prev == 0 && next == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n == 0;
    }
};
