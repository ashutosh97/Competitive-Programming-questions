#include <bits/stdc++.h>
using namespace std;

void primsMST(vector<pair<int, int>> graph[], int V)
{
    int weightTotal = 0;
    int m = V - 1;
    int cnt = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int visited[V] = {0}, parent[V] = {-1};

    visited[0] = 1;
    for (int j = 0; j < graph[0].size(); j++)
    {
        int v = graph[0][j].first;
        int w = graph[0][j].second;

        if (!visited[v])
            pq.push({w, v}), parent[v] = 0;
    }

    while (!pq.empty() && cnt != m)
    {
        pair<int, int> node = pq.top();
        pq.pop();
        int u = node.second;
        int weight = node.first;

        if (visited[u])
            continue;

        visited[u] = 1;
        weightTotal += weight;
        cnt++;

        for (int j = 0; j < graph[u].size(); j++)
        {
            int v = graph[u][j].first;
            int w = graph[u][j].second;

            if (!visited[v])
                pq.push({w, v}), parent[v] = u;
        }
    }

    if (cnt != m)
        cout << "MST not possible.\n";
    else
    {
        cout << weightTotal << endl;
        for (int i = 1; i < V; i++)
            cout << parent[i] << " " << i << endl;
    }
}

int main()
{
    int V = 9;
    vector<pair<int, int>> graph[V];

    graph[0].push_back({1, 4});
    graph[0].push_back({7, 8});
    graph[1].push_back({2, 8});
    graph[1].push_back({7, 11});
    graph[2].push_back({3, 7});
    graph[2].push_back({8, 2});
    graph[2].push_back({5, 4});
    graph[3].push_back({4, 9});
    graph[3].push_back({5, 14});
    graph[4].push_back({5, 10});
    graph[5].push_back({6, 2});
    graph[6].push_back({7, 1});
    graph[6].push_back({8, 6});
    graph[7].push_back({8, 7});
    primsMST(graph, V);
    return 0;
}
