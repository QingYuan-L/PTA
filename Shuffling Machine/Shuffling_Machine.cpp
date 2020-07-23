//
// Created by lqy on 2020/7/24.
//
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> order;
    int order_temp;
    int num;
    cin >>num;
    while(cin>>order_temp){
        order.push_back(order_temp);
        char c  = cin.get();
        if (c=='\n')break;
    }
    for(auto mu:order)
    {
        cout<<mu;
    }
    return 0;
}
