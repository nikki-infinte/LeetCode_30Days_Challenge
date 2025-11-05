class Solution {
public:
    long long sum;
    set<pair<int,int>> main, sec;
    int X;

    void removeFromSet(pair<int,int> p){
        if(main.find(p) != main.end()){
            sum -= 1LL * p.first * p.second;
            main.erase(p);

            if(!sec.empty()){
                auto largest = *sec.rbegin();
                sec.erase(largest);
                main.insert(largest);
                sum += 1LL * largest.first * largest.second;
            }
        } else {
            sec.erase(p);
        }
    }

    void insertInSet(pair<int,int> p){
        if(main.size() < X || p > *main.begin()){
            sum += 1LL * p.first * p.second;
            main.insert(p);
            if(main.size() > X){
                auto smallest = *main.begin();
                sum -= 1LL * smallest.first * smallest.second;
                main.erase(smallest);
                sec.insert(smallest);
            }
        } else {
            sec.insert(p);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        sum = 0;
        X = x;
        vector<long long> result;
        unordered_map<int,int> mp;
        int n = nums.size();
        int i = 0;

        for(int j = 0; j < n; j++){
            if(mp.count(nums[j])){
                removeFromSet({mp[nums[j]], nums[j]});
                mp[nums[j]]++;
                insertInSet({mp[nums[j]], nums[j]});
            } else {
                mp[nums[j]] = 1;
                insertInSet({1, nums[j]});
            }

            if(j - i + 1 == k){
                result.push_back(sum);

                removeFromSet({mp[nums[i]], nums[i]});
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                } else {
                    insertInSet({mp[nums[i]], nums[i]});
                }
                i++;
            }
        }
        return result;
    }
};
