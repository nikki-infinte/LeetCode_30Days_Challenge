class Solution {
public:
  static int countSetBit(int num){

        int count =0;
        while( num  > 0){
            num = num & num-1;
            count++;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int a,int b){
            if(countSetBit(a) == countSetBit(b)){
                return a < b;
            }
            return countSetBit(a) < countSetBit(b);
        });
        return arr;
    }
};