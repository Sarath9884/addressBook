#include "contact.h"
int ed_name(AddressBook *addressBook,int val)
{
    printf("Enter The New Name--\n");
    char e_name[20];
    name:
    scanf(" %[^\n]",e_name);
    if(!is_name(e_name))
    {
        strcpy(addressBook->contacts[val].name,e_name);
        printf("Name Edited Success--..\n");
    }
    else
    {
        printf("Invalid name\n");
        goto name;
    }
}
int ed_phone(AddressBook *addressBook,int val)
{
    printf("Enter New phonenumber--\n");
    char e_phone[20];
    phone:
    scanf(" %[^\n]",e_phone);
    if(!is_phone(addressBook,e_phone))
    {
        strcpy(addressBook->contacts[val].phone,e_phone);
        printf("Phone number Edited--.\n");
    }
    else
    {
        printf("Inavlid Number..Re-Enter\n");
        goto phone;
    }
}
int ed_mail(AddressBook *addressBook,int val)
{
    printf("Enter New Email Id--\n");
    char e_mail[40];
    mail:
    scanf(" %[^\n]",e_mail);
    if(! is_email(addressBook,e_mail))
    {
        strcpy(addressBook->contacts[val].email,e_mail);
        printf("Email Edited--..\n");
    }
    else
    {
        printf("Invalid Email id !!\n");
        goto mail;
    }

}