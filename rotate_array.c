/**
 *  Rotate Numbers Array
 *  Rotate an array of n elements to the right by k steps.
 *  For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 */

/*Solution1*/
void reverse(int *nums, int start, int end)
{
    while(start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        
        start++;
        end--;
    }
}


void rotate(int* nums, int numsSize, int k) 
{
    k = k % numsSize;
    if(k <= 0)
        return;
    
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
}


/*Solution2*/
void move(int nums[], int n)
{
    int last = nums[n-1];
    
    for(int i = n-1; i >=1; --i) {
        nums[i] = nums[i-1];
    }
    nums[0] = last;
}

void rotate(int *nums, int numsSize, int k)
{
    for(int i = 0; i < k; ++i)
        move(nums, numsSize);
}