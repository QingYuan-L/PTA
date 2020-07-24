//
// Created by admin on 2020/7/24.
//
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m;
    cin>>m;
    vector<int> numbers;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        numbers.push_back(temp);
    }
    int real_sub=0;
    int max_sub_column=0;
    for(int i=0;i<m;i++)
    {
        max_sub_column=max_sub_column+numbers[i];
        if(max_sub_column>real_sub)real_sub=max_sub_column;
        if(max_sub_column<0)max_sub_column=0;
    }
    cout<<real_sub;
    return 0;
}
