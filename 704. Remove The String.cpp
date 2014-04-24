/********************************************************
*      Md. Khairullah Gaurab                            *
*      Computer Science & Engineering                   *
*      Shahjalal University of Science and Technology   *
*      20th Batch                                       *
*      gaurab.cse.sust@gmail.com                        *
*********************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>

#define sf scanf
#define pf printf

using namespace std;
const int mx = 10009;
const int my = 1009;

int lenX, lenY, prep[my][26], LPS[my], dp[mx][my];
char X[mx], Y[my];

void computeLPSArray()
{
    int i, k;
    LPS[0] = LPS[1] = k = 0;
    for(i=2; i<=lenY; i++)
    {
        while(k>0 and Y[i]!=Y[k+1]) k = LPS[k];
        if(Y[i]==Y[k+1]) k++;
        LPS[i] = k;
    }
}

int KMP()
{
    int i, j, k;
    computeLPSArray();
    for(i=0; i<lenY; i++)
    {
        for(char c='a'; c<='z'; c++)
        {
            k = i;
            while(k>0 and Y[k+1]!=c) k = LPS[k];
            if(Y[k+1]==c) k++;
            prep[i][c-'a'] = k;
        }
    }
    for(i=0; i<=lenX; i++) dp[i][lenY] = (0x7fffffff);
    for(i=0; i<lenY; i++) dp[lenX][i] = 0;

    for(i=lenX-1; i; i--)
    {
        for(j=lenY-1; j>=0; j--)
        {
            dp[i][j] = 1 + dp[i+1][j];
            int next = dp[i+1][prep[j][X[i]-'a']];
            if(dp[i][j]>next) dp[i][j] = next;
        }
    }
    return dp[1][0];
}

int main(int argc, const char *argv[])
{
    while(gets(&X[1]))
    {
        gets(&Y[1]);
        lenX = strlen(&X[1]) + 1;
        lenY = strlen(&Y[1]);
        int ret = KMP();
        printf("%d\n", ret);
    }
    return 0;
}
