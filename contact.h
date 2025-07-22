#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include <stdio_ext.h>

//#include "file.h"
extern int dupe[30];

#define MAX_CONTACTS 100

typedef struct {
    char name[50]; 
    char phone[20];
    char email[50];
} Contact; 

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;


//save
//oid saveContactsToFile(AddressBook *addressBook);

//multiple name
//unique
 int unique(AddressBook *addressBook,const char* str);
 int unique_mail(AddressBook *str,const char* maiil);
// create contact
int is_name(const char* str);
int is_phone(AddressBook *addressBook,const char* str);
int is_email(AddressBook *addressBook, const char* str);

// search contact
 int s_name(AddressBook *addressBook);
 int s_phone(AddressBook *addressBook);
 int s_mail(AddressBook *addressBook);

 //Edit Contact
 int ed_name(AddressBook *addressBook,int val);
 int ed_phone(AddressBook *addressBook,int val);
 int ed_mail(AddressBook *addressBook,int val);

void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
//void saveContactsToFile(AddressBook *AddressBook);

#endif
