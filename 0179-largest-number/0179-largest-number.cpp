class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        //convert to string
        vector<string>arr;
        for(int n:nums) arr.push_back(to_string(n));
        //sort now with comparision
        sort(arr.begin(), arr.end(), [](string &a, string &b){
            return a+b > b+a; //comparison according to this 
        });
        if(arr[0] == "0") return "0";

        //add all strings
        string result = "";
        for(string &r : arr){
            result += r;
        }
        return result;
    }
};