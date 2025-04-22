class NumArray {
public:
vector<int>psum;
    NumArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(psum.empty())
            {
                psum.push_back(nums[i]);
            }else{
                psum.push_back(psum.back()+nums[i]);
            }
        }
    }
    
    int sumRange(int left, int right) {
        if(left ==0)return psum[right];

        return (psum[right]-psum[left-1] );
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */