#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void BoyerMoore(string text,string pattern){
  int n = text.length();
  int m = pattern.length();
  unordered_map<char,int> badChar;
  for (int i = 0; i < m; ++i)
  {
    badChar[pattern[i]] = i;
  }
  int s = 0;
  while(s <= n-m){
    int j = m-1;
    while(j >= 0 && pattern[j] == text[s+j]){
      j--;
    }
    if(j < 0){
      cout << "Pattern found at index " << s << endl;
      s += (s+m < n) ? m-badChar[text[s+m]] : 1;
    }else{
      s += max(1,j-badChar[text[s+j]]);
    }
  }
}

