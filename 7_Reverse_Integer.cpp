//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//Example2: x = -123, return -321
//
//click to show spoilers.
//
//Note:
//The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows. 
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
  public:
    int reverse(const int x) {
      bool ispositive = true;
      x>0 ? ispositive=true : ispositive=false;
      stringstream ss;
      ss << x;
      string text;
      ss >> text;
      ss.str("");
      ss.clear();

      string ans;
      if (ispositive) {
        for (int i = text.size()-1; i >= 0; i--) ans += text[i];
        ss << ans;
      }
      else {
        for (int i = text.size()-1; i > 0; i--) ans += text[i];
        ss << ("-" + ans);
      }
      long long final_res;
      ss >> final_res;
      if (final_res > (~(1<<31)) || final_res < (1<<31)) return 0; //max = ~(1<<31) min = (1<<31)
      return final_res;
    }
};

int main () {
  Solution s;
  cout << s.reverse(1463847412);
}
