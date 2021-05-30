#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int vertices, edges;
vector<vector<int> > graph;
void graphinput()
{
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < vertices; i++)
    {
        graph.push_back(vector<int>());
        for (int j = 0; j < vertices; j++)
        {
            graph[i].push_back(0);
        }
    }
    cout << "Enter connected vertices two at a time(those joined by edges): " << endl;
    int vert1, vert2;
    for (int i = 0; i < edges; i++)
    {
        cin >> vert1 >> vert2;
        graph[vert1 - 1][vert2 - 1] = 1;
        graph[vert2 - 1][vert1 - 1] = 1;
    }
}
bool isconnected()
{
    bool f = 0;
    vector<int> visiting;
    vector<int> visited;
    visiting.push_back(2);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (graph[visiting[0]][j] == 1 && !count(visiting.begin(), visiting.end(), j) && !count(visited.begin(), visited.end(), j))
            {
                visiting.push_back(j);
            }
        }

        if (!visiting.empty())
        {
            visited.push_back(visiting[0]);
            visiting.erase(visiting.begin());
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (!count(visited.begin(), visited.end(), i))
        {
            f = 1;
            break;
        }
    }
    return f;
}
int isEuler()
{
    int i, j, k;
    vector<int> degree(vertices, 0);
    int odddegree = 0;
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            if (graph[i][j] == 1)
                degree[i]++;
        }
    }
    for (i = 0; i < vertices; i++)
    {
        if (degree[i] % 2 != 0)
            odddegree++;
    }
    return odddegree;
}
int main()
{
    graphinput();
    if (isconnected())
    {
        cout << "Graph is disconnected.";
        return 0;
    }
    switch (isEuler())
    {
    case 0:
        cout << "The graph has Euler Path as well as circuit.";
        break;
    case 2:
        cout << "The graph has Euler Path but no circuit.";
        break;
    default:
        cout << "The graph has neither Euler Path nor a Euler circuit.";
        break;
    }
    return 0;
}
