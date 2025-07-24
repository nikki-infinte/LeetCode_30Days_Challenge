class Solution {
public:
    bool isPrefixAndSuffix(string a,string b){
      
        int aLen = a.size();
        int bLen = b.size();

          if (aLen > bLen) return false;

        // Check if 'a' is prefix of 'b'
        bool isPrefix = (b.substr(0, aLen) == a);
        // Check if 'a' is suffix of 'b'
        bool isSuffix = (b.substr(bLen - aLen) == a);

        return isPrefix && isSuffix;
      

    }
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int count =0;
        int n = words.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i != j && isPrefixAndSuffix(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};