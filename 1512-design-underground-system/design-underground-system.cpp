class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    unordered_map<int,pair<string,int>>checkInMap;
    unordered_map<string,vector<int>>checks;
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id]={stationName,t};


    }
    
    void checkOut(int id, string stationName, int t) {
        
        if(checkInMap.count(id)){
            string source = checkInMap[id].first;
            int timeTake = t - checkInMap[id].second;
            checks[(source+"->"+stationName)].push_back(timeTake);

        }
    }
    
 double getAverageTime(string startStation, string endStation) {
    double avg = 0;
    string key = startStation + "->" + endStation;
    if (checks.count(key)) {
        vector<int> tmp = checks[key];
        int sum = accumulate(tmp.begin(), tmp.end(), 0);
        avg = static_cast<double>(sum) / tmp.size();
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