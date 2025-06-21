class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int>s;
        vector<int>NG(n1, 0);
        
        for(int i = n1-1; i>=0; i--){
            while(!s.empty()) s.pop();
           for(int j = n2-1; j>=0; j--){
            if(nums1[i] == nums2[j]){
                while(!s.empty() && s.top() <= nums2[j]){
                    s.pop();
                }
                if(s.empty()){
                    NG[i] = -1;
                }else{
                    NG[i] = s.top();
                }
                break;
            }
            s.push(nums2[j]);
           } 
        }
        return NG;
    }
};