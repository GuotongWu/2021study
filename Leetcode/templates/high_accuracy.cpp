#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

const int N = 1e6+10;

vector<int> add(vector<int> a, vector<int> b)
{
    if (a.size() < b.size())
        return add(b,a);
    int flag = 0;
    vector<int> res;
    for (int i=0; i<a.size(); ++i){
        flag += a[i];
        if(b.size() > i)
            flag += b[i];
        res.push_back(flag%10);
        flag /= 10;
    }
    if(flag)
        res.push_back(flag);
    return res;
}


vector<int> subtract(vector<int> a, vector<int> b)
{
    // a>b,a>0,b>0
    int flag = 0;
    vector<int> res;
    for(int i=0; i<a.size(); ++i){
        flag += a[i];
        if (i < b.size())
            flag -= b[i];
        res.push_back(abs(flag%10));
        flag /= 10;
    }
    if (flag<0)
        res.push_back(-1);
    return res;
}

vector<int> mul(vector<int> a, vector<int> b)
{
    if (a.size()<b.size())
        return mul(b,a);
    int flag = 0;
    vector<int> res;
    for(int i=0; i<a.size(); ++i){
        flag += a[i];
        if ()
    }

}

int main()
{
    vector<int> a = {1,2,3,4};
    vector<int> b = {2,3,4,6,2};
    vector<int> c = subtract(b,a);
    for(int i=c.size()-1; i>=0; --i)
        cout<<c[i];
    return 0;
}