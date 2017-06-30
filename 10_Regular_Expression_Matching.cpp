//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//  Some examples:
//  isMatch("aa","a") → false
//  isMatch("aa","aa") → true
//  isMatch("aaa","aa") → false
//  isMatch("aa", "a*") → true
//  isMatch("aa", ".*") → true
//  isMatch("ab", ".*") → true
//  isMatch("aab", "c*a*b") → true (c*0 + a*2 + b*1)
#include <iostream>
using namespace std;

class Solution {
  public:
    bool isMatch(string s, string p) {
      uint32_t ptr_s = 0;
      uint32_t ptr_p = 0;
      uint32_t len_s = s.size();
      uint32_t len_p = p.size();

      while (ptr_p != len_p) {
        if (ptr_p != len_p-1) {
          if (p[ptr_p+1] != *) {
            if (p[ptr] == '.' || p[ptr_p] == s[ptr_s]) {
              ptr_p ++;
              ptr_s ++;
            }else {
              return false;
            }
          }else {
            while (

    }
};

int main () {

