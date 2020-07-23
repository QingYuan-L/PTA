#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string numbers;
    cin>>numbers;
    vector<int> jug,count_jug;
    for(int i=0;i<10;i++)
    {
        jug.push_back(0);
        count_jug.push_back(0);
    }

//    long long int j,dou_j;
//    j = stoll(numbers);
//    dou_j = j*2;
//    string dou_numbers = to_string(dou_j);
    string dou_numbers;
    vector<char> temp_dou_number;
    int ten = 0;
    for(int i=numbers.size()-1;i>=0;i--)
    {
        int str_temp = (numbers[i]-'0');
        str_temp = str_temp*2;
        char  one_char = char(str_temp%10+'0'+ten);
        ten = str_temp/10;
        temp_dou_number.insert(temp_dou_number.begin(),one_char);
    }
    if(ten ==1)temp_dou_number.insert(temp_dou_number.begin(),char(1+'0'));
    dou_numbers.assign(temp_dou_number.begin(),temp_dou_number.end());
    for(int j=0;j<dou_numbers.size();j++)
    {
        jug[(dou_numbers[j]-'0')]=1;
        count_jug[(dou_numbers[j]-'0')]=1;
    }
    for(int j=0;j<numbers.size();j++)
    {
        jug[(numbers[j]-'0')]=0;
        count_jug[(numbers[j]-'0')]=2;
    }
    int yn=1;
    for(int i=0;i<jug.size();i++)
    {
        if(jug[i]==1)yn=0;
    }
    if(yn==1&&numbers.size()==dou_numbers.size())
        {cout<<"Yes"<<endl;}
    else 
        {cout<<"No"<<endl;}
    cout<<dou_numbers;
    return 0;
}