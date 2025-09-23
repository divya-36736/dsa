class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = version1.size();
        int v2 = version2.size();
        int i = 0;
        int j = 0;

        while(i<v1 || j<v2){
            long num1 = 0;
            long num2 = 0;
            //extract number from version 1
            while(i<v1 && version1[i] != '.'){
                num1 = num1*10+ (version1[i] - '0');
                i++;
            }
            //extract number from version2
            while(j<v2 && version2[j] != '.'){
                num2 = num2*10 + (version2[j] - '0');
                j++;
            }
            if(num1>num2) return 1;
            else if (num1 < num2) return -1;
            //if '.'
            i++;
            j++;
        }
        return 0;
    }
};