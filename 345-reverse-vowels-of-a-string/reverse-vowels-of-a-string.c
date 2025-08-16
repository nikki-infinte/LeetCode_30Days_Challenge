#include<string.h>

char* reverseVowels(char* s) {

    int n = strlen(s);
    char* collectAll = (char*)malloc(n*sizeof(char));
    int ci = 0;
    for(int i=0;i<n;i++){
        char elm = toupper(s[i]);

        if(elm == 'A' || elm == 'E' || elm == 'I' || elm == 'O' || elm  == 'U'){
            collectAll[ci] = s[i];
            ci++;
        }
    }

    int i=0;
    for(int i=0;i<n && ci > 0;i++){
         char elm = toupper(s[i]);

        if(elm == 'A' || elm == 'E' || elm == 'I' || elm == 'O' || elm  == 'U'){
           s[i] = collectAll[--ci];
        
        }

    }
       free(collectAll);
    return s;
}