#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  int st_id;
  char st_name[20];
  int earned_credites;
  struct node *next;
} advisee_node;

advisee_node *fill_advisee(void)
{
  char c;
  advisee_node *advisee;
  advisee = (advisee_node *)malloc(sizeof(advisee_node));
  printf("\nPlease, enter the information of the student you want to add");
  printf("\nStudent ID: ");
  scanf("%d", &advisee->st_id);
  scanf("%c", &c);
  printf("\nStudent Name: ");
  gets(advisee->st_name);
  printf("\nEarned credits for the student: ");
  scanf("%d", &advisee->earned_credites);
  advisee->next = NULL;
  return advisee;
}
int search(advisee_node **head, int id)
{
  advisee_node *walker;
  if (*head == NULL)
    return 0;
  else if (id == (*head)->st_id)
  {
    return 1;
  }
  else
  {
    walker = *head;
    while (walker != NULL)
    {
      if (id == walker->st_id)
      {
        return 1;
      }
      walker = walker->next;
    }
  }
}
void add_new_advisee(advisee_node *advisee, advisee_node **head, advisee_node **tail)
{
  if (*head == NULL)
  {
    *head = (advisee_node *)malloc(sizeof(advisee_node));
    *head = advisee;
    *tail = *head;
  }
  else
  {
    (*tail)->next = advisee;
    *tail = advisee;
  }
}

void change_major(int id, advisee_node **head, advisee_node **tail, advisee_node **he, int *status)
{
  *status = 0;
  advisee_node *walker, *temp;
  if (*head == NULL)
    printf("\nThe list is empty\n");
  else if (id == (*head)->st_id)
  {
    temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    if (*he != NULL)
    {
      (*tail)->next = temp;
      *tail = temp;
      *status = 1;
    }
    else
    {
      *he = temp;
      *tail = temp;
      *status = 1;
    }
  }

  else
  {
    walker = *head;
    while (walker->next != NULL)
    {
      if (id == walker->next->st_id)
      {
        temp = walker->next;
        walker->next = temp->next;
        temp->next = NULL;
        (*tail)->next = temp;
        *tail = temp;
        *status = 1;
        break;
      }
      walker = walker->next;
    }
  }
}

void delete_student(int id, advisee_node **head, advisee_node **tail, int *status)
{
  *status = 0;
  advisee_node *walker, *temp;
  if (*head == NULL)
    printf("\nThe list is empty\n");
  else if (id == (*head)->st_id)
  {
    temp = *head;
    *head = (*head)->next;
    free(temp);
    *status = 1;
  }
  else
  {
    walker = *head;
    while (walker->next != NULL)
    {
      if (id == walker->next->st_id)
      {
        temp = walker->next;
        walker->next = temp->next;
        if (walker->next == NULL)
          *tail = walker;
        free(temp);
        *status = 1;
        break;
      }
      walker = walker->next;
    }
  }
}
void merge_ll(advisee_node **og, advisee_node *head, advisee_node **put, advisee_node **stick, char name[25])
{
  if (*og == NULL)
  {
    *og = head;
    *stick = *put;
  }
  else
  {
    (*stick)->next = head;
    *stick = *put;
  }
}

void Print_advisees_for_advisor(advisee_node *head)
{
  advisee_node *walker;

  if (head == NULL)
    printf("\n The LL is empty");
  else
  {
    walker = head;
    while (walker != NULL)
    {
      printf("\nstudent ID: %d\nStudent name: %s\nEarned credits: %d\n-------", walker->st_id, walker->st_name, walker->earned_credites);
      walker = walker->next;
    }
  }
}

void quit(advisee_node *head, FILE *outfp)
{
  advisee_node *walker;
  if (head == NULL)
  {
    fprintf(outfp, "The LL is empty");
  }
  else
  {
    walker = head;
    while (walker != NULL)
    {
      fprintf(outfp, "student ID: %d\nStudent name:%s\nEarned credits: %d\n-------", walker->st_id, walker->st_name, walker->earned_credites);
      walker = walker->next;
    }
  }
}

int menu()
{
  int choice = 0;
  printf("\n\t\t\t\t\t\t\t\t***-----welcome-----***\n\t\t\t\t1-Add New Advisee\n\t\t\t\t2-Advisee changes major hence advisor\n\t\t\t\t3-Advisee changes school hence leave LL\n\t\t\t\t4-Merge LLs\n\t\t\t\t5-Print advisees for an advisor\n\t\t\t\t6-Quit\n\t\t\t\tPlease enter your Choice--> ");
  scanf("%d", &choice);
  return choice;
}

int main(void)
{
  int choice, id, status, inlist1, inlist2;
  char ch, answer;
  char advisor[25];
  advisee_node *advisee, *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;
  FILE *outfp1, *outfp2;
  do
  {
    choice = menu();
    switch (choice)
    {
    case 1:
      advisee = fill_advisee();
      printf("\nIs the student a computing student or not (Y/N)");
      scanf(" %c", &answer);
      if (answer == 'Y')
        add_new_advisee(advisee, &head1, &tail1);
      else if (answer == 'N')
        add_new_advisee(advisee, &head2, &tail2);
      else
        printf("\nplease, enter the right input");
      break;
    case 2:
      printf("\n please,enter the ID of student who changed majors: ");
      scanf("%d", &id);
      inlist1 = search(&head1, id);
      inlist2 = search(&head2, id);

      if (inlist1 == 1)
        change_major(id, &head1, &tail2, &head2, &status);
      else if (inlist2 == 1)
        change_major(id, &head2, &tail1, &head1, &status);
      if (status == 1)
        printf("\nThe student with ID: %d is succesfully removed from the list", id);
      else
        printf("\nCould not remove the student,%d is not in the list", id);

      break;
    case 3:
      printf("\n please,enter the ID of student who changed school: ");
      scanf("%d", &id);
      inlist1 = search(&head1, id);
      inlist2 = search(&head2, id);
      if (inlist1 == 1)
        delete_student(id, &head1, &tail1, &status);
      else if (inlist2 == 1)
        delete_student(id, &head2, &tail2, &status);
      if (status == 1)
        printf("\nThe student with ID: %d is succesfully removed from the list", id);
      else
        printf("\nCould not remove the student,%d is not in the list", id);

      break;
    case 4:
      printf("Which advisor is not available?");
      scanf("%s", advisor);
      if (strcmp(advisor, "Mrs.VanLierde") == 0)
      {
        merge_ll(&head1, head2, &tail2, &tail1, advisor);
        printf("The lists have been merged");
      }
      else if (strcmp(advisor, "Mrs.Talei") == 0)
      {
        merge_ll(&head2, head1, &tail1, &tail2, advisor);
        printf("The lists have been merged");
      }
      else
      {
        printf("Enter a valid advisor name.");
      }
      break;
    case 5:
      printf("\nWhich advisor you want to see his or her advisees--> ");
      getchar();
      gets(advisor);
      if (strcmp(advisor, "Mrs.Talei") == 0)
      {
        printf("\nThe advisees for Mrs.Talei are:");
        Print_advisees_for_advisor(head1);
      }
      else if (strcmp(advisor, "Mrs.VanLierde") == 0)
      {
        printf("\nThe advisees for Mrs.VanLierde are:");
        Print_advisees_for_advisor(head2);
      }
      else
        printf("\nWrong input, There is no advisor with such name");
      break;
    case 6:
      outfp1 = fopen("Talei_advisees.txt", "w");
      outfp2 = fopen("VanLierde_advisees.txt", "w");
      quit(head1, outfp1);
      quit(head2, outfp2);
      fclose(outfp1);
      fclose(outfp2);
      break;
    }
    if (choice != 6)
    {
      printf("\nDo you want to execute another function...(Y/N)");
      scanf(" %c", &ch);
    }
    else
      ch = 'N';

  } while (ch != 'N');

  return 0;
}
