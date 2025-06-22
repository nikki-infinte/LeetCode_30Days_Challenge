class Solution {
public:

    int findSum(int a)
    {
        int sum =0;
        while(a)
        {
            sum+=a%10;
            a/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>v = nums;

        sort(v.begin(),v.end(),[&](int a,int b)
        {
            int sumA = findSum(a);
            int sumB = findSum(b);
            if(sumA == sumB)return a<b;
            return sumA < sumB;
        });

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]] = i;
        }

        vector<bool>visit(n,false);
        int cnt =0;

        for(int i=0;i<n;i++)
        {
            if(visit[i] || v[i] == nums[i])continue;

            int cycle =0;
            int j=i;
            while(!visit[j]){
                visit[j] = true;
                j = mp[v[j]];
                cycle++;
            }
            if(cycle > 1)cnt+=(cycle-1);



        }
        return cnt;


    }
};