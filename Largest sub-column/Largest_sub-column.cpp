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
    int if_positive=0;
    vector<int> max_start_queue;
    int max_start_temp=0;
    int max_end,max_start;
    for(int i=0;i<m;i++)
    {
        if (numbers[i]>=0)if_positive=1;
        max_sub_column=max_sub_column+numbers[i];
        max_start_temp++;
        if(max_sub_column>real_sub)
        {
            real_sub=max_sub_column;
            max_end=i;
            max_start_queue.push_back(max_start_temp);
        }
        if(max_sub_column<0){
            max_sub_column=0;
            max_start_temp=0;
        }
    }
//    for(int i =0;i<max_start_queue.size();i++)
//    {
//        if(max_start_queue[i]>max_end)
//        {
//            max_start=max_start_queue[i-1];
//            break;
//        }
//    }
    if(if_positive)
    {
        //cout<<max_end<<max_start;
        if(real_sub==0)
        {
            cout<<0<<' '<<0<<' '<<0;
            return 0;
        }
        max_start=max_end-max_start_queue.back()+1;
        cout<<real_sub<<' '<<numbers[max_start]<<' '<<numbers[max_end];

    } else{
        cout<<0<<' '<<numbers[0]<<' '<<numbers[m-1];
    }
    return 0;
}
