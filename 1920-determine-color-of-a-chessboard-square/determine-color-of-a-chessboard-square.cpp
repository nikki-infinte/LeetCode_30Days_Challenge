class Solution {
public:
    bool squareIsWhite(string coordinates) {
        unordered_map<char,int>umap;
        int chara=coordinates[0]-'a'+1;
        int value=coordinates[1];

        if(chara % 2)
        {
            return (value % 2 == 0);
        }else{
            return (value % 2 !=0);
        }
        
    }
};