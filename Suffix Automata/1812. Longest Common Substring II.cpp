/*
 * 1812. Longest Common Substring II.cpp
 *
 *  Created on: Oct 1, 2014
 *      Author: ddxofy
 */
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

using namespace std;

const int inf = 2000000000;
const int MOD = 10007;

typedef long long Long;
typedef double DD;

#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define SZ(s) ((int)s.size())
#define PI 3.141592653589793
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<DD>
#define VLL         vector<Long>
#define lim 200005
#define unq(vec) stable_sort(vec.begin(),vec.end());\
vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    stable_sort(BE(a))
#define sortc(a)    sort(BE(a),comp)

#define MAXN 150010
char A[MAXN];
int RES;
struct SAM {
	int tot, last, idx;
	int go[MAXN << 1][26], pre[MAXN << 1], step[MAXN << 1], DP[15][MAXN << 1];

	void new_node(int s) {
		step[++tot] = s;
		pre[tot] = 0;
		memset(go[tot], 0, sizeof go[tot]);
	}

	void build(char* s) {
		tot = 0;
		last = 1;
		new_node(0);
		int n = strlen(s);
		REP(i, 0, n - 1)
		{
			new_node(step[last] + 1);
			int c = s[i] - 'a';
			int p = last, np = tot, q, nq;
			for (; p && !go[p][c]; p = pre[p])
				go[p][c] = np;
			if (!p)
				pre[np] = 1;
			else {
				q = go[p][c];
				if (step[q] == step[p] + 1)
					pre[np] = q;
				else {
					new_node(step[p] + 1);
					nq = tot;
					memcpy(go[nq], go[q], sizeof go[q]);
					pre[nq] = pre[q];
					pre[np] = pre[q] = nq;
					for (; p && go[p][c] == q; p = pre[p])
						go[p][c] = nq;
				}
			}
			last = np;
		}
		REP(i,1,tot)
			DP[0][i] = step[i];
	}
	void match(char* s) {
		idx++;
		int p = 1, len = 0;
		int n = strlen(s);
		REP(i, 0, n - 1)
		{
			int c = s[i] - 'a';
			while (pre[p] && !go[p][c]) {
				p = pre[p];
				len = step[p];
			}
			if (go[p][c]) {
				p = go[p][c];
				len++;
				DP[idx][p] = max(DP[idx][p], min(DP[idx - 1][p], len));
				for (int j = pre[p]; pre[j]; j = pre[j]) {
					if (DP[idx][j] >= DP[idx - 1][j])
						break;
					DP[idx][j] = DP[idx - 1][j];
				}
			}
		}
		RES = *max_element(DP[idx] + 1, DP[idx] + tot + 1);
	}
};

SAM run;

int main(int argc, const char **argv) {
	sf("%s", A);
	run.build(A);
	RES = strlen(A);
	while (~sf("%s", A)) {
		run.match(A);
	}
	pf("%d\n", RES);
	return 0;
}

