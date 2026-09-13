#include "contact.h"


/* =============================================================================
                                     CREATE CONTACT
   ============================================================================ */

void createContact(AddressBook *addressBook)
{
    char name[50];
    char phone[20];
    char email[50];
    char ch;

    if(addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("Address Book is full.\n");
        return;
    }

    /* ---------------- NAME ---------------- */
    do
    {
        printf("\nEnter the Name: ");
        scanf(" %49[^\n]", name);

    } while(validate_name(name) == 0);

    /* ---------------- PHONE ---------------- */
    do
    {
        printf("Enter the Phone No.: ");
        scanf(" %19[^\n]", phone);

    } while(validate_phone(phone, addressBook) == 0);

    /* ---------------- EMAIL ---------------- */
    do
    {
        printf("Enter the Email ID: ");
        scanf(" %49s", email);

    } while(validate_email(email, addressBook) == 0);

    /* Show entered data */

    printf("\nYou Entered:\n");

    printf("%-20s %-15s %-30s\n","Name","Phone Number","Email");

    printf("%-20s %-15s %-30s\n",name,phone,email);

    // Ask the user whether to save the contact
    printf("\nDo you want to Save the Contact (Y/N): ");

    scanf(" %c", &ch);

    if(ch == 'Y' || ch == 'y')
    {
        // Copy the entered name into the AddressBook
        strcpy(addressBook->contacts[addressBook->contactCount].name,name);

        // Copy the entered phone number into the AddressBook
        strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);

        // Copy the entered email into the AddressBook
        strcpy(addressBook->contacts[addressBook->contactCount].email,email);

        // Increase the contact count after saving the contact
        addressBook->contactCount++;

        printf("Contact Saved!!\n");
    }
    else
    {
        printf("Contact not saved.\n");
    }
}

/* ======================================================================================
                                      SEARCH CONTACT
   =======================================================================================*/

int searchContact(AddressBook *addressBook)
{
    int option;
    char name[50];
    char phone[20];
    char email[50];

    if(addressBook->contactCount == 0)
    {
        printf("No contacts saved !!\n");
        return 1;
    }

    printf("\n========== SEARCH CONTACT ==========\n");

    printf("1. Search by Name\n");
    printf("2. Search by Phone Number\n");
    printf("3. Search by Email\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");

    scanf("%d", &option);

    switch(option)
    {
        case 1:

            printf("Enter the Name: ");
            scanf(" %49[^\n]", name);

            search_by_name(name, addressBook);
            break;

        case 2:
            printf("Enter the Phone Number: ");
            scanf(" %19s", phone);

            search_by_phone(phone, addressBook);
            break;


        case 3:
            printf("Enter the Email: ");
            scanf(" %49s", email);

            search_by_email(email, addressBook);
            break;


        case 4:
            printf("Exit Search Contact.\n");
            break;

        default:
            printf("Invalid Choice!\n");
    }
    return 0;
}


/* ===================================================================================
                                    SEARCH BY NAME
   ================================================================================= */

int search_by_name(char *name, AddressBook *addressBook)
{
    int found = 0;
    int sno = 1;

    addressBook->ir_size = 0;

    for(int i = 0;i < addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].name, name) == 0)
        {
            if(found == 0)
            {
                printf("\n----- CONTACT LIST -----\n\n");

                printf("%-5s %-20s %-15s %-30s\n","S.No","Name","Phone","Email");

                printf("---------------------------------------------------------------------\n");
            }

            printf("%-5d %-20s %-15s %-30s\n",sno,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);  
            
            addressBook->index_record[found] = i;
            found++;
            sno++;
        }
    }

    addressBook->ir_size = found;
    if(found == 0)
    {
        printf("Contact not found.\n");

        return 1;
    }
    return 0;
}


/* ==============================================================================
                                  SEARCH BY PHONE
   ======================================================================== */

int search_by_phone(char *phone, AddressBook *addressBook)
{
    addressBook->ir_size = 0;

    for(int i = 0;i < addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].phone, phone) == 0)
        {
            printf("\n----- CONTACT LIST -----\n\n");

            printf("%-5s %-20s %-15s %-30s\n","S.No","Name","Phone","Email");

            printf("---------------------------------------------------------------------\n");

            printf("%-5d %-20s %-15s %-30s\n",1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

            addressBook->index_record[0] = i;
            addressBook->ir_size = 1;

            return 0;
        }
    }
    printf("Contact not found.\n");
    return 1;
}


/* ===================================================================================
                                    SEARCH BY EMAIL
   ================================================================================ */

int search_by_email(char *email, AddressBook *addressBook)
{
    addressBook->ir_size = 0;


    for(int i = 0;i < addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].email, email) == 0)
        {
            printf("\n----- CONTACT LIST -----\n\n");

            printf("%-5s %-20s %-15s %-30s\n","S.No","Name","Phone","Email");

            printf("---------------------------------------------------------------------\n");

            printf("%-5d %-20s %-15s %-30s\n",1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

            addressBook->index_record[0] = i;
            addressBook->ir_size = 1;

            return 0;
        }
    }
    printf("Contact not found.\n");

    return 1;
}

/* =========================================================
                    EDIT CONTACT
   ========================================================= */

void editContact(AddressBook *addressBook)
{
    int option;

    char name[50];
    char phone[20];
    char email[50];

    if(addressBook->contactCount == 0)
    {
        printf("Address Book is Empty!\n");
        return;
    }

    printf("\n========== EDIT CONTACT ==========\n");

    printf("\n------------ Search Contact ------------\n");

    printf("1. Search by Name\n");
    printf("2. Search by Phone Number\n");
    printf("3. Search by Email\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("Enter the Name: ");
            scanf(" %49[^\n]", name);

            edit_by_name(name, addressBook);
            break;

        case 2:
            printf("Enter the Phone Number: ");
            scanf(" %19s", phone);

            edit_by_phone(phone, addressBook);
            break;

        case 3:
            printf("Enter the Email: ");
            scanf(" %49s", email);

            edit_by_email(email, addressBook);
            break;

        case 4:
            printf("Exit Edit Contact.\n");
            break;

        default:
            printf("Invalid Choice!\n");
    }
}

/* ============================================================================
                                    EDIT BY NAME
   =========================================================================== */

int edit_by_name(char *name, AddressBook *addressBook)
{
    int selected;

    if(search_by_name(name, addressBook) == 1)
    {
        return 1;
    }

    printf("\nEnter S.No to edit: ");
    scanf("%d", &selected);

    if(selected < 1 || selected > addressBook->ir_size)
    {
        printf("Invalid S.No.\n");
        return 1;
    }
    return edit_contact(addressBook->index_record[selected - 1],addressBook);
}

/* ============================================================================================
                                        EDIT BY PHONE
   ============================================================================================ */

int edit_by_phone(char *phone, AddressBook *addressBook)
{
    if(search_by_phone(phone, addressBook) == 1)
    {
        return 1;
    }
    return edit_contact(addressBook->index_record[0],addressBook);
}

/* ===============================================================================================
                                     EDIT BY EMAIL
   ============================================================================================ */

int edit_by_email(char *email, AddressBook *addressBook)
{
    if(search_by_email(email, addressBook) == 1)
    {
        return 1;
    }
    return edit_contact(addressBook->index_record[0],addressBook);
}


/* =============================================================================================
                                    EDIT SELECTED CONTACT
   =========================================================================================== */

int edit_contact(int index, AddressBook *addressBook)
{
    int option;

    char new_name[50];
    char new_phone[20];
    char new_email[50];

    printf("\nContact found.\n");

    printf("Name  : %s\n",addressBook->contacts[index].name);
    printf("Phone : %s\n",addressBook->contacts[index].phone);
    printf("Email : %s\n",addressBook->contacts[index].email);

    printf("\nWhat do you want to edit?\n");

    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");

    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option)
    {
        /* ---------------- NAME ---------------- */
        case 1:
            do
            {
                printf("Enter New Name: ");
                scanf(" %49[^\n]", new_name);

            } while(validate_name(new_name) == 0);

            strcpy(addressBook->contacts[index].name,new_name);

            printf("Name updated successfully.\n");
            break;

        /* ---------------- PHONE ---------------- */

        case 2:
        {
            int valid;

            do
            {
                valid = 1;

                printf("Enter New Phone: ");
                scanf(" %19s", new_phone);

                if(strlen(new_phone) != 10)
                {
                    printf("Invalid Phone Number.\n");
                    valid = 0;
                }

                for(int i = 0;new_phone[i] != '\0' && valid;i++)
                {
                    if(!isdigit((unsigned char)new_phone[i]))
                    {
                        printf("Phone number must contain only digits.\n");
                        valid = 0;
                    }
                }

                if(valid)
                {
                    for(int i = 0;i < addressBook->contactCount;i++)
                    {
                        if(i != index &&strcmp(new_phone,addressBook->contacts[i].phone) == 0)
                        {
                            printf("Phone number already exists.\n");
                            valid = 0;
                            break;
                        }
                    }
                }

            } while(valid == 0);

            strcpy(addressBook->contacts[index].phone,new_phone);
            printf("Phone Number updated successfully.\n");

            break;
        }

        /* ---------------- EMAIL ---------------- */

        case 3:
        {
            int valid;

            do
            {
                printf("Enter New Email: ");
                scanf(" %49s", new_email);

                valid = 1;

                char *gmail = strstr(new_email, "@gmail.com");

                if(new_email[0] >= '0' && new_email[0] <= '9')
                {
                    printf("Email should not start with a digit!\n");
                    valid = 0;
                }

                if(gmail == NULL || strcmp(gmail, "@gmail.com") != 0)
                {
                    printf("Email must end with @gmail.com\n");
                    valid = 0;
                }

                if(gmail == new_email)
                {
                    printf("Invalid Email!\n");
                    valid = 0;
                }

                if(valid)
                {
                    for(char *p = new_email;p < gmail;p++)
                    {
                        if(!islower((unsigned char)*p) &&!isdigit((unsigned char)*p) && *p != '.')
                        {
                            printf("Invalid Email!\n");
                            valid = 0;
                            break;
                        }
                    }
                }

                if(valid)
                {
                    for(int i = 0;i < addressBook->contactCount;i++)
                    {
                        if(i != index &&strcmp(new_email, addressBook->contacts[i].email) == 0)
                        {
                            printf("Email already exists.\n");
                            valid = 0;
                            break;
                        }
                    }
                }

            } while(valid == 0);

            strcpy(addressBook->contacts[index].email,new_email);
            printf("Email updated successfully.\n");

            break;
        }

        default:
            printf("Invalid choice.\n");
            return 1;
    }
    return 0;
}

/* ==========================================================================================
                                      DELETE CONTACT
   ========================================================================================== */

void deleteContact(AddressBook *addressBook)
{
    int option;

    char name[50];
    char phone[20];
    char email[50];


    if(addressBook->contactCount == 0)
    {
        printf("Address Book is Empty!\n");

        return;
    }

    printf("\n========== DELETE CONTACT ==========\n");

    printf("1. Delete by Name\n");
    printf("2. Delete by Phone Number\n");
    printf("3. Delete by Email\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("Enter the Name: ");
            scanf(" %49[^\n]", name);

            delete_by_name(name, addressBook);
            break;

        case 2:
            printf("Enter the Phone Number: ");
            scanf(" %19s", phone);

            delete_by_phone(phone, addressBook);
            break;

        case 3:
            printf("Enter the Email: ");
            scanf(" %49s", email);

            delete_by_email(email, addressBook);
            break;

        case 4:
            printf("Exit Delete Contact.\n");
            break;

        default:
            printf("Invalid Choice!\n");
    }
}

/* =======================================================================================
                                     DELETE BY NAME
   ======================================================================================= */

int delete_by_name(char *name, AddressBook *addressBook)
{
    int selected;

    if(search_by_name(name, addressBook) == 1)
    {
        return 1;
    }

    printf("\nEnter S.No to delete: ");
    scanf("%d", &selected);

    if(selected < 1 || selected > addressBook->ir_size)
    {
        printf("Invalid S.No.\n");

        return 1;
    }

    int index = addressBook->index_record[selected - 1];

    for(int i = index;i < addressBook->contactCount - 1;i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    printf("Contact Deleted!!\n");
    return 0;
}


/* =======================================================================================
                                     DELETE BY PHONE
   ==================================================================================== */

int delete_by_phone(char *phone, AddressBook *addressBook)
{
    if(search_by_phone(phone, addressBook) == 1)
    {
        return 1;
    }

    int index = addressBook->index_record[0];

    for(int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    printf("Contact Deleted!!\n");
    return 0;
}


/* ======================================================================================
                                   DELETE BY EMAIL
   =================================================================================== */

int delete_by_email(char *email, AddressBook *addressBook)
{
    if(search_by_email(email, addressBook) == 1)
    {
        return 1;
    }

    int index = addressBook->index_record[0];

    for(int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    printf("Contact Deleted!!\n");
    return 0;
}


/* ==============================================================================================
                                         SORT CONTACTS
   ============================================================================================ */

static void sortContacts(AddressBook *addressBook)
{
    Contact temp;

    for(int i = 0;i < addressBook->contactCount - 1;i++)
    {
        for(int j = 0;j < addressBook->contactCount - i - 1;j++)
        {
            if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j + 1].name) > 0)
            {
                temp =addressBook->contacts[j];

                addressBook->contacts[j] = addressBook->contacts[j + 1];

                addressBook->contacts[j + 1] = temp;
            }
        }
    }
}

/* ===========================================================================================
                                    LIST CONTACTS
   ========================================================================================== */

void listContacts(AddressBook *addressBook)
{
    if(addressBook->contactCount == 0)
    {
        printf("Address Book is Empty!\n");
        return;
    }

    sortContacts(addressBook);

    printf("\n----- CONTACT LIST -----\n\n");

    printf("%-5s %-20s %-15s %-30s\n","S.No","Name","Phone","Email");

    printf("---------------------------------------------------------------------\n");

    for(int i = 0;i < addressBook->contactCount;i++)
    {
        printf("%-5d %-20s %-15s %-30s\n",i + 1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}


/* ============================================================================================
                                     SAVE CONTACTS
   ============================================================================================ */

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fptr;
    fptr = fopen("contact.csv", "w");

    if(fptr == NULL)
    {
        perror("contact.csv");
        return;
    }

    fprintf(fptr," # %d\n",addressBook->contactCount);

    for(int i = 0;i < addressBook->contactCount;i++) 
    {
        fprintf(fptr,"%s , %s , %s\n" ,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(fptr);

    printf("Contacts saved successfully.\n");
}


/* ===========================================================================================
                                         LOAD CONTACTS
   ============================================================================================ */

void load_contacts_from_file(AddressBook *addressBook)
{
    FILE *fptr;
    fptr = fopen("contact.csv", "r");

    if(fptr == NULL)
    {
        printf("No saved contacts found.\n");

        return;
    }

    if(fscanf(fptr," # %d\n",&addressBook->contactCount) != 1)
    {
        fclose(fptr);
        addressBook->contactCount = 0;
        return;
    }

    if(addressBook->contactCount > MAX_CONTACTS)
    {
        addressBook->contactCount = MAX_CONTACTS;
    }

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(fscanf(fptr," %49[^,], %19[^,], %49[^\n]",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email) != 3)
        {
            addressBook->contactCount = i;
            break;
        }
    }
    fclose(fptr);
}