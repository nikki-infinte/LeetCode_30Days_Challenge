class Solution {
public:

    string reverse(string n)
    {
        int start=0;
        int end =n.length()-1;
        while(start <= end)
        {
            swap(n[start],n[end]);
            start++;
            end--;
        }
        return n;
    }
    string multiply(string num1, string num2) {
        string rev1 = reverse(num1);
        string rev2 =reverse(num2);
           int *arr = new int[rev1.length() + rev2.length()]();
        for(int i=0;i<rev1.size();i++)
        {
            int carry =0;
            int start =i;
            for(int j=0;j<rev2.size();j++)
            {
                int n1 = rev1[i]-'0';
                int n2 =rev2[j]-'0';

                int sum =(n1 *n2)+arr[start]+carry;
                int base =sum %10;
                carry =sum/10;
                arr[start++]=base;

            }

            if(carry !=0)arr[start]=carry;
        }

        // Fix: Getting correct size of array
        int i = rev1.length() + rev2.length() - 1;
        while (i > 0 && arr[i] == 0) i--;

        string ans = "";
        while (i >= 0) {
            ans += (arr[i] + '0'); // Fix: Use arr[i] instead of res[i]
            i--;
        }

        delete[] arr; // Fix: Avoid memory leak

        return ans;
    }
};