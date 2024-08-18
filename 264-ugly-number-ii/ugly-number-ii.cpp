class Solution {
public:
    int nthUglyNumber(int n) {
        //min heap
        priority_queue<long , vector<long>,greater<long>>pq;
        set<long>st;
        pq.push(1);
        st.insert(1);
        long elem =1;
        int i=0;
        while(i<n)
        {
            elem=pq.top();
            pq.pop();
           
        if(st.find(elem*2)==st.end()){
            pq.push(elem*2);
            st.insert(elem*2);
        }
            
        if(st.find(elem*3)==st.end()){
            pq.push(elem*3);
            st.insert(elem*3);
        }
            
        if(st.find(elem*5)==st.end()){
            pq.push(elem*5);
            st.insert(elem*5);
        }
            
         
            
            i++;
        }
        return static_cast<int>(elem);
        
    }
};