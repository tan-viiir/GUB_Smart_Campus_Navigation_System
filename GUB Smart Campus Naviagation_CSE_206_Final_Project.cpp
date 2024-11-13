#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+123;
bool vis[mx];
vector<int> adj1[mx];

void make(int n, int m, vector<vector<int>>&edges)
{
    for (auto it : edges)
        {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
}

void dfs(int u){

    vis[u] = 1;

    for(auto v: adj1[u]){
        if(vis[v] == 0){
            dfs(v);
        }
    }
}

class Mapis
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges, int src, int end_node)
    {
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n + 1, 1e9), parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        dist[src] = 0;

        pq.push({0, src});
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        if (dist[n] == 1e9)
            return {-1};

        vector<int> path;
        int node = end_node;

        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(src);

        reverse(path.begin(), path.end());
        return path;
    }
};

int main()
{
    cout << "*****Welcome to Green University Smart Campus Navigation*****" << endl << endl;

    cout << "Here the list of Building" << endl << endl;
    cout << "1. Building E" << endl;
    cout << "2. Building F" << endl;
    cout << "3. Building G" << endl;
    cout << "4. Building H" << endl;
    cout << "5. Building J" << endl;
    cout << "6. Building K" << endl;
    cout << "7. Building L" << endl << endl;

    int check = 1;
    while( check == 1){
        cout << "Where are you?" << endl;
        cout << "At Building: ";

        char start_node;
        cin >> start_node;
        switch(start_node){
        case 'E':
            start_node = 1;
            break;
        case 'F':
            start_node = 2;
            break;
        case 'G':
            start_node = 3;
            break;
        case 'H':
            start_node = 4;
            break;
        case 'I':
            start_node = 5;
            break;
        case 'K':
            start_node = 6;
            break;
        case 'L':
            start_node = 7;
            break;
        }

        cout << "Where do you want to go?" << endl;
        cout << "At Building: ";

        char end_node;
        cin >> end_node;
        switch(end_node){
        case 'E':
            end_node = 1;
            break;
        case 'F':
            end_node = 2;
            break;
        case 'G':
            end_node = 3;
            break;
        case 'H':
            end_node = 4;
            break;
        case 'J':
            end_node = 5;
            break;
        case 'K':
            end_node = 6;
            break;
        case 'L':
            end_node = 7;
            break;
        }
        int V = 7, E = 11;
        vector<vector<int>> edges = {{1, 2, 4}, {1, 3, 4}, {2, 3, 2}, {3, 4, 6}, {3, 5, 6},
        {3, 6, 4}, {6, 5, 3}, {4, 5, 2}, {2, 7, 1},{3, 7, 5},{6, 7, 2}};

        make(V, E, edges);
        dfs(1);
        if(vis[end_node] == 0){
            cout << endl;
            cout << "**You are at the moon.**" << endl;
            cout << "Please come back to Green University of Bangladesh." << endl;
        }
        else{
        Mapis obj;
        vector<int> path = obj.shortestPath(V, E, edges, start_node, end_node);

        cout << "You are at " ;
        for (int i = 0; i < path.size(); i++)
        {
            switch(path[i]){
            case 1:
                cout << "Building: E" << endl;
                break;
            case 2:
                cout << "Building: F" << endl;
                break;
            case 3:
                cout << "Building: G" << endl;
                break;
            case 4:
                cout << "Building: H" << endl;
                break;
            case 5:
               cout << "Building: J" << endl;
                break;
            case 6:
                cout << "Building: K" << endl;
                break;
            case 7:
                cout << "Building: L" << endl;
                break;
            }

            if(i < path.size() - 1)
            cout << "Then move ";
        }
        cout << endl;
        }
        cout << "Press one to continue. " << endl;
        cout << "Pres any any digit except 1 to exit." << endl;
        int a;
        cin >> a;
        check = a;
    }

    cout << endl;
    return 0;
}
