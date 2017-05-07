#include <bits/stdc++.h>

using namespace std;

vector <int> L[100010];

ifstream fin("dfs.in");
ofstream fout("dfs.out");

int n,m;
int x,y;
int nr = 0;
bitset <100010> visited;

void DFS(int node) {
    visited[node] = 1;
    for (int i = 0; i < L[node].size(); i++)
        if (visited[ L[node][i] ] == 0)
            DFS(L[node][i]);

}

int main() {

    fin >> n >> m;

    for (int i = 1; i <= m; i++) {
        fin >> x >> y;
        L[x].push_back(y);
        L[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            DFS(i);
            nr++;
        }
    }
    fout << nr;


}
