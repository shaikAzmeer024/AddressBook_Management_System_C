#include "contact.h"


 /* =========================================================
                    NAME VALIDATION
   ========================================================= */

int validate_name(char *name)
{
    // Check if the name is empty
    if(name[0] == '\0')
    {
        printf("Invalid Name! Try again.\n");

        // Return 0 if name is invalid
        return 0;
    }

    // Check each character of the name
    for(int i = 0; name[i] != '\0'; i++)
    {
        // Allow only alphabets, numbers, spaces and dots
        if(!isalnum((unsigned char)name[i]) && name[i] != ' ' && name[i] != '.')
        {
            printf("Invalid Name! Try again.\n");

            // Return 0 if an invalid character is found
            return 0;
        }
    }

    // Return 1 if the name is valid
    return 1;
}


/* =========================================================
                    PHONE VALIDATION
   ========================================================= */

int validate_phone(char *phone, AddressBook *addressBook) 
{ 
    // Check whether the phone number contains exactly 10 digits
    if(strlen(phone) != 10) 
    { 
        printf("Invalid Phone Number.\n"); 
 
        // Return 0 if the phone number length is invalid
        return 0; 
    } 
 
    // Check each character of the phone number
    for(int i = 0; phone[i] != '\0'; i++) 
    { 
        // Make sure every character is a digit
        if(!isdigit((unsigned char)phone[i])) 
        { 
            printf("Phone number must contain only digits.\n"); 

            // Return 0 if a non-digit character is found
            return 0; 
        } 
    } 
 
    /* Check duplicate phone numbers */

    // Compare the entered phone number with existing contacts
    for(int i = 0; i < addressBook->contactCount; i++) 
    { 
        if(strcmp(phone, addressBook->contacts[i].phone) == 0) 
        { 
            printf("Phone number already exists.\n"); 

            // 0  phone number already exists
            return 0; 
        } 
    } 

    // Return 1 if the phone number is valid and unique
    return 1; 
}


/* =========================================================
                    EMAIL VALIDATION
   ========================================================= */

int validate_email(char *email, AddressBook *addressBook)
{
    // Pointer used to find "@gmail.com" in the email
    char *gmail;

    /* Email should not start with a number */

    // Check whether the first character is a digit
    if(email[0] >= '0' && email[0] <= '9')
    {
        printf("Email should not start with a digit!\n");

        // Return 0 if email starts with a digit
        return 0;
    }

    // Find "@gmail.com" in the email
    gmail = strstr(email, "@gmail.com");


    /* Must end with @gmail.com */

    // Check whether "@gmail.com" exists and is at the end
    if(gmail == NULL || strcmp(gmail, "@gmail.com") != 0)
    {
        printf("Email must end with @gmail.com\n");

        // Return 0 if the email format is invalid
        return 0;
    }

    /* Something must exist before @gmail.com */

    // Check whether the email username is empty
    if(gmail == email)
    {
        printf("Invalid Email!\n");

        // Return 0 if nothing exists before "@gmail.com"
        return 0;
    }


    /* Check email username */

    // Check each character before "@gmail.com"
    for(char *p = email; p < gmail; p++)
    {
        // Allow only lowercase letters, digits and dots
        if(!islower((unsigned char)*p) && !isdigit((unsigned char)*p) && *p != '.')
        {
            printf("Invalid Email! Try again.\n");

            // Return 0 if an invalid character is found
            return 0;
        }
    }

    /* Check duplicate email */

    // Compare the email with all existing contacts
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(email, addressBook->contacts[i].email) == 0)
        {
            printf("Email already exists.\n");

            // Return 0 if the email already exists
            return 0;
        }
    }

    // Return 1 if the email is valid and unique
    return 1;
}