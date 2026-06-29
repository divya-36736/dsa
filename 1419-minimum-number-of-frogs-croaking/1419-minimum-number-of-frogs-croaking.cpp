class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();
        int c = 0, r = 0, o = 0, a= 0, k = 0;
        int frog = 0;
        int maxfrog = 0;
        for(char &ch:croakOfFrogs){
            if(ch == 'c'){
                c++;
                frog++;
            }
            else if(ch == 'r') r++;
            else if(ch == 'o') o++;
            else if(ch == 'a') a++;
            else if(ch == 'k'){
                k++;
                frog--;
            }
            else{
                return -1; //any other character
            }
            maxfrog = max(maxfrog, frog);
            if(c < r || r<o || o<a || a<k) return -1;
        }

        if(frog == 0 && c == r && r == o && o == a && a == k) return maxfrog;
        return -1;
    }
};