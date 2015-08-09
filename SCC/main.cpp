#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector <int> graph[875720];
vector <int> nGraph[875720];

bool visited[875720];
int finshed[875720];
int t = 0;
int len = 0;

void dfs(int u)
{
    visited[u] = 1;
    for(int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(!visited[v])
            dfs(v);
    }
    t += 1;
    finshed[u] = t;
}

void dfs1(int u)
{
    visited[u] = 1;
    len += 1;
    for(int i = 0; i < nGraph[u].size(); i++)
    {
        int v = nGraph[u][i];
        if(!visited[v])
            dfs1(v);
    }
}
int main()
{
    freopen("SCC.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
//    freopen("in.txt", "r", stdin);
    int a, b;
    while(cin >> a >> b)
        graph[a].push_back(b);
    //magical order
    for(int i = 875714; i > 0; i--)
    {
        if(!visited[i])
            dfs(i);
    }

    //change order of nodes
    vector <int> tmp[875720];
    for(int i = 1; i <= 875714; i++)
    {
        int n = finshed[i];
        for(int j = 0; j < graph[i].size(); j++)
        {
            int nV = finshed[graph[i][j]];
            tmp[n].push_back(nV);
        }
    }

    // reverse edges
    for(int i = 1; i <= 875714; i++)
    {
        for(int j = 0; j < tmp[i].size(); j++)
        {
            int v = tmp[i][j];
            nGraph[v].push_back(i);
        }
    }
    memset(visited, 0, sizeof visited);
    vector <int> ans;
    for(int i = 875714; i > 0; i--)
    {
        if(!visited[i])
        {
            len = 0;
            dfs1(i);
            ans.push_back(len);
        }
    }

    sort(ans.rbegin(), ans.rend());
    if(ans.size() >= 5)
    {
        for(int i = 0; i < 5; i++)
            cout << ans[i] <<",\n"[i == 4];
    }
    else
    {
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << ",";
        int rem = 5 - ans.size();
        for(int i = 0; i < rem; i++)
            cout << 0 << ",\n"[i==rem-1];
    }

    return 0;
}
