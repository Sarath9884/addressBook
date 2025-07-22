#include "contact.h"

// to check name contains alohabets only
int is_name(const char* str)
{
    while(*str != '\0')
    {
        if(!isalpha(*str) && (*str) != ' ')
        {
            return 1;
        }
        str++;
    }
    return 0;
}
// to check phone number contains only numbers
int is_phone(AddressBook *addressBook,const char* str)
{   
    int j=0;
    if(strlen(str)!=10)
    {
        return 1;
    }
    while(str[j])
    {
    if(! isdigit(str[j]) )
    {
        return 1;
    }
    j++;
    }
   return unique(addressBook,str);
}
// length minimum 6
// only 1 @ 
// before and after @ isalnum

int is_email(AddressBook *addressBook,const char *str)
{
    int len=strlen(str);
        int i=0,a=0;
    for(i=0;i<len;i++)
    {
        if(str[i]=='@')
        {
            a++;
        }
    }
    if(a!=1)
    {
        return 1;
    }
        
    for(i=0;i<len;i++)
   {
        if(len <  6)
        {
            return 1;
        }
        if(str[i]=='@' ) 
        {
            if (! isalnum(str[i+1]))
            {
            return 1;
            }
            if (! isalnum(str[i-1]))
            {
            return 1;
            }
        }
        char* aptr=strchr(str,'@');
        char* dptr=strchr(str,'.');
        if (!isalnum(*(aptr+1)))  
        {
        return 1;
        }
        if (dptr && strcmp(dptr, ".com") == 0 && dptr > aptr)
    {
        return unique_mail(addressBook,str); 
    }
       return 1;
    }
        
}
// to check unique phone
int unique(AddressBook *str,const char* mob)
{
    static int p=1;
    int count=str->contactCount;
    for(int i=0;i<=count-1;i++)
    {
        if(strcmp(str->contacts[i].phone,mob)==0)
        {  
        
             if(p==1)
            {
             printf("Phone Number already EXISTS!!!\n");  
            } 
            p++;
            return 1;
           
        }
    }
    return 0;
}
// to check unique mail
int unique_mail(AddressBook *str,const char* maiil)
{
    static int m=1;
    int count=str->contactCount;
    for(int i=0;i<count;i++)
    {
        if(strcmp(str->contacts[i].email,maiil)==0)
        {
            if(m==1)
            {
            printf("Email ID already EXISTS!!!\n");
            }
            m++;
            return 1;
        }
    }
    return  0;

}