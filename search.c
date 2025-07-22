#include "contact.h"
int dupe[30];
int s_name(AddressBook  *str)
{
    ppp:
    printf("Enter Name to search\n");
    int j=0,cc=1,i,ret;
    char searchname[20];
    int count=str->contactCount;
    scanf(" %[^\n]",searchname);
    if(count==0)
    {
        printf("\t !!Create Contact First!!!\n");
        return 0;
    }
    ret=is_name(searchname);
      if( ret==1)
      {
        printf("Name MUST contain Alphabets ONLY!!!\n");
          goto ppp;
       }
     if(count>0)
    {
        for(i=0;i<count;i++)
        {
            if(strcmp(str->contacts[i].name,searchname)==0)
            {
                if(j==0)
                {
                    printf("Founded Name-\n");
                }
                dupe[j]=i;
                j++;
                printf("-------------------\n");
                printf("Serial Number-[%d]-\n",cc);
                printf("-------------------\n");
                cc++;
                //printf("Founded Name-\n");
                //printf("-----------------\n");
                printf("%s\n",str->contacts[i].name);
                printf("%s\n",str->contacts[i].phone);
                printf("%s\n",str->contacts[i].email);
            }
        }
         if(j==0)
        {
            printf("Name Mismatch !!\n");
            goto ppp;   
        }
           // printf("j==%d  \n",j);
        return j;
    }
}

int s_phone(AddressBook *str)
{
    int count=str->contactCount;
    int j=0,cc=1,ret;
    char searchphone[20];
    phph:
    printf("Enter Phone Number To Search\n");
    scanf(" %[^\n]",searchphone);
    if(count==0)
    {
        printf("!!Create Contact First!!!\n");
        return 0;
    }
    //   ret=is_phone(str,searchphone);
    //   printf("ret====%d\n",ret);
    //    if(ret==1)
    //    {
    //        printf("Name MUST contain Numbers ONLY!!!\n");
    //        goto phph;
    //    }
    for(int i=0;i<str->contactCount;i++)
    {
        if(strcmp(str->contacts[i].phone,searchphone)==0)
        {
             if(j==0)
                {
                    printf("Founded Phone number-\n");
                }
                dupe[j]=i;
                j++;
                printf("-------------------\n");
                printf("Serial Number-[%d]-\n",cc);
                printf("-------------------\n");
                cc++;
            printf("%s\n",str->contacts[i].name);
            printf("%s\n",str->contacts[i].phone);
            printf("%s\n",str->contacts[i].email);
            return j;
        }
    }   
    if(j==0)
        {
            printf("Phone number Not found\n");
            goto phph;
        }
    //return 0;
}
int s_mail(AddressBook *str)
{
    int j=0,cc=1;
    int count=str->contactCount;
    emem:
    printf("Enter Email-id to check\n");
    char searchemail[60];
    scanf(" %[^\n]",searchemail);
    if(count==0)
    {
        printf("\t !!Create Contact First!!!\n");
        return 0;
    }
    if(count>0)
    {
    for(int i=0;i<str->contactCount;i++)
    {
        if(strcmp(str->contacts[i].email,searchemail)==0)
        {
              if(j==0)
                {
                    printf("Founded Phone number-\n");
                }
                dupe[j]=i;
                j++;
                printf("-------------------\n");
                printf("Serial Number-[%d]-\n",cc);
                printf("-------------------\n");
                cc++;
            printf("%s\n",str->contacts[i].name);
            printf("%s\n",str->contacts[i].phone);
            printf("%s\n",str->contacts[i].email);
            return j;
        }
    }
    if(j==0)
    
    {
        printf("Emaild id Not--Found!!\n");
            goto emem;
    }
    }

}
