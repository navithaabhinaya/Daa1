/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{   
    int n, arr[100] , i, count ;
    cout<<"Enter the number of elements to be sorted \n";
    cin>>count;
 
    cout<<"Enter " << count <<" numbers\n";
    
    for(i=0; i<count; i++)
    {
        cin>>arr[i];
        
    }
    
    cout<<"\n Enter the element to be searched :\n";
    cin>>n;
    for(i=0; i<count; i++)
    {
        if(arr[i]==n)
        {
            cout<<"Element found at position "<<i;
            break;
        }
    }
    if(i==count)
    {
        cout<<"\nElement not found\n";
    }
    return 0;
}
