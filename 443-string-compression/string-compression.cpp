class Solution {
public:
    int compress(vector<char>& chars) {
        
        string s = "";
        for(int i=0;i<chars.size();i++){

         
            int times = 1;
            while(i+1<chars.size() && chars[i] == chars[i+1]){
                times++;
                i++;
            }

            if(times == 1){
                s+=chars[i];
            }else{
                s+=chars[i];
                s+=to_string(times);
            }
        }

        //modify new input array 

       for(int i=0;i<s.length();i++){
        chars[i] = s[i];
       }
        return s.length();
    }
};