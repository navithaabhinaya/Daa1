//floyd
#include <iostream>
#include<iostream>
#include<iomanip>
#define NODE 4
#define oo 999
using namespace std;

int costMat[NODE][NODE] = {
   {0, 3, 6, oo},
   {3, 0, 2, oo},
   {6, 2, oo, 1},
   {oo, 1, 1, 0},
  
};
void floyd(){
   int cost[NODE][NODE]; 
   for(int i = 0; i<NODE; i++)
      for(int j = 0; j<NODE; j++)
         cost[i][j] = costMat[i][j]; 
         for(int k = 0; k<NODE; k++){
            for(int i = 0; i<NODE; i++)
               for(int j = 0; j<NODE; j++)
                  if(cost[i][k]+cost[k][j] < cost[i][j])
                     cost[i][j] = cost[i][k]+cost[k][j];
   }
   cout << "The matrix:" << endl;
   for(int i = 0; i<NODE; i++){
      for(int j = 0; j<NODE; j++)
         cout << setw(3) << cost[i][j];
      cout << endl;
   }
}
int main(){
   floyd();
}