class Solution {
public:
    int nums(char c){
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        else return 1000;
    }
    int romanToInt(string s) {
        int n  = s.size();
        int idx = 0;
        int sum = 0;

        while(idx<(n-1)){
            if(nums(s[idx])<nums(s[idx+1])){
                //ydi less hoga toh hum - kr rhe hai
                sum -= nums(s[idx]);
            }else{
                sum += nums(s[idx]); 
            }
            idx++;
        }
        //last n-1 elemets rah rha tha
        sum += nums(s[n-1]);
        return sum;
    }
};