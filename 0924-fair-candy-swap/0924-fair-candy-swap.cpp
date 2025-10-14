// class Solution {
// public:
//     vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
//         int a = aliceSizes.size();
//         int b = bobSizes.size();
//         int i = 0;
//         int j = 0;
//         int b1 = 0;
//         int a1 = 0;
//         while(i<a || j<b){
//             if(i<a && j<b){ //when both
//                 b1 += bobSizes[j];
//                 a1 += aliceSizes[i];
//                 j++;
//                 i++;
//             }
//             else if(i<a){ //when only alice
//                 a1 += aliceSizes[i];
//                 i++;
//             }
//             else{ //when only bob
//                 b1 += bobSizes[j];
//                 j++;
//             }
//         }
//         int dif = a1-b1;
//         dif = dif/2;
//         for(int i = 0; i<a; i++){
//             for(int j = 0; j<b; j++){
//                 if(aliceSizes[i]-bobSizes[j] == dif){
//                     return {aliceSizes[i], bobSizes[j]};
//                 }
//             }
//         }
//         return {};

//     }
// };

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0, sumB = 0;
        for (int a : aliceSizes) sumA += a;
        for (int b : bobSizes) sumB += b;
        
        int delta = (sumA - sumB) / 2;
        unordered_set<int> setB(bobSizes.begin(), bobSizes.end());
        
        for (int a : aliceSizes) {
            int b = a - delta;
            if (setB.count(b)) return {a, b};
        }
        return {};
    }
};