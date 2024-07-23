class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        //create maxheap to remove which has highest diffeence
        priority_queue<pair<int,int>>maxheap;
        for(int i=0;i<arr.size();i++)
        {
            maxheap.push({abs(arr[i]-x),arr[i]});

            if(maxheap.size()>k)
            {
                maxheap.pop();
            }
        }
        vector<int>ans;
        while(!maxheap.empty())
        {
            auto elem=maxheap.top();
            ans.push_back(elem.second);
            maxheap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};