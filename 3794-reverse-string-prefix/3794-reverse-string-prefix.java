class Solution {
    public String reversePrefix(String s, int k) {

        String prefix = s.substring(0, k);
        StringBuilder sb = new StringBuilder(prefix);
        sb.reverse();

        sb.append(s.substring(k));
        return sb.toString();
    }
}
