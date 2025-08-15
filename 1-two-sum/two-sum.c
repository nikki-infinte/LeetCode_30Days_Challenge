/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i=0;i<numsSize;i++){
        int elem = nums[i];
        for(int j=i+1;j<numsSize;j++){

            if(elem + nums[j] == target){
                int * res = (int*)malloc(2*sizeof(int));
                res[0] = i;
                res[1] = j;
                *returnSize = 2;
                return res;
            }
        }

    }
    *returnSize =0;
    return NULL;
}