class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
       stack<int>s;
       vector<string>res;
       int j = 0;
    
       for(int i = 1; i<=n && j<target.size(); i++){
        s.push(i);
        res.push_back("Push");
        if(s.top() != target[j]){
            s.pop();
            res.push_back("Pop");
        }else{
            j++;
        }
       }
       return res;
    }
};