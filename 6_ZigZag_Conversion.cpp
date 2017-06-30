//tring "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//
//And then read line by line: "PAHNAPLSIIGYIR"
//
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string text, int nRows);
//
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    string convert(const string s, const int numRows) {
      if (numRows == 1 || s.size() <= numRows) return s;
      const int cap = numRows*2-2;
      const int len = s.size();
      string ans;
      ans.reserve(len+1); //注意resize与reserve的区别

      int cnt = 0;
      while (cnt < len) {  //注意cnt不能等于len
        ans += s[cnt];
        cnt += cap;
      }

      for (auto i=1; i<numRows-1; i++) {
        cnt = i;
        while (cnt < len) {
          ans += s[cnt];
          if (cnt+cap-2*i < len) ans += s[cnt+cap-2*i]; //小心数组越界
          cnt += cap;
        }
      }

      cnt = numRows-1;
      while (cnt < len) {
        ans += s[cnt];
        cnt += cap;
      }
      return ans;
    }
};


int main () {
  Solution s;
  cout << s.convert("ABCD", 2) << endl;
  cout << s.convert("ABC", 2) << endl;
  cout << s.convert("ABC", 3) << endl;
  cout << s.convert("ABC", 2) << endl;
}
