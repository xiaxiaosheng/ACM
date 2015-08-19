class Solution {
public:
    int getsum(int n)
    {
        int tot = 0;
        while(n)
        {
            int t = n % 10;
            tot += (t * t);
            n /= 10;
        }
        return tot;
    }
    bool isHappy(int n) {
        int p1 = n,p2 = n,flag = 1;
        while(1)
        {
            p1 = getsum(p1);
            p2 = getsum(p2);
            p2 = getsum(p2);
            if(p1 == 1 || p2 == 1)
                break;
            if(p1 == p2)
            {
                flag = 0;
                break;
            }
        }
        return flag;
    }
};
