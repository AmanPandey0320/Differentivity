#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//vector
#define vll vector<ll>
#define vii vector<int>
#define vpb push_back
#define vpp pop_back
//map
#define unmap_si unordered_map<string,ll>
#define unmap_ii unordered_map<ll,ll>
//set
#define set_i set<ll>
#define set_s set<string>
#define in insert
//pair
#define pair_ii pair<ll,ll>
#define pair_si pair<string,ll>
#define pair_ip pair<ll,pair<ll,ll>>
#define pair_mk make_pair
//priority queue
#define min_pq priority_queue <ll, vector<ll>, greater<int>> 
#define max_pq priority_queue <ll> 
//fast io
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//modulus
ll mod=1e9+7;
ll m=1000000;
void solve();
//main
int main(){
    fast_io;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}//end of main function
//template
template<typename T>
T mergeArr(T arr[],int l,int m,int r){
    //function to merge two part
    int nl = m-l+1;
    int nr = r-m;
    T inv=0;
    T left[nl],right[nr];
    //forming elements of the left side of sub array
    for(int i=0;i<nl;i++)
        left[i] = arr[l+i];
    //forming elements of the right side of sub array
    for(int i=0;i<nr;i++)
        right[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    //merging the two arrays
    while(i<nl && j<nr){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }else{
            arr[k]=right[j];
            j++;
            inv+=(m-i+1-l);
        }
        k++;
    }
    //merging the remaining elements of left array
    while(i<nl)arr[k++]=left[i++];
    //merging the remaining elements of right array
    while(j<nr)arr[k++]=right[j++];

    return inv;
}
//template
template<typename T>
T mergeSort(T arr[],int l,int r){
    if(l>=r){
        //no element in this sub array or only one element
        return 0;
    }
    int m = l+(r-l)/2;
    //sort left part recursively
    T left = mergeSort<T>(arr,l,m);
    //sort right part recursively
    T right = mergeSort<T>(arr,m+1,r);
    //merge two parts
    T merge = mergeArr<T>(arr,l,m,r);
    return (left+right+merge);
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort<int>(arr,0,n-1);
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    return;
}