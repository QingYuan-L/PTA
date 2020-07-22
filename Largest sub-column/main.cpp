#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& num,int begin,int end){
    while(begin<end)
    {
        int jj;
        jj = num[begin];
        num[begin]=num[end];
        num[end]=jj;
        begin++,end--;
    }
}

int main() 
{
    int m,n;
    vector <int> num;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {  
        int temp;
        cin>>temp;
        num.push_back(temp);
    }
    if(n>m){
        n=n%m;
    }
    if(n%m!=0)
    {
        reverse(num,0,m-n-1);
        reverse(num,m-n,m-1);
        reverse(num,0,m-1);
    }
    
    for(int i=0;i<num.size()-1;i++)
    {
        cout<<num[i]<<' ';
    }
    cout<<num.back();
    return 0;
}