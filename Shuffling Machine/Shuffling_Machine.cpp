//
// Created by lqy on 2020/7/24.
//
#include <iostream>
#include <vector>
using namespace std;

struct poker{
    char ch;
    int p_num;
};

vector<poker> shuffling(vector<poker> pokers,vector<int> order){
    vector<poker> pokers_temp(54);
    for(int i=0;i<54;i++)
    {
        pokers_temp[order[i]-1].ch=pokers[i].ch;
        pokers_temp[order[i]-1].p_num=pokers[i].p_num;
    }
    return pokers_temp;
}

int main()
{
    vector<int> order;
    vector<poker> pokers_set;
    int order_temp;
    poker p_temp;
    int num;
    cin >>num;
    char p_f[5]={'S','H','C','D','J'};
    for(int i=0;i<5;i++)
        for(int j=1;j<=13;j++)
        {
            if(i==4&&j==3)break;
            p_temp.ch=p_f[i];
            p_temp.p_num=j;
            pokers_set.push_back(p_temp);
        }
//    for(auto cm:pokers_set)
//    {
//        cout<<cm.ch<<cm.p_num<<' ';
//    }
//
    while (cin>>order_temp){
        order.push_back(order_temp);
        char c  = cin.get();
        if (c=='\n')break;
    }
    for(int i=0;i<num;i++)
    {
        pokers_set=shuffling(pokers_set,order);
    }
    for(int i=0;i<53;i++)
    {
        cout<<pokers_set[i].ch<<pokers_set[i].p_num<<' ';
    }
    cout<<pokers_set[53].ch<<pokers_set[53].p_num;
    return 0;
}
