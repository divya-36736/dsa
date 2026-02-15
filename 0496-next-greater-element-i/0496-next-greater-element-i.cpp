class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int>st;
        vector<int>ans;
        for(int i = 0; i<n1; i++){
            while(!st.empty()) st.pop();
            for(int j = n2-1; j>=0; j--){
                if(nums1[i] == nums2[j]){
                    while(!st.empty() && st.top() < nums2[j]){
                        st.pop();
                    }
                    if(st.empty()){
                        ans.push_back(-1);
                    }
                    else{
                        ans.push_back(st.top());
                    }
                    break;
                }

                st.push(nums2[j]);
            }
        }
        return ans;
    }
};