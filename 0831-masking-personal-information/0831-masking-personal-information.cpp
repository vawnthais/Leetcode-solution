
class Solution {
public:
   string maskPII(string s) {
      int ind = s.find('@');
      if (ind != string::npos) { 
         if (s[0] == '.' or s.back() == '.') return s;
         for (char &c : s) c = tolower(c);
         return string(1, s[0]) + "*****" + s.substr(ind -1);
      }

      string new_s = "";
      for (char c : s) {
         if (isdigit(c)) new_s += c;
      }
      if (new_s.size() == 10) return "***-***-" + new_s.substr(new_s.size() - 4);
      string count = "+";
      for ( int i = 0; i < new_s.size() - 10; i++) {
         count += "*";
      }
      return count + "-***-***-" + new_s.substr(new_s.size() - 4);
   }
};
