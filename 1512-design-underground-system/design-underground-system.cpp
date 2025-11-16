class UndergroundSystem {
public:
    map<int,pair<string,int>>checkInMp;
    map<string,vector<int>>finalMp;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMp[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int timetake = t - checkInMp[id].second;
        string route = checkInMp[id].first + "->"+stationName;
        finalMp[route].push_back(timetake);

        
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avg=0;
        if(finalMp.find(startStation+"->"+endStation)!=finalMp.end()){
            double sum =0;

            for(auto e:finalMp[startStation+"->"+endStation]){
                sum+=e;
            }
            avg = sum / finalMp[startStation+"->"+endStation].size();
        }
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */