/*
    Project           :  Address Book Management System
    Name              :  Shaik Azmeer
    Registered Number :  26015_079

    -The Address Book project is a C-based application used to manage contacts such as names, phone numbers, and email addresses.
    -It provides features like adding, searching, editing, deleting, and displaying contacts efficiently.
    -File handling is used to save and load contact details, allowing the data to be maintained even after the program is closed.

*/
#include <stdio.h>
#include "contact.h"

int main()
{
    int choice;

    // Declare AddressBook structure variable
    AddressBook addressBook;

    // Initialize contact count to zero
    addressBook.contactCount = 0;

    // Initialize index/size variable to zero
    addressBook.ir_size = 0;


    // Load contacts from file //
    load_contacts_from_file(&addressBook);

    // Display menu repeatedly until user chooses Save & Exit
    do
    {
        printf("\n========== ADDRESS BOOK MENU ==========\n");

        printf("1. Create Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. List All Contacts\n");
        printf("6. Save & Exit\n");

        printf("=======================================\n");

        // Read user's menu choice
        printf("Enter your choice: ");
        
        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid choice. Please try again.\n");

            while(getchar() != '\n');

            continue;
        }

        // Perform operation based on user's choice
        switch(choice)
        {
            case 1:
                // Create a new contact
                createContact(&addressBook);
                break;

            case 2:
                // Search for an existing contact
                searchContact(&addressBook);
                break;

            case 3:
                // Edit an existing contact
                editContact(&addressBook);
                break;

            case 4:
                // Delete an existing contact
                deleteContact(&addressBook);
                break;

            case 5:
                // Display all contacts
                listContacts(&addressBook);
                break;

            case 6:
                // Save all contacts to file before exiting
                saveContactsToFile(&addressBook);
                printf("Saving and Exiting...\n");
                break;

            default:
                // Handle invalid menu choice
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 6);

    return 0;
}