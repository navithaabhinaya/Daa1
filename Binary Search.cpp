#include<iostream>
using namespace std;
int main()
{
    int count, i, arr[50], num, j, temp, first, last, middle;
    cout<<"Enter the Size: ";
    cin>>count;
    cout<<"Enter "<<count<<" Elements: ";
    for(i=0; i<count; i++)
        cin>>arr[i];

    for(i=0; i<(count-1); i++)
    {
        for(j=0; j<(count-i-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"\nThe New Sorted Array is:\n";
    for(i=0; i<count; i++)
        cout<<arr[i]<<" ";
    cout<<"\n\nEnter Element to be Searched: ";
    cin>>num;
    first = 0;
    last = (count-1);
    middle = (first+last)/2;
    while(first <= last)
    {
        if(arr[middle]<num)
            first = middle+1;
        else if(arr[middle]==num)
        {
            cout<<"\nThe number, "<<num<<" found at Position "<<middle+1;
            break;
        }
        else
            last = middle-1;
        middle = (first+last)/2;
    }
    if(first>last)
        cout<<"\nThe number, "<<num<<" is not found in given Array";
    cout<<endl;
    return 0;
}