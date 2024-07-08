class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalBottles = 0;

        while (numBottles >= numExchange) {
            totalBottles +=numExchange;
            numBottles-=numExchange;

            numBottles+=1;
        }

        return (totalBottles+numBottles);
    }
};