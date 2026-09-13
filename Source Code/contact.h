#ifndef CONTACT_H
#define CONTACT_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CONTACTS 100

typedef struct
{
    char name[50];      // Store contact name

    char phone[20];     // Store contact phone number

    char email[50];    // Store contact email address

} Contact;


typedef struct
{
    Contact contacts[MAX_CONTACTS];      // Array to store all contacts

    int contactCount;         // Store the total number of contacts

    /* Used to remember contacts found by search.
       Edit/Delete use this to select by S.No. */

    int index_record[MAX_CONTACTS];         // Store indexes of contacts found during search

    int ir_size;                // Store the number of indexes currently recorded

} AddressBook;


/* -------------------------------Create --------------------------------------*/

// Function to create a new contact
void createContact(AddressBook *addressBook);


/*--------------------------------Search----------------------------------------*/

// Function to search for a contact
int searchContact(AddressBook *addressBook);

// Search contact by name
int search_by_name(char *name, AddressBook *addressBook);

// Search contact by phone number
int search_by_phone(char *phone, AddressBook *addressBook);

// Search contact by email
int search_by_email(char *email, AddressBook *addressBook);


/* -------------------------------------Edit-------------------------------------*/

// Function to edit an existing contact
void editContact(AddressBook *addressBook);

// Edit contact using its index
int edit_contact(int index, AddressBook *addressBook);

// Edit contact by name
int edit_by_name(char *name, AddressBook *addressBook);

// Edit contact by phone number
int edit_by_phone(char *phone, AddressBook *addressBook);

// Edit contact by email
int edit_by_email(char *email, AddressBook *addressBook);


/* ---------------------------------Delete -------------------------------------*/

// Function to delete a contact
void deleteContact(AddressBook *addressBook);

// Delete contact by name
int delete_by_name(char *name, AddressBook *addressBook);

// Delete contact by phone number
int delete_by_phone(char *phone, AddressBook *addressBook);

// Delete contact by email
int delete_by_email(char *email, AddressBook *addressBook);


/* ---------------------------------------List ------------------------------------*/

// Function to display all contacts
void listContacts(AddressBook *addressBook);


/* ---------------------------------File handling---------------------------------- */

// Load contacts from the file
void load_contacts_from_file(AddressBook *addressBook);

// Save contacts to the file
void saveContactsToFile(AddressBook *addressBook);


/* ----------------------------------Validation -------------------------------------*/

// Validate contact name
int validate_name(char *name);

// Validate phone number and check for duplicates
int validate_phone(char *phone, AddressBook *addressBook);

// Validate email and check for duplicates
int validate_email(char *email, AddressBook *addressBook);

#endif