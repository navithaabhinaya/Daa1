/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<iostream>
#define NODE 5
using namespace std;
int graph[NODE][NODE] = {{0, 1, 1, 0, 0},
{1, 0, 1, 1, 0},
{1, 1, 0, 1, 1},
{0, 1, 1, 0, 1},
{0, 0, 1, 1, 0}};
void traverse(int u, bool visited[]) {
   visited[u] = true; 
   for(int v = 0; v<NODE; v++) {
      if(graph[u][v]) {
         if(!visited[v])
            traverse(v, visited);
      }
   }
}
bool isConnected() {
   bool *vis = new bool[NODE];
  
   for(int u; u < NODE; u++) {
      for(int i = 0; i<NODE; i++)
         vis[i] = false; 
         traverse(u, vis);
      for(int i = 0; i<NODE; i++) {
         if(!vis[i]) 
            return false;
      }
   }
   return true;
}
int main() {
   if(isConnected())
      cout << "The Graph is connected.";
   else
      cout << "The Graph is not connected.";
}