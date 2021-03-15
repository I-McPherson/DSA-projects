/**********************************************************************/
/*                                                                    */
/* Program Name: program6 - Demonstrate various search algorithms     */
/* Author:       Ian McPherson                                        */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: November 15, 2019                                    */
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
/* This program will create a linked list with user provided student  */
/* id numbers, and will perform several processes, including:         */
/*    -Insert a student id node                                       */
/*    -Print the student id list                                      */
/*    -Sort the student id list into ascending order                  */
/*    -Delete duplicate student ids from the list                     */
/* Then it will print a goodbye message and terminate the program.    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */
#include <stdlib.h> /* malloc, free, exit                             */
#include <ctype.h>  /* tolower                                        */

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define COURSE_NUMBER     "CS227" /* PCC assigned course number       */
#define HEADER_ALLOC_ERR  1       /* Header memory allocation error   */
#define ID_ALLOC_ERR      3       /* Memory allocation error for each */
                                  /* linked list node                 */
#define LIST_HEADER       0       /* Value of the linked list header  */
#define LIST_TRAILER      1000000 /* Value of the linked list trailer */
#define MAXIMUM_ID        999999  /* Maximum student ID number        */
#define MINIMUM_ID        1       /* Minimum student ID number        */
#define PROGRAM_NUMBER    6       /* Teacher assigned program number  */
#define PROGRAMMER_NAME   "McPherson"
                                  /* The programmer's last name       */ 
#define QUIT              0       /* Program exit value               */
#define TRAILER_ALLOC_ERR 2       /* Trailer memory allocation error  */

/**********************************************************************/
/*                        Program Structures                          */
/**********************************************************************/
/* The specification for a student ID node                            */
struct student_id
{
   int    id_number;             /* Value of a node's student id      */
   struct student_id *p_next_id; /* Points to the next student id node*/
};
typedef struct student_id ID_NODE;

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void    print_heading();
   /* Prints the program heading                                      */
void    print_instructions();
   /* Prints the program instructions                                 */
char    get_response();
   /* Gets the response to continue or quit                           */
ID_NODE *create_list();
   /* Creates an empty linked list with header and trailer nodes      */
void    insert_node(ID_NODE *p_id_numbers, int id_number);
   /* Inserts a student id at the beginning of the list               */
void    print_id_list(ID_NODE *p_id_numbers);
   /* Prints the student id list                                      */
int     get_student_amount(ID_NODE *p_id_numbers);
   /* Counts the amount of students on the list                       */
void    sort_student_ids(ID_NODE *p_id_numbers);
   /* Sorts the student id list into ascending order                  */
void    remove_duplicates(ID_NODE *p_id_numbers);
   /* Deletes all duplicate ids                                       */

/**********************************************************************/
/*                          Main Function                             */
/**********************************************************************/
int main()
{
   ID_NODE *p_id_numbers, /* Points to the ordered linked list           */
        *p_id;            /* Points to a node in the ordered linked list */
   int  student_id;       /* Student ID                                  */


   /* Print the program header                                        */
   print_heading();

   /* Loop proccessing a linked list until the user says to quit      */
   while (print_instructions(), get_response() == 'y')
   {
      /* Create a new empty linked list with header and trailer nodes */
      p_id_numbers = create_list();

      while (printf("Enter the next student id (%d to quit): ", QUIT),
         scanf("%d", &student_id), student_id > LIST_HEADER)
         if (student_id > MAXIMUM_ID)
            printf("    Id rejected - it cannot exceed %d", MAXIMUM_ID);
         else
            insert_node(p_id_numbers, student_id);
      
      /* Print the student id list                                    */
      printf("\nThe unsorted student id list, as entered, is:");
      if (get_student_amount(p_id_numbers) > LIST_HEADER)
         print_id_list(p_id_numbers);
      else
         printf("\n    The student id list is empty.");
      printf("\nThe length of the unsorted student id list is: %d", 
         get_student_amount(p_id_numbers));

      /* Sort and print the student id list                           */
      sort_student_ids(p_id_numbers);
      printf("\n\nThe student id list, sorted ascending by id, is:");
      if (get_student_amount(p_id_numbers) > LIST_HEADER)
         print_id_list(p_id_numbers);
      else
         printf("\n    The student id list is empty.");
      printf("\nThe length of the sorted student id list is: %d",
         get_student_amount(p_id_numbers));

      /* Remove duplicate id numbers and print the student id list    */
      /*printf("\n\nThe student id list, with duplicate id's removed,");
      printf(" sorted ascending by id, is:");*/
      if (get_student_amount(p_id_numbers) > LIST_HEADER)
      {
         printf("\n");
         remove_duplicates(p_id_numbers);
      }
      else
         printf("\n    The student id list is empty.");
      printf("\nThe student id list, with duplicate id's removed,");
      printf(" sorted ascending by id, is:");
      print_id_list(p_id_numbers);
      printf("\nThe length of the cleaned and sorted student id list is: %d", 
                                       get_student_amount(p_id_numbers));

      /* Free the student id list's memory                            */
      while (p_id_numbers != NULL)
      {
         p_id = p_id_numbers;
         p_id_numbers = p_id_numbers->p_next_id;
         free(p_id);
      }
   }

   /* Print a goodbye message and terminate the program               */
   printf("\nThanks for using this program.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");

   return 0;
}

/**********************************************************************/
/*                    Print the program heading                       */
/**********************************************************************/
void print_heading()
{
   printf("\n\n\n\n\n\n");
   printf("\n========================================================");
   printf("\n                Program Number: %d",    PROGRAM_NUMBER);
   printf("\n                Programmer: %s",        PROGRAMMER_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   return;
}

/**********************************************************************/
/*                Print the program instructions                      */
/**********************************************************************/
void print_instructions()
{
   printf("\n\n");
   printf("\n    This program maintains a list of students by their");
   printf("\n    id number.  After entry of all id's, it sorts them");
   printf("\n    into ascending order, then removes all duplicates.");
   return;
}

/**********************************************************************/
/*                Get the response to continue or quit                */
/**********************************************************************/
char get_response()
{
   char response[2]; /* Stores the menu option entered by the user    */

   do
   {
      printf("\n\nDo you want to enter another student id list (y or n): ");
      scanf("%1s", &response[0]);
      response[0] = tolower(response[0]);
   } 
   while ((response[0] != 'y') && (response[0] != 'n'));
   return response[0];
}

/**********************************************************************/
/*    Create an empty student id list with header and trailer nodes   */
/**********************************************************************/
ID_NODE *create_list()
{
   ID_NODE *p_new_list; /* Points to the newly created list              */

   if ((p_new_list = (ID_NODE *) malloc (sizeof(ID_NODE))) == NULL)
   {
      printf("\nError #%d occurred in create_list.", HEADER_ALLOC_ERR);
      printf("\nCannot allocate memory for the list header.");
      printf("\nThe program is aborting.");
      exit  (HEADER_ALLOC_ERR);
   }
   p_new_list->id_number = LIST_HEADER;

   if ((p_new_list->p_next_id = 
                          (ID_NODE *) malloc (sizeof(ID_NODE))) == NULL)
   {
      printf("\nError #%d occurred in create_list.", TRAILER_ALLOC_ERR);
      printf("\nCannot allocate memory for the list trailer.");
      printf("\nThe program is aborting.");
      exit  (TRAILER_ALLOC_ERR);
   }
   p_new_list->p_next_id->id_number = LIST_TRAILER;
   p_new_list->p_next_id->p_next_id = NULL;
   return p_new_list;
}

/**********************************************************************/
/*             Insert a new student node into the list                */
/**********************************************************************/
void insert_node(ID_NODE *p_id_numbers, int id_number)
{
   ID_NODE *p_new_student; /* Points to a newly created id node          */

   if ((p_new_student = (ID_NODE *) malloc (sizeof(ID_NODE))) == NULL)
   {
      printf("\nError #%d occurred in insert_node.", ID_ALLOC_ERR);
      printf("\nCannot allocate memory for a new list node.");
      printf("\nThe program is aborting.");
      exit  (ID_ALLOC_ERR);
   }
   p_new_student->id_number = id_number;
   p_new_student->p_next_id = p_id_numbers->p_next_id;
   p_id_numbers->p_next_id  = p_new_student;
   return;
}

/**********************************************************************/
/*                     Print the student id list                      */
/**********************************************************************/
void print_id_list(ID_NODE *p_id_numbers)
{
   while (p_id_numbers = p_id_numbers->p_next_id, 
          p_id_numbers->id_number < LIST_TRAILER)
      printf("\n%25d", p_id_numbers->id_number);
   return;
}

/**********************************************************************/
/*                   Count the amount of students                     */
/**********************************************************************/
int get_student_amount(ID_NODE *p_id_numbers)
{
   int student_sum = 0; /* Sum of the student ids in the list         */

   while (p_id_numbers = p_id_numbers->p_next_id, 
          p_id_numbers->id_number < LIST_TRAILER)
      student_sum++;
   return student_sum;
}

/**********************************************************************/
/*                    Sort the student id numbers                     */
/**********************************************************************/
void sort_student_ids(ID_NODE *p_id_numbers)
{
   int  student_id_count; /* Amount of IDs in the list                */
   ID_NODE *p_traverse,   /* Points to each student ID                */
           *p_temp_sort;  /* Points to a temporary student id         */

   for (student_id_count = 0; student_id_count < 
             (get_student_amount(p_id_numbers) - 1); student_id_count++)
   {
      p_traverse = p_id_numbers;
      while (p_traverse->p_next_id->p_next_id->id_number != LIST_TRAILER)
      {
         if (p_traverse->p_next_id->id_number > 
             p_traverse->p_next_id->p_next_id->id_number)
         {
            p_temp_sort                      = p_traverse->p_next_id->p_next_id;
            p_traverse->p_next_id->p_next_id = p_temp_sort->p_next_id;
            p_temp_sort->p_next_id           = p_traverse->p_next_id;
            p_traverse->p_next_id            = p_temp_sort;
         }
         p_traverse = p_traverse->p_next_id;
      }
   }
   return;
}

/**********************************************************************/
/*        Remove duplicate IDs from the list of student IDs           */
/**********************************************************************/
void remove_duplicates(ID_NODE *p_id_numbers)
{
   ID_NODE *p_current  = p_id_numbers->p_next_id->p_next_id, 
                                       /* Points to the current node  */
           *p_previous = p_id_numbers->p_next_id;            
                                       /* Points to the previous      */
                                       /* node                        */

   while (p_current->id_number != LIST_TRAILER)
   {
      if (p_previous->id_number == p_current->id_number)
      {
         printf("\nDeleting the duplicate student id: %d", 
            p_current->id_number);
         p_previous->p_next_id = p_current->p_next_id;
         free(p_current);
         p_current = p_previous->p_next_id;
      }
      else
      {
         p_previous = p_current;
         p_current  = p_current->p_next_id;
      }
   }
   return;
}
