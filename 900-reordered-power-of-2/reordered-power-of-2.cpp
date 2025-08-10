class Solution {
public:

    string getSorted(int n){
        string s = to_string(n);
        sort(s.begin(),s.end());

        return s;
    }
    bool reorderedPowerOf2(int n) {
        
        if(n==0)return false;

        string s1 = getSorted(n);
        for(int power = 0;power <= 29 ;power++){

            string toCheck = getSorted(1<<power);
            if(toCheck == s1)return true;
        }
        return false;
    }
};