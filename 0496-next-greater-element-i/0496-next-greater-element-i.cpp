class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        vector<int>NG;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i = 0; i<n1; i++){
            while(!s.empty()) s.pop();
           for(int j = n2-1; j>=0; j--){
            if(nums1[i] == nums2[j]){
                while(!s.empty() && s.top() <= nums2[j]){
                    s.pop();
                }
                if(s.empty()){
                    NG.push_back(-1);
                }else{
                    NG.push_back(s.top());
                }
                break;
            }
            s.push(nums2[j]);
           } 
        }
        return NG;
    }
};