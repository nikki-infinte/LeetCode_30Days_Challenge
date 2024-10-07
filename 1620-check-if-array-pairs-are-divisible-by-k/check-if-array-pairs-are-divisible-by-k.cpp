class Solution {
public:
    bool canArrange(vector<int>& vec, int k) {
    //     vector<pair<int,int>>ans;
    // int count=0;
    // sort(vec.begin(),vec.end());
    
    // vector<int>mark(vec.size(),0);
    
    // for(int i=0;i<vec.size();i++)
    // {
    //     int elm=vec[i];
    //     if(mark[i]==0)
    //     {
    //         for(int j=i+1;j<vec.size();j++)
    //         {
    //             if(mark[j]==0)
    //             {
    //                 if((vec[j]+elm)%k==0)
    //                 {
    //                     ans.push_back(make_pair(vec[i],vec[j]));
    //                     mark[i]=1;
    //                     mark[j]=1;
    //                     count++;
    //                 }
    //             }
    //         }
    //     }
    // }
    // if(count==vec.size()/2)return true;
    // else return false;



    //optimal
    unordered_map<int, int> mp;
     for (int a : vec) {
        int rem = a % k;
        if (rem < 0) {
            rem += k;  // Handle negative remainders
        }
        mp[rem]++;
    }

    // Step 2: Check remainder 0, it must have an even count
    if (mp[0] % 2 != 0) return false;

    // Step 3: Check if the remainder counts are compatible for pairing
    for (int i = 1; i < k; ++i) {
        if (mp[i] != mp[k - i]) {
            return false;  // The frequency of remainder i must match k - i
        }
    }

    return true;
    }
};