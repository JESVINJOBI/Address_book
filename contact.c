#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"
#include <ctype.h>

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the choosen criteria
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    do 
    {
        printf("Enter the name : ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
        if(!isValidName(addressBook->contacts[addressBook->contactCount].name))
            printf("Invalid name.Try Again.\n");
    }while(!isValidName(addressBook->contacts[addressBook->contactCount].name));

    do
    {
        printf("Enter the phone : ");
        scanf("%s",addressBook->contacts[addressBook->contactCount].phone);
        if(!isValidPhone(addressBook->contacts[addressBook->contactCount].phone))
            printf("Invalid phone.Try Again.\n");
        else if(isDuplicatePhone(addressBook,addressBook->contacts[addressBook->contactCount].phone))
            printf("Phone number already exists. Try Again.\n");
    }while(!isValidPhone(addressBook->contacts[addressBook->contactCount].phone) || isDuplicatePhone(addressBook,addressBook->contacts[addressBook->contactCount].phone));

    do
    {
        printf("Enter the email : ");
        scanf("%s",addressBook->contacts[addressBook->contactCount].email);
        if(!isValidEmail(addressBook->contacts[addressBook->contactCount].email))
            printf("Invalid email.Try Again.\n");
        else if(isDuplicateEmail(addressBook,addressBook->contacts[addressBook->contactCount].email))
            printf("Email already exists. Try Again.\n");
    }while(!isValidEmail(addressBook->contacts[addressBook->contactCount].email) || isDuplicateEmail(addressBook,addressBook->contacts[addressBook->contactCount].email));

    addressBook->contactCount++; 
    printf("Contact created successfully.\n");
}


void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}

int isValidName(char name[])
{
    if(strlen(name)>=2)
    {
        for(int i=0;name[i]!='\0';i++)
        {
            if(!isalpha(name[i])&&name[i]!=' ')
                return 0;
        }
        return 1;
    }
    else
        return 0;
}
int isValidPhone(char phone[])
{

    if(strlen(phone)==10)
    {
        for(int i=0;phone[i]!='\0';i++)
        {
            if(!isdigit(phone[i]))
                return 0;
        }
        if(phone[0]>='6'&&phone[0]<='9')
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
int isValidEmail(char email[])
{
    int len = strlen(email);
    int atCount = 0;
    int atIndex = -1;

    if (len < 5 || strcmp(email + len - 4, ".com") != 0)
    {
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        if (isupper(email[i]))
        {
            return 0;
        }

        if (email[i] == '.' && email[i + 1] == '.')
        {
            return 0;
        }

        if (email[i]=='@')
        {
            atCount++;
            atIndex=i;
        }
    }

    if (atCount!= 1)
    {
        return 0;
    }

    if (atIndex == 0 || atIndex == len - 1)
    {
        return 0;
    }

    if (email[atIndex - 1]=='.' || email[atIndex + 1]=='.')
    {
        return 0;
    }

    int dotAfterAt = 0;
    for (int i =atIndex + 1; i<len; i++)
    {
        if (email[i]=='.')
        {
            dotAfterAt=1;
            break;
        }
    }

    if (!dotAfterAt)
    {
        return 0;
    }
    return 1;
}
int isDuplicatePhone(AddressBook *addressBook, char phone[])
{
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].phone,phone)==0)
            return 1;
    }
    return 0;
}
int isDuplicateEmail(AddressBook *addressBook, char email[])
{
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].email,email)==0)
            return 1;
    }
    return 0;
}