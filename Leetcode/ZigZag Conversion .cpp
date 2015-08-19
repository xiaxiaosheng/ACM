struct node
{
	char ch;
	int row,fol;
	node(char c = ' ',int r = 0,int f = 0):ch(c),row(r),fol(f) {}
	friend bool operator < (node a,node b)
	{
		if(a.row == b.row) return a.fol < b.fol;
		return a.row < b.row;
	}
};
class Solution {
public:	
	vector<node> vt;
public:
	string convert(string s, int nRows) {
		vt.clear();
		int r = 0,flag = -1;
		for(int i = 0;i < s.length();++i)
		{
			vt.push_back(node(s[i] ,r,i));
			if(r >= nRows - 1 || r <= 0)
				flag *= -1;
			if(nRows != 1)
				r += flag;
		}
		sort(vt.begin(),vt.end());
		string ans = "";
		for(int i = 0;i < vt.size();++i)
			ans += vt[i].ch;
		return ans;
	}
};

