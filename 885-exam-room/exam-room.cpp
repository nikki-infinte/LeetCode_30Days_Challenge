class ExamRoom {
public:
    set<int> st;
    int size;
    ExamRoom(int n) { size = n; }

    int seat() {
        if (st.empty()) {
            st.insert(0);
            return 0;
        } else {

            int maxDist = 0;
            int seatToSit = 0;

            // 1 check seat at pos 0
            auto first = *st.begin();
            if (first != 0) {
                int dist = first;
                if (dist > maxDist) {
                    maxDist = dist;
                    seatToSit = 0;
                }
            }

            // 2.check seats in middle
           int prev =-1;
           for(int s:st){
            if(prev != -1){
                int d = (s - prev)/2;
                if(d > maxDist){
                    maxDist = d;
                    seatToSit = prev+d;
                }
            }
            prev =s;
           }

            // 3 .check seat at pos n-1
            int last = *st.rbegin();
            if (size- 1 - last > maxDist) {
                seatToSit = size - 1;
            }

            st.insert(seatToSit);
            return seatToSit;
        }
    }

    void leave(int p) { st.erase(p); }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */