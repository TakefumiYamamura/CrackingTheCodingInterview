#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

class Robofactory
{
public:
  int reveal(vector <int> query, vector <string> answer){
    for (int i = 0; i < query.size(); ++i)
    {
      if(answer[i] == "Even"){
        if(query[i] % 2 != 0) return i;
      }else{
        if(query[i] % 2 != 1) return i;
      }
      if(i == query.size() - 1) continue;
      if(query[i] % 2 == 0) return -1;
    }
    return 0;
  }
};
