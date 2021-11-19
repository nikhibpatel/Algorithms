// Quick Sort 			
// Time Complexity - [Average Case - O(N log(N)) ] [Worst Case - O(N^2)]		
// Space Complexity - [Average Case - O(log(N)) ] [Worst Case - O(N)]



#include<bits/stdc++.h>
using namespace std;


template < typename Tq > 
int partition(vector <Tq> &v,int si,int ei){
    Tq cmp=v[si];
    int i=si+1,j=ei;
    while(i<=j){
        if(v[i]>cmp && v[j]<=cmp){
            swap(v[i],v[j]);
            i++;j--;
        }
        if(v[i]<=cmp){
            i++;
        }
        if(v[j]>cmp ){
            j--;
        }
    }
    swap(v[si],v[i-1]);
    return i-1;
}

template < typename Tq > 
void quickSort(vector <Tq> &v,int si,int ei){
    if(si>=ei) return ;
    int c=partition(v,si,ei);
    quickSort(v,si,c-1);
    quickSort(v,c+1,ei);
    return ;
}

int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> v(n);
        for (int i=0;i<n;i++){
            cin >> v[i];
        }
        quickSort(v,0,n-1);
        for(int i=0;i<n;i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}