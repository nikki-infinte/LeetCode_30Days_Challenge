class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        int i=0;
        while( i < word.size()){
            int tmp =0;
            while(i+1<word.size() && word[i+1] == word[i]){
                tmp++;
                i++;
            }
            count+=tmp;
            i++;
        }
        return count;
    }
};