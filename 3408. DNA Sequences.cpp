//Md. Khairullah Gaurab
//CSE, SUST  20th
//gaurab.cse.sust@gmail.com

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>


#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define all(a) (a.begin(),a.end())
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define unq(vec) stable_sort(vec.begin(),vec.end());\
                 vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));

using namespace std;

typedef long long Long;
typedef double dd;

const Long MOD = 1000000007;
const int SZ = 1000+5;

//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

char st1[SZ], st2[SZ];
int dp[SZ][SZ], conse[SZ][SZ];
int main(int argc, const char **argv)
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int K;
    while(sf("%d",&K)==1 and K)
    {   mem(dp,0);mem(conse,0);
        sf("%s %s",st1,st2);
        int l1 = strlen(st1);
        int l2 = strlen(st2);
        REP(i,1,l1)REP(j,1,l2)if(st1[i-1]==st2[j-1])conse[i][j] = conse[i-1][j-1] + 1;
        REP(i,1,l1)REP(j,1,l2)
        {
            int match = conse[i][j]; dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            if(match>=K) dp[i][j] = max(dp[i-K][j-K]+K,dp[i][j]);
            if(match>K) dp[i][j] = max(dp[i-1][j-1]+1,dp[i][j]);
        }
        pf("%d\n",dp[l1][l2]);
    }
    return 0;
}




