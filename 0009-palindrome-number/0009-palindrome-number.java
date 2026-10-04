class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) return false;

        int original = x;
        int r = 0;
        while(x>0){
            int ans = x%10;
            if (r > Integer.MAX_VALUE / 10 ||
                r < Integer.MIN_VALUE / 10) {
                return false;
            }
            r = ans + r*10;
            x /= 10;
        }
        if(r == original) return true;
        return false;
    }
}