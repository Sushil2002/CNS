#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;
// ASCII of 'a'-97,'z'-123,'A'-65,'Z'-90,'0'-48,'9'-57
bool sortby(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return a.second < b.second;
}
signed main()
{
    string s;
    cin >> s;
    int m = s.length();
    int r = 0;
    int form = m + r + 1;
    vector<int> v;
    while (pow(2, r) < m + r + 1)
    {
        v.push_back(pow(2, r));
        r++;
    }
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    int size = m + v.size();
    vector<char> arr(size + 1, '1');
    // arr[0]='-1';
    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i]] = 'r';
    }
    reverse(arr.begin(), arr.end());
    arr[size] = 'a';
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 'r')
        {
            arr[i] = s[j];
            j++;
        }
        if (j == m)
        {
            break;
        }
    }
    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // for (int i = arr.size()-2; i >=0; i--)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    vector<string> str;
    string ans = "";
    int cnt = 0;
    // cout<<arr.size()<<endl;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] == 'r')
        {
            cnt = arr.size() - 2 - i + 1;
            ans.clear();
            int temp = 0;
            int flag = 1;
            for (int j = i; j >= 0; j--)
            {
                if (arr[j] != 'r' && flag == 1)
                {
                    ans.push_back(arr[j]);
                }
                temp++;
                if (temp == cnt)
                {
                    temp = 0;
                    flag = 1 - flag;
                }
            }
            str.push_back(ans);
        }
    }
    // for (int i = 0; i < v.size(); i++)
    // {
    //     ans="";
    //     int temp = v[i];
    //     for (int k = arr.size() - temp; k >= 0; k -= temp + 1)
    //     {
    //         for (int l = k; l >= 0; l--)
    //         {
    //             if (arr[l] != 'r')
    //             {
    //                 ans += arr[l];
    //             }
    //         }
    //     }
    //     str.push_back(ans);

    // }
    // cout << endl;
    // cout<<"Hello"<<endl;
    cout << str.size() << endl;
    for (auto it : str)
    {
        cout << it << " ";
    }
    return 0;
}