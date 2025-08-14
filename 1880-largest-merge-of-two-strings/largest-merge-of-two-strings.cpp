class Solution {
public:
    string largestMerge(string word1, string word2) {
        

        string res ="";

        int i=0,j=0;
        int n=word1.size(),m=word2.size();


        while( i < n && j <m ){

            if(word1[i] > word2[j]){
                res+=word1[i];
                i++;
            }else if(word2[j] > word1[i]){
                res += word2[j];
                j++;
            }else{
               
               //check ahead consider
                if(word1.substr(i) > word2.substr(j)){
                    res+=word1[i++];
                }else{
                    res += word2[j++];
                }
            }
        }

        while( i < n){
            res+=word1[i];
            i++;
        }
        while(j < m ){
            res += word2[j];
            j++;
        }
        return res;

    }
};