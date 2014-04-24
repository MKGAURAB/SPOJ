/********************************************************
*      Md. Khairullah Gaurab                            *
*      Computer Science & Engineering                   *
*      Shahjalal University of Science and Technology   *
*      20th Batch                                       *
*      gaurab.cse.sust@gmail.com                        *
*********************************************************/
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <utility>
#include <cstdio>

#define sf scanf
#define pf printf

using namespace std;

vector<int> res;
int plen, slen;
string pat, hay;

void computeLPSArray(int *LPS)
{
    int i, len;
    LPS[0] = len = 0;
    i = 1;
    while(i<plen)
    {
        if(pat[i]==pat[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else{
            if(len!=0)
            {
                len = LPS[len-1];
            }
            else{
                LPS[i] = 0;
                i++;
            }
        }
    }
}
void KMP()
{
    int i, j;
    slen = hay.length();
    res.clear();
    int *LPS = (int *)malloc(sizeof(int)*plen);
    computeLPSArray(LPS);
    i=j=0;
    while(i<slen)
    {
        if(hay[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==plen)
        {
            res.push_back(i-j);
            j = LPS[j-1];
        }
        else if(hay[i]!=pat[j])
        {
            if(j!=0) j = LPS[j-1];
            else i++;
        }
    }
    free(LPS);
}
int main(int argc, const char *argv[])
{
    while(cin>>plen>>pat>>hay){
            KMP();
            int k = res.size();
            if(k==0) pf("\n");
            for(int i=0; i<k; i++)
            {
                pf("%d\n",res[i]);
            }
            pf("\n");
    }
    return 0;
}


