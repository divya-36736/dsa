class Solution {
    public String largestEven(String s) {
        int n = s.length();
        for(int i = n-1; i>=0; i--){
            int lastDigit = s.charAt(i)-'0';
            if(lastDigit % 2 == 0){
                return s.substring(0, i+1);
            }
        }
        return "";
    }
}