class Solution {
public:
    string reverseVowels(string s) {
        string vowels="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' ||s[i]=='I' ||s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U')
            {
                vowels+=s[i];
            }
        }

        int i=0;
        int j=vowels.size()-1;
        while(i<j)
        {
            swap(vowels[i],vowels[j]);
            i++;
            j--;
        }
        int indx=0;

          for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' ||s[i]=='I' ||s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U')
            {
                s[i]=vowels[indx];
                indx++;
            }
        }
    return s;
    }
};