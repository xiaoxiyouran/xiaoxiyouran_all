//哈希函数 H(k)=3*k MOD length
#pragma warning(disable:4996)
#include<stdio.h>  
#include<string.h>  
#include<iostream>
#include<functional>
#include<queue>
#include<set>
#include<string>
#include<unordered_map>
#include<map>
#include<array>
#include<algorithm>
#include<stack>
using namespace std;
int table[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
long long int GetNum(const char* dt, int l,int r, int jz)
{
 long long int ans = 0;
 for(int i = l; i <= r; ++i)
 {
  int temp = 0;
  if(dt[i] >='A' && dt[i] <= 'F')
  {
    temp = table[dt[i] - 'A' + 10];
  }
  else
  {
   temp = table[dt[i] - '0'];
  }
  if (temp >= jz) return -1;
  ans *= jz;
  ans += temp;
 }
 return ans;
}
char dt[1000];
int main()
{
 int t, x, y;
 cin >> t;
 while(t--)
 {
  cin >> x >> y >> dt;
  int len = strlen(dt);
  for(int i = 0; i < len-1; ++i)
  {
   long long a = GetNum(dt, 0, i, x);
   long long b = GetNum(dt, i + 1, len - 1, y);
   if(a == b)
   {
    cout << a << endl;
    break;
   }
  }
 }
}

/*output:
3
5 2 113221101000101
13 7 1016
4 12 2222248A

837
13
682
*/