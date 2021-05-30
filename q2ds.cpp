#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vertices, edges, vert1, vert2, indeg, outdeg;
    indeg = outdeg = 0;
    int row = 1;
    cout << "Enter number of vertices:  ";
    cin >> vertices;
    vector<int> indegree(vertices, 0);
    vector<int> outdegree(vertices, 0);

    for (int i = 0; i < vertices; i++)
    {
        outdegree[i] = indegree[i] = 0;
    }

    cout << "Enter the number of edges:  ";
    cin >> edges;
    cout << endl;

    for (int i = 0; i < edges; i++)
    {
        cout << "Edge " << i + 1 << " :  " << endl;
        cout << "Emerging from:  ";
        cin >> vert1;
        cout << "Encountering:  ";
        cin >> vert2;
        cout << endl;
        indegree[vert2 - 1]++;
        outdegree[vert1 - 1]++;
    }

    for (int i = 0; i < vertices; i++)
    {
        indeg += indegree[i];
        outdeg += outdegree[i];
    }

    cout << "Vertices\tin-deg\tout-deg" << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << "  (" << i + 1 << ")  \t"
             << "           " << indegree[i] << '\t' << "   " << outdegree[i] << endl;
    }
    cout << endl;

    cout << "Total in-degree = " << indeg << endl;
    cout << "Total out-degree = " << outdeg << endl;
    cout << "Total degree = " << (indeg + outdeg) << endl;
}
