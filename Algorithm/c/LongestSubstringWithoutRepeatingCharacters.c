#include <stdio.h>
#include <stdlib.h>

//0 , not all different
//1 , all different
int dif_str(char *s, int len)
{
    int i=0;
    char str[256]={0};
   
    memset(str,0,sizeof(256));
    
    //aa
    //len=2
    //
    
    for(i=0;i<len;i++)
    {
        if( str[*(s+i)]  ==0 )
            str[*(s+i)] = 1;
        else // already have the same character
            return 0;    
    }
    return 1;
}

int lengthOfLongestSubstring_1(char *s)
{
    int len=strlen(s);
    int i,j,r;
    //start from 2,
    int max=1;
    if (len==0 || len==1)
       return len;
   
    for(i=0;i<len;i++)    
    {    
        for(j=2;j<=len;j++)
        {
            if(i+j>len)
                break;
            r=dif_str(s+i,j);
            if(r)
            {
                if(j>max)
                    max=j;
            }    
            
        }
    }     
    return max;   
}

int lengthOfLongestSubstring(char *s)
{
    int len=strlen(s);
    int i,j,r;
    //start from 2,
    char temp[100]={0};
    int max=0;
    if (len==0 || len==1)
       return len;
       
    max=1;
    i=0;
    j=i+max;
    //
    //  len 2
    //  max 1
    //  i  1
    //  j  2
    //
    while( i <= (len-max)  )
    {
        //printf("\n in while, max=%d ",max);
        if(max==len)    
        {       
            //printf("\n return 111, max=%d ",max);
            return max;
        }
        if( (len-max) ==i)
        {    
            //printf("\n return 222, max=%d ",max);
            return max;
        }
        r=dif_str(s+i,j-i+1);
        //printf("\n 111 r : %d ",r);
        if(r==1)
        {
            if( (j-i+1) > max)    
                max=j-i+1;
            j++;
            if(j==len)
            {
                i++;
                j=i+max;
            } 
            continue;
        }    
        //if all char all different
        else
        {
            i++;
            j=i+max;
            
        }    
    }
    //printf("\n return 333, max=%d ",max);

    return max;

}

