#include <iostream>
#include <limits.h>
using namespace std;

int largestSumSubArray(int arr[], int n,int sum,int final_sum)
{
    sum = sum + arr[n-1];             //calcu
    if (final_sum < sum)
    {
        final_sum = sum;
    }

    if (sum < 0)
    {
        sum = 0;
    }
    if(n==0)
    {
        return final_sum;
    }
    largestSumSubArray(arr,n-1,sum,final_sum);
}
//T(n) = T(n-1) + 3
int main()
{ int continuee=0;
    do
    {
        int final_sum = INT_MIN, sum = 0,n;
        cout<<"enter the size of the array"<<endl;
        cin>>n;
        while(n<=0)
        {
            cout<<"the size must be above zero, please enter a suitable size "<<endl;
            cin>>n;
        }
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cout<<"enter element number "<<i+1<<endl;
            cin>>arr[i];
        }
        int max_sum = largestSumSubArray(arr, n,sum,final_sum);
        cout << "Maximum contiguous sum is " << max_sum<<endl;
        cout<<"if you wish to continue press 1 ,if not press any other key"<<endl;
        cin>>continuee;
    }
    while(continuee==1);

    return 0;
}
