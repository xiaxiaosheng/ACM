// File Name: Leetcode15.cpp
// Author: xiaxiaosheng
// Created Time: 2015年04月14日 星期二 15时03分51秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

map<int,int> mp;
bool cmp(vector<int> a,vector<int> b)
{
	if(a[0] != b[0]) return a[0] > b[0];
	if(a[1] != b[1]) return a[1] > b[1];
	return a[2] > b[2];
}
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector< vector<int> > tt;
		if(num.size() < 3) return  tt;
		sort(num.begin(),num.end());
		mp.clear();
		for(int i = 0;i < num.size();++i)
		{
			if(mp[num[i]] == 0) mp[num[i]] = 1;
			else mp[num[i]]++;
		}
		vector< vector<int> > ans,last;
		vector<int> temp;
		ans.clear();
		for(int i = 0;i < num.size();++i)
			for(int j = i+1;j < num.size();++j)
			{
				mp[num[i]]--,mp[num[j]]--;
				int t = -1 * (num[i] + num[j]);
				if(mp[t])    //there is exist num[i],num[j],t
				{
					temp.clear();
					temp.push_back(num[i]);
					temp.push_back(num[j]);
					temp.push_back(t);
					ans.push_back(temp);
				}
				mp[num[i]]++,mp[num[j]]--;
			}
		if(!ans.empty())
		{
			last.clear();
			for(int i = 0;i < ans.size();++i)
				sort(ans[i].begin(),ans[i].end());
			sort(ans.begin(),ans.end(),cmp);      
			last.push_back(ans[0]);
			for(int i = 1;i < ans.size();++i)
			if(!(ans[i][0] == ans[i-1][0] && ans[i][1] == ans[i-1][1]))
				last.push_back(ans[i]);
		}
		return last;
    }
};
int main()
{
	Solution sol;
	vector<int> num;
//	num = {-1,0,1,2,-1,-4};
	num.push_back(0);
	num.push_back(1);
	num.push_back(1);
//	num.push_back(1);
//	num.push_back(2);
//	num.push_back(-1);
//	num.push_back(-4);

	vector< vector<int> > ans = sol.threeSum(num);
	for(int i = 0;i < ans.size();++i)
	{
		for(int j = 0;j < 3;++j)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
