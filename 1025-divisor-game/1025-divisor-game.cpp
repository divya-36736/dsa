class Solution {
public:
    bool divisorGame(int n) {
        //if n is even the  alice take 1 and leave odd for bob
        //if n is odd then alice take 1 and leave even for bob;
        //thus we can say alice wins if and if n is enen
        if(n%2 == 0){
            return true;
        }
        else return false;
    }
};