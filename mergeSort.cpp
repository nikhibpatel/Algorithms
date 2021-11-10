#include<bits/stdc++.h>
using namespace std;

// Merge Sort          // Time Complexity - O( N log(N) )		// Space Complexity - O (N)
template < typename Tm > 
void mergeSort(vector <Tm> &v,vector <Tm> &temp,int si,int ei)
{
    if(si >= ei ) return ;
    
    int mi=(si+ei)/2;
    
    mergeSort(v,temp,si,mi);		// Sorting Left SubArray
    mergeSort(v,temp,mi+1,ei);	// sorting Right SubArray
    
    
    // copying SubArray in Temporary Array 
    for (int i=si;i<=ei;i++)
    {
        temp[i]=v[i];
    }
    
    // Sorting Array
    
    int i=si,j=mi+1,k=si;
    
    while(i<=mi && j<=ei )
    {
        if (temp[i]<=temp[j]){
            v[k]=temp[i],i++;
        }else{
            v[k]=temp[j],j++;
        }
        k++;
    }
    
    // copying remaining array 
    while(i<=mi) v[k]=temp[i],i++,k++;
    while(j<=ei) v[k]=temp[j],j++,k++;
    
    return ;
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t ;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> v(n),temp(n);
        for (int i=0;i<n;i++)
        {
        	cin >> v[i];
        }
        mergeSort(v,temp,0,n-1);
        
        for (int i=0;i<n;i++)
        {
        	cout << v[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
