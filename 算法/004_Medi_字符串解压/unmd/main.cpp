#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, string> &pair1, const pair<int, string> &pair2) {
  if (pair1.first < pair2.first)
    return true;
  else if (pair1.first > pair2.first)
    return false;
  else {
    if (pair1.second.size() < pair2.second.size())      // 比较数字的位数
      return true;
    else if (pair1.second.size() > pair2.second.size()) // 比较数字的个数
      return false;
    else
      return pair1.second <= pair2.second;
  }

}

int main() {
  string s;
  cin >> s;
  vector<pair<int, string>> v;
  int i = 0;
  while(i < s.size()) {
    int start = i;
    pair<int, string> p;
    while (s[i] < '0' || s[i] > '9') {      // 非数字
      ++i;
    }
    p.second = s.substr(start, i - start);
    start = i;
    while (s[i] >= '0' && s[i] <= '9') {    // 检测数字的
      ++i;
    }
    p.first = stoi(s.substr(start, i - start));
    v.push_back(p);
  }

  sort(v.begin(), v.end(), compare);

  string res;

  for (auto p : v) {
    for (int i = 0; i < p.first; ++i)
      res += p.second;
  }

  cout << res;
  return 0;
}