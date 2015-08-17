#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll OO = 1000000;
const int len = 200;

ll adjMatrix[207][207];
bool visited[207];
int node[] = {7,37,59,82,99,115,133,165,188,197};

int minDistance(vector <ll>&dist, bool visited[])
{
    ll minn = OO;
    int ans;
    for(int i = 1; i <= len; i++)
    {
        if(!visited[i] && dist[i] <= minn)
        {
            minn = dist[i];
            ans = i;
        }
    }
    return ans;
}
int main()
{
    freopen("dijkstraData.txt", "r", stdin);
    string s;
    ll n, m, w;
    while(cin >> s)
    {
        bool f = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ',')
                f = 1;
        }
        if(!f)
            n = atoll(s.c_str());
        else
        {
            string curr = "";
            bool f1 = 0;
            for(int i  = 0; i < s.size(); i++)
            {
                if(s[i] == ',')
                {
                    m = atoll(curr.c_str());
                    f1 = 0;
                    curr = "";
                    continue;
                }
                curr += s[i];
            }
            w = atoll(curr.c_str());
        }
        if(f)
            adjMatrix[n][m] = w;
    }

    vector <ll> dist(len+1, OO);
    dist[1] = 0;
    for(int i = 1; i <= len; i++)
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for(int j = 1; j <= len; j++)
        {
            int curr = dist[u] + adjMatrix[u][j];
            if(!visited[j] && adjMatrix[u][j] && dist[u] != OO && curr < dist[j])
               dist[j] = curr;
        }
    }
    for(int i = 0; i < 10; i++)
        cout << dist[node[i]] << ",\n"[i==9];
    return 0;
}
