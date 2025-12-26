class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int op = operations.size();
        int x = 0;
        for(string s: operations){
            if(s == "++X"){
                ++x;
            }
            else if(s == "X++"){
                x++;
            }
            else if(s  == "--X"){
                --x;
            }
            else{
                x--;
            }
        }
        return x;
    }
};