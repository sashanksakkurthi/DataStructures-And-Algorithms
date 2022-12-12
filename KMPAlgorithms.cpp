// kmp pattern matching algorithm

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void findKMP(string text,string pattern){
  int n = text.length();
  int m = pattern.length();
  int lps[m];
  lps[0] = 0;
  int i = 1;
  int len = 0;
  while(i < m){
    if(pattern[i] == pattern[len]){
      len++;
      lps[i] = len;
      i++;
    }else{
      if(len != 0){
        len = lps[len-1];
      }else{
        lps[i] = 0;
        i++;
      }
    }
  }
  i = 0;
  int j = 0;
  while(i < n){
    if(text[i] == pattern[j]){
      i++;
      j++;
    }
    if(j == m){
      cout << "Pattern found at index " << i-j << endl;
      j = lps[j-1];
    }else if(i < n && text[i] != pattern[j]){
      if(j != 0){
        j = lps[j-1];
      }else{
        i++;
      }
    }
  }
}

