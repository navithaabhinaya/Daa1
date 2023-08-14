/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int a[20][20], q[20], visited[20], n, i, j, f=0, r=-1;

void bfs(int v)
{
    for(i=1; i<=n; i++)
      if(a[v][i] && !visited[i])
      {
          q[++r] = i;
      bfs(q[f++]);
      }
}

int main()
{
    int v;
    cout << "\n Enter the number of vertices:";
    cin>> n;
    for(i=1; i<=n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }
    cout<<"\n Enter graph data:\n";
    for(i = 1;i<=n;i++)
    for (j=1; j<=n; j++)
    cin>> a[i][j];
    cout<<"\n Enter the starting vertex:";
    cin>>v;
    bfs(v);
    cout<<"\n The nodes which are reachable are:\n";
    for(i=1; i<=n; i++)
       if(visited[i])
        cout<<i<<"\t";
        return 0;
}