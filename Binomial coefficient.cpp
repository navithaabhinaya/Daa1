// BinomialCoefficients using dynamic programming
#include <bits/stdc++.h>
using namespace std;
int BinomialCoefficients(int n, int k)
{
    int C[k+1];
    memset(C, 0, sizeof(C));
    C[0] =1;
    for(int i= 1; i<=n; i++)
    {
        for(int j = min(i, k); j>0; j--)
        C[j] = C[j] + C[j-1];
    
    }
    return C[k];
    
}
int main()
{
    int n, k;
    cout<< "enter the value of n"<<endl;
    cin>>n;
    cout<< "enter the value of k"<<endl;
    cin>>k;
    cout<<" The value of C("<<n<<", "<<k<<") is "<<BinomialCoefficients(n, k);
    return 0;
}
