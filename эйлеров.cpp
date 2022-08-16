#include <iostream>
#include <vector>

using namespace std;
int n;
vector <vector <int> > graph;
vector<bool> visit;
vector<int> result;

void dfs(int v)
{
    visit[v] = true;
    for (int j = 0; j < 2; j++)
    {
        int next = graph[v][j];
        if (!visit[next])
            dfs(next);
    }
    result.push_back(v);
}

int main(void)
{
    cin >> n;
    graph.resize(n-1);
    visit.resize(n-1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--, v--;

        graph[u][v] = graph[v][u] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (!visit[i])
        {
            result.clear();
            dfs(i);
            for (int j = 0; j < (2 * n - 1); j++)
                cout << result[j] << endl;
        }
    }
    return 0;
}


