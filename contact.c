#include "contact.h"
#include "file.h"
//#include "populate.h"
void listContacts(AddressBook *addressBook/*, int sortCriteria*/) 
{
{
    int count = addressBook->contactCount;
    if (count != 0)
    {
        printf("Listing Contacts:\n");
        printf("..........................\n");
        int i;
        for (i = 0; i < count; i++)
        {
            printf("..........................\n");
            printf("Entry No: %d\n", i + 1);
            printf("Name:%s\n", addressBook->contacts[i].name);
            printf("Phone No:%s\n", addressBook->contacts[i].phone);
            printf("Phone No:%s\n", addressBook->contacts[i].email);
            printf("..........................\n");
            printf("\n");
        }
    }
    else
         {
               printf("No entries as of now!\n");
         }
}   
}
void initialize(AddressBook *addressBook) 
{
        // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    do
    {
    printf("Enter The Name:\n ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    if(  is_name(addressBook->contacts[addressBook->contactCount].name) )
    {
     printf("Enter a valid name\n");   
    }
    }while( is_name(addressBook->contacts[addressBook->contactCount].name) );
    do
    {
    printf("Enter the Phonenumber:\n");
    //printf("Enter a valid Phonenumber!\n");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
    if(  is_phone(addressBook,addressBook->contacts[addressBook->contactCount].phone))
    {
        printf("Enter a valid Phonenumber!\n");
    }
    }while( is_phone(addressBook,addressBook->contacts[addressBook->contactCount].phone));

    do
    {
    printf("Enter Email id\n");
     scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
     if( is_email(addressBook,addressBook->contacts[addressBook->contactCount].email))
     {
        printf("Enter a valid Email id\n");
     }
    }while(is_email(addressBook,addressBook->contacts[addressBook->contactCount].email));
    addressBook->contactCount++;
}

int searchContact(AddressBook *addressBook) 
{
    printf("Enter the choice\n");
    printf("Enter 1 to search by Name\n");
    printf("Enter 2 to search by phonenumber\n");
    printf("Enter 3 to search by Email id\n");
    int ch,ind;
    __fpurge(stdin);
    searchh:
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
          
                ind=s_name(addressBook);
               break;
        }
        case 2:
        {
             ind=s_phone(addressBook);
            break;
        }
        case 3:
        {
             ind=s_mail(addressBook);
            break;
        }
        default:
        {
            printf("Enter the Given Choices--!\n");
            __fpurge(stdin);
            goto searchh;
        }
    }
    return ind;
}

void editContact(AddressBook *addressBook)
{
    int count=addressBook->contactCount;
    int ch;

	int val=searchContact(addressBook);
   // printf("   vaal===%d   \n",val);
    int i;
    //searchContact(addressBook);
    if(val>1)
    {
        int s;
        printf("Which Name to EDIT\n");
        printf("-----------------\n");
        scanf("%d",&s);
        i=dupe[s-1];
    } 
    else
        {//printf("Which Name to EDIT\n");
        printf("-----------------\n");
            i=dupe[0];
            
        }
      //  printf("i====%d\n",i);
    if(count>0)
    {
        printf("Details To be Edited\n");
        printf("Enter your Choice --\n");
        printf(" 1--EDIT---Name----\n");
        printf(" 2--EDIT----Phone--\n");
        printf(" 3--EDIT----Email--\n");
        editt:
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                ed_name(addressBook,i);
                break;
            }
            case 2:
            {
                ed_phone(addressBook,val);
                break;
            }
            case 3:
            {
                ed_mail(addressBook,val);
                break;
            }
            default:
            {
                printf("Enter the Given Choices..//\n");
                __fpurge(stdin);
                goto editt;

            }
        }

        
    }

    
}

void deleteContact(AddressBook *addressBook)
{
     printf("Which contact should be Deleted\n");
     int ind;
     ind=searchContact(addressBook);
     if (ind==0)
     {
        return;
     }
    int count=addressBook->contactCount;
    if(count>0 && ind>1)
    {
        int d;
        indd:
        printf(" !!Print Serial No to Delete PermanentlYY!!!\n");
        scanf("%d",&d);
        if(d>ind)
        {
            printf("Invalid  \n");
            goto indd;
        }
        ind=dupe[d-1];
    }
    if (ind==1)
    {
        ind=dupe[0];
    }
    int cho;
    printf("Do you Want To DELETE !!!\n");
    printf("PRESS 1 TO CONFIRM or any number to EXIT\n");
    scanf("%d",&cho);
    if (cho==1 )
    {
        for(int i=ind;i<count-1;i++)
        {
            if(ind==count-1)
            {
                addressBook->contactCount -= 1;
                return;
            }
            else 
            {
                addressBook->contacts[i]=addressBook->contacts[i+1];
            }
        }
        {
            addressBook->contactCount -=1;
        }
        printf("Contact deleted Succesfully\n");
    }
    else
    {
        printf("Contact Not DELETED !!\n");
        return;
    }
}





