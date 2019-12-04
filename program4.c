/**********************************************************************/
/*                                                                    */
/* Program Name: program4 - Database of Customer Accounts Records     */
/* Author:       Ian McPherson                                        */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS277, Data Structures and Algorithms                */
/* Date Written: October 4, 2019                                      */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* I pledge this assignment is my own first time work.                */
/* I pledge I did not copy or try to copy any work from the Internet. */
/* I pledge the only person I asked for help from was my teacher.     */
/* I pledge I did not attempt to help any student on this assignment. */
/* I understand if I violate this pledge I will receive a 0 grade.    */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */
/*                                           (signature)              */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program manages a database of customer accounts receivable    */
/* records, asking for the customer's name, amount owed, and          */
/* priority.  It will then clean the names of all non-letters, sort   */
/* the accounts by alphabetical order, and printing the accounts in   */
/* table format.                                                      */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* getchar, scanf, printf                         */
#include <stdlib.h> /* malloc, free, exit                             */
#include <string.h> /* strcmp                                         */
#include <ctype.h>  /* isalpha, toupper, tolower                      */

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define COURSE_NUMBER   "CS227" /* PCC assigned course number         */
#define PROGRAM_NUMBER  4       /* Teacher assigned program number    */
#define PROGRAMMER_NAME "McPherson"
                                /* The programmer's last name         */
#define DB_ALLOC_ERR    1       /* Error allocating memory for        */
                                /* database of customer accounts      */
                                /* receivable records                 */
#define END_OF_STRING   '\0'    /* Null character                     */
#define MAX_CUSTOMERS   100     /* Maximum amount of customers        */
#define MIN_CUSTOMERS   2       /* Minimum amount of customers        */
#define MAX_NAME_LENGTH 20      /* Maximum customer name length       */
#define NEW_LINE        '\n'    /* New line character                 */
#define QUIT            0       /* Program exit value                 */

/**********************************************************************/
/*                       Structure Definitions                        */
/**********************************************************************/
/* The specification for a customer account                           */
struct customer
{
   char last_name[MAX_NAME_LENGTH + 1]; /* The customer's last name   */
   float amount_owed;                   /* Amount the customer owes   */
   int   customer_priority;             /* Priority of the customer   */
};

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Prints the program heading                                      */
void print_instructions();
   /* Prints the program instructions                                 */
int  get_account_quantity();
   /* Gets the quantity of customer accounts receivable records       */
void get_customer_data(struct customer *p_customer_start, int quantity);
   /* Get the customer account receivable records data                */
void clean_names(struct customer *p_customer_start, int quantity);
   /* Clean the customer names of all non-letters and title case      */
void sort_accounts(struct customer *p_customer_start, int quantity);
   /* Sort the accounts alphabetically by the customer's name         */
void print_customers(struct customer *p_customer_start, int quantity);
   /* Print the database of customer accounts receivable in table     */
   /* format                                                          */

/**********************************************************************/
/*                          Main Function                             */
/**********************************************************************/
int main()
{
   struct customer *p_customer; /* Points to every customer account   */
   int             quantity;    /* Amount of customer accounts to be  */
                                /* added to the database              */

   /* Print the program header                                        */
   print_heading();

   /* Loop processing database of customer accounts receivable data   */
   /* until the user says to quit                                     */
   while (print_instructions(), 
                            (quantity = get_account_quantity()) != QUIT)
   {
      /* Allocates memory for the database of customer accounts       */
      /* receivable data if memory is available and aborts if memory  */
      /* is not available                                             */
      if ((p_customer = 
      (struct customer *)malloc(sizeof(struct customer)*quantity)) == NULL)
      {
         printf("\nError %d occurred in main().", DB_ALLOC_ERR);
         printf("\nDatabase memory allocation error occurred");
         printf("\nThe program is aborting");
         printf("\n\n\n\n\n");
         exit  (DB_ALLOC_ERR);
      }
      else
      {
         /* Get names, clean names, sort accounts, and print the      */
         /* database of customer account receivable data              */
         get_customer_data (p_customer, quantity);
         clean_names       (p_customer, quantity);
         sort_accounts     (p_customer, quantity);
         print_customers   (p_customer, quantity);
      }

      /* Displays to the user that the database is done processing    */
      printf("\n\n******* End Of Customer Database Processing *******");

      /* Release memory allocated to the database of customer         */
      /* accounts receivable records                                  */
      free(p_customer);
   }

   /* Says goodbye and terminates the program                         */
   printf("\nThanks for processing account data. Have a nice day! ;-)");
   printf("\n\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                    Print the Program Heading                       */
/**********************************************************************/
void print_heading()
{
   printf(  "\n\n\n\n\n\n\n");
   printf(  "\n========================================================");
   printf(  "\n                Program Number: %d",    PROGRAM_NUMBER);
   printf(  "\n                Programmer: %s",        PROGRAMMER_NAME);
   printf(  "\n                PCC Course Number: %s", COURSE_NUMBER);
   printf(  "\n========================================================");
   return;
}

/**********************************************************************/
/*                Print the program instructions                      */
/**********************************************************************/
void print_instructions()
{
   printf("\n\nThis program allows you to input customers which owe");
   printf(  "\nyou money (your accounts receivable), and manage these");
   printf(  "\naccounts in a database.  You will enter the following:");
   printf(  "\n   Customer last name (1-%d characters)", MAX_NAME_LENGTH);
   printf(  "\n   Amount the customer owes (to the exact cent)");
   printf(  "\n   Customer priority (1=VIP, 2=Important, 3=Regular)");
   printf(  "\nFrom %d to %d customers may be processed.", MIN_CUSTOMERS,
             MAX_CUSTOMERS);
   return;
}

/**********************************************************************/
/*                     Get the data quantity                          */
/**********************************************************************/
int get_account_quantity()
{
   int account_quantity; /* Quantity of customer accounts           */
                         /* receivable records                      */
   do
   {
      printf("\n\nGet the customers for the database");
      printf(  "\n--------------------------------------------------");
      printf(  "\nHow many customers do you have (%d to %d, %d=quit): ",
                MIN_CUSTOMERS, MAX_CUSTOMERS, QUIT);
      scanf ("%d", &account_quantity);
   }
   while(((account_quantity < MIN_CUSTOMERS) ||
          (account_quantity > MAX_CUSTOMERS)) &&
          (account_quantity != QUIT));
   return  account_quantity;
}

/**********************************************************************/
/*                Get the customer account information                */
/**********************************************************************/
void get_customer_data(struct customer *p_customer_start, int quantity)
{
   struct customer *p_customer;  /* Points to each customer account   */
   char            *p_last_name; /* Points to each character in the   */
                                 /* customer's last name              */

   /* Loop receiving the customer account receivable data and goint   */
   /* through each customer's account                                 */
   for (p_customer = p_customer_start; (p_customer - p_customer_start) <
        quantity; p_customer++)
   {
      /* Prints the number of the customer's account                  */
      printf ("\nCustomer number %d", 
                             (int) (p_customer - p_customer_start + 1));

      /* Loop processing the customer's last name and converting it   */
      /* into a string                                                */
      printf ("\n   Enter the customer's last name: ");
      getchar();
      p_last_name = p_customer->last_name;
      do
      {
         *p_last_name++ = getchar();
      }
      while (*(p_last_name - 1) != NEW_LINE);
      *(p_last_name - 1) = END_OF_STRING;

      /* Gets the amount that the customer owes                       */
      printf ("   Enter the amount owed: ");
      scanf  ("%f", &p_customer->amount_owed);

      /* Gets the customer's priority                                 */
      do
      {
         printf ("   Enter the customer's priority (1-3): ");
         scanf  ("%d", &p_customer->customer_priority);
      }
      while((p_customer->customer_priority) < 1 ||
            (p_customer->customer_priority > 3));
   }
   return;
}

/**********************************************************************/
/*      Clean the customer names of non-letters and title case        */
/**********************************************************************/
void clean_names(struct customer *p_customer_start, int quantity)
{
   struct customer *p_customer; /* Points to every customer account   */
   char *p_fast,                /* Points to each character in a      */
                                /* customer's name                    */
        *p_slow;                /* Points to each alphabetical        */
                                /* character in a customer's name     */

   for (p_customer = p_customer_start; (p_customer - p_customer_start) <
        quantity; p_customer++)
   {
      p_fast = p_customer->last_name;
      p_slow = p_customer->last_name;
      while (*p_fast != END_OF_STRING)
      {
         if (isalpha(*p_fast))
            *p_slow++ = tolower(*p_fast);
         p_fast++;
      }
      *p_slow = END_OF_STRING;
      p_fast  = p_customer->last_name;
      *p_fast = toupper(*p_fast);
   }

   return;
}

/**********************************************************************/
/*    Clean the customer names of all non-letters including spaces    */
/**********************************************************************/
void sort_accounts(struct customer *p_customer_start, int quantity)
{
   struct customer *p_outer,      /* Points to a character in the     */
                                  /* customer's last name to compare  */
                   *p_inner,      /* Points to a character in a       */
                                  /* different last name to compare   */
                   temp_customer; /* Temporary variable for swapping  */
                                  /* accounts                         */

   for (p_outer = p_customer_start; (p_outer - p_customer_start) <
        quantity; p_outer++)
   {
      for (p_inner = (p_outer + 1); (p_inner - p_customer_start) <
         quantity; p_inner++)
      {
         if (strcmp(p_inner->last_name, p_outer->last_name) < 0)
         {
            temp_customer = *p_inner;
            *p_inner      = *p_outer;
            *p_outer      = temp_customer;
         }
      }
   }
   return;
}

/**********************************************************************/
/*               Prints the customer account information              */
/**********************************************************************/
void print_customers(struct customer *p_customer_start,
                     int quantity)
{
   struct customer *p_customer; /* Points to each customer's account  */

   printf("\n  Here is the accounts receivable customer database");
   printf("\n=====================================================");
   printf("\n   Customer Name         Amount        Priority");
   printf("\n--------------------    ---------    -------------");

   for (p_customer = p_customer_start; (p_customer - p_customer_start)
        < quantity; p_customer++)
   {
      printf("\n%20s    $%8.2f    %d",
              p_customer->last_name, p_customer->amount_owed,
              p_customer->customer_priority);
      switch(p_customer->customer_priority)
      {
         case 1:
            printf(" (VIP)");
            break;
         case 2:
            printf(" (Important)");
            break;
         case 3:
            printf(" (Regular)");
            break;
      }
   }
}