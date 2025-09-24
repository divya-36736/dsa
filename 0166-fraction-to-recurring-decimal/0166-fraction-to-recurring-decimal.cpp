class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
      if(numerator == 0) return "0";
      string res;

      if((numerator<0) ^ (denominator<0)) res += "-";

      long long n = llabs((long long)numerator);
      long long d = llabs((long long)denominator);

      res += to_string(n/d);
      long long rem = n%d;

      if(rem == 0) return res;
      res += '.';
      //to store the remainder->position
      unordered_map<long long, int>seen;

      while(rem != 0){
        if(seen.find(rem) != seen.end()){
            //insert with bracket
            res.insert(seen[rem], "(");
            res+=")";
            break;
        }
        seen[rem] = res.size();
        rem = rem*10;
        res += to_string(rem/d);
        rem %= d; 
      }
      return res;
    }
};