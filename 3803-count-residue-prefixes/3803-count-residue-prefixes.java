class Solution {
    public int residuePrefixes(String s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i<n; i++){
            ArrayList<Integer> arr = new ArrayList<>(Collections.nCopies(26, 0));
            int cnt = 0;

            for(int j = 0; j<=i; j++){
                int idx = s.charAt(j) - 'a';
                if(arr.get(idx) == 0){
                    cnt++;
                }
                arr.set(idx, arr.get(idx)+1);
            }
            if(cnt == (i+1)%3) ans++;
        }
        return ans;
    }
}