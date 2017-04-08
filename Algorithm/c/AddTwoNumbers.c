/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode*  create(int i)
{
   struct ListNode  *tmp=NULL;   
   tmp =  (struct ListNode*) malloc(sizeof(struct ListNode));
   tmp->next=NULL;
   tmp->val =i;
   return tmp;
        
}
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode  *ret=NULL,*ret_list= NULL,*tmp=NULL;
    char b_first=1;

    /*
    ret_list = (ListNode*) malloc(sizeof(ListNode));
    ret_list->val=0;
    ret_list->next=NULL;
    */
    int increment=0;
    while( l1 != NULL || l2 != NULL || increment==1 )
    {
        if(tmp!=NULL)
            free(tmp);
        tmp =  (struct ListNode*) malloc(sizeof(struct ListNode));
        tmp->next=NULL;
        tmp->val = 0; //init
        if(l1 != NULL)
        {
            tmp->val+=l1->val;
            l1=l1->next;
        }
        if(l2 != NULL)
        {
            tmp->val+=l2->val;
            l2=l2->next;
        }
            
        tmp->val +=increment;
        if(tmp->val >= 10 )
        {
            tmp->val -=10;
            increment=1;
        }    
        else
            increment=0;
        
        
        
        if(ret_list==NULL)
        {
            ret_list = create(tmp->val);
            ret = ret_list;
        }                
        else
        {
            ret_list->next=create(tmp->val);
            ret_list=ret_list->next;
         //   ret_list->next=tmp;
        }
        
     }
     return ret;
}
