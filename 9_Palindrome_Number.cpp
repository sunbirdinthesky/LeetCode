//Determine whether an integer is a palindrome. Do this without extra space.

class Solution {
  public:
    bool isPalindrome(int x) {
      if (x%10 == 0 && x != 0) return false;
      if (x < 0) return false;
      int tmp = 0;
      int swap = x;
      while (swap != 0) {
        tmp *= 10;
        tmp += swap%10;
        swap /= 10;
      }
      return tmp == x;
    }
};
