class Solution {
    public int compress(char[] chars) {
        int n = chars.length;
        int idx = 0;
        int i = 0;
        while(i<n){
            char ch = chars[i];
            int cnt = 0;
            while(i<n && ch == chars[i]){
                cnt++;
                i++;
            }
            chars[idx++] = ch;
            if(cnt > 1){
                String str = String.valueOf(cnt);
                for(char c: str.toCharArray()){
                    chars[idx++] = c;
                }
            }
        }
        return idx;
    }
}