#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string numbers;
    cin>>numbers;
    vector<int> jug;
    for(int i=0;i<10;i++)
    {
        jug.push_back(0);
    }
    // for(auto um:jug)
    // {
    //     cout<<um;
    // }
    long long int j,dou_j;
    j = stoll(numbers);
    dou_j = j*2;
    string dou_numbers = to_string(dou_j);
    for(int j=0;j<dou_numbers.size();j++)
    {
        jug[(dou_numbers[j]-'0')]=1;
    }
    for(int j=0;j<numbers.size();j++)
    {
        jug[(numbers[j]-'0')]=0;
    }
    int yn=1;
    for(int i=0;i<jug.size();i++)
    {
        if(jug[i]==1)yn=0;
    }
    if(yn==1)
        {cout<<"Yes"<<endl;}
    else 
        {cout<<"No"<<endl;}
    cout<<dou_numbers;
    return 0;
}