#include <iostream>
#include <conio.h>
#include <vector>
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
int checkTotPath(int startNode, int goalNode, int pathLen)
{
    if (pathLen == 0 && startNode == goalNode)
    {
        return 1;
    }
    else if (pathLen == 1 && graph[startNode][goalNode])
    {
        return 1;
    }
    else if (pathLen <= 0)
    {
        return 0;
    }
    int totPath = 0;
    for (int i = 0; i < 5; i++)
        if (graph[startNode][i] == 1)
        {
            totPath += checkTotPath(i, goalNode, pathLen - 1);
        }

    return totPath;
}
int main()
{
    graphinput();
    int startNode;
    int goalNode;
    int pathLen;
    cout << "Enter the starting node:-";
    cin >> startNode;
    cout << "Enter the goal node:-";
    cin >> goalNode;
    cout << "Enter the length of path:-";
    cin >> pathLen;

    cout << checkTotPath(startNode, goalNode, pathLen);
    return 0;
}
