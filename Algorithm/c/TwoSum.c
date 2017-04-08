/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) 
{
    int i=0,j=0,sum=0;
    int *arr=NULL;
    for(i=0;i<numsSize;i++)
    {
        printf("%d, ",nums[i]);
    }
    printf("\n target :%d \n",target);
    for(i=0;i<numsSize-1 ; i++ )
    {
        for(j=i+1;j<numsSize;j++)
        {
            sum=nums[i] + nums[j];
            printf("\n i : %d, j: %d ",i,j);
            printf("\n     array:   %d,  %d ",nums[i],nums[j]);
            
            if(sum==target)
            {
                printf("\n match the target ,i : %d, j : %d \n",i,j);
                arr=(int *)malloc(8);
                if(arr==NULL)
                    return NULL;
                *arr=i;
                *(arr+1)=j;
                return arr;  
            }
        }
    }
    return arr;    
}

