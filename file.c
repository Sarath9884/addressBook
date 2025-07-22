#include "contact.h"
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
  
    FILE *ptr;
    ptr=fopen("contacts.csv","w");
    if(ptr==NULL)
    {
        return;
    }
    int count=addressBook->contactCount;
    fprintf(ptr,"#%d\n",count);
    for(int i=0;i<count;i++)
    {
        fprintf(ptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        
    }
    fclose(ptr);
}

void loadContactsFromFile(AddressBook *addressBook)
{
     FILE *ptr;
    ptr=fopen("contacts.csv","r");
    if(ptr==NULL)
    {
        return;
    }
    fscanf(ptr,"#%d\n",&addressBook->contactCount);
    int count=addressBook->contactCount;
    //printf("%d\n",count);
    for(int i=0;i<count;i++)
    {
        fscanf(ptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

    }
    fclose(ptr);
}

