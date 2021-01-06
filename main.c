#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define null -32

struct employee
{
    char name[30];
    int id;
    int salary;
};

struct Node
{
    struct employee emp;
    struct Node *next;
    struct Node *prev;
};
struct Node *pfirst=NULL;
struct Node *plast=NULL;
struct Node *pcurrent=NULL;

 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

 void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}

struct Node *create (struct employee  e)
{
   struct Node* New=(struct Node *)malloc(1*sizeof(struct Node));
    New->emp=e;

    New->next=New->prev=NULL;
	return new;
}

void Add (struct Node *PNEW)
{
    if(pfirst==NULL)
    {
        pfirst=plast=PNEW;
    }
    else
    {
        plast->next=PNEW;
        PNEW->prev=plast;
        plast=PNEW;
    }
}


void insertNodeInsideList(struct Node *Pnew ,struct Node * temp)
{

   if(temp==plast)
   {
       Add(Pnew);
   }
   else
   {

	temp->next->prev=Pnew;
	Pnew->next=temp->next;
	Pnew->prev=temp;
	temp->next=Pnew;



	}


}


struct Node *Search_forpointer(int item)
{
    struct Node *temp=pfirst;
    while(temp!=NULL)
    {
        if(temp->emp.id==item)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;



   }

void Delete(struct Node*pdelete)
{
    if(plast== pfirst)
    {
        if(pfirst==plast)
        {
            pfirst=plast=NULL;
        }
        else
        {
            pfirst=pfirst->next;
            pfirst->prev=NULL;
        }
    }
    else if(pdelete==plast)
    {
        plast=plast->prev;
        plast->next=NULL;
    }
    else
    {
        pdelete->prev->next=pdelete->next;
        pdelete->next->prev=pdelete->prev;
    }
    free(pdelete);
}
int main()
{
    char a;
    struct employee emp;

    int postion;
    int search_result;
struct    Node *ptr;
struct    Node *insert;
    int id;
int c=1;
char f;
int k=0;

    char arr[5][10]={"new","insert","search","delete","display"};
    int i,j,row;
     printf("\t\t\main menu\n");
   printf("\t\t\------------");

   while(c>0)
   {


   for(i=0;i<5;i++)
   {
      gotoxy(20,i+5);
      textattr( 15);
      printf("%s\n",arr[i]);
   }
        gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);

  char d;
   d=getch();
if(d==27)break;
if(d==9)
{
    gotoxy(20,k+5);
      textattr( 15);
      printf("%s\n",arr[k]);
           if(k==2)
            {
            k=0;
            gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
            }
           else
           {
               k=k+1;
               gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
           }
}
   if(d == -32)
   {
       d=getch();
       if(d==80)
       {
           gotoxy(20,k+5);
      textattr( 15);
      printf("%s\n",arr[k]);
           if(k==4)
            {
            k=0;
            gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
            }
           else
           {
               k=k+1;
               gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
           }
       }
       else if (d==72)
       {
           gotoxy(20,k+5);
      textattr( 15);
      printf("%s\n",arr[k]);
         if(k==0)
         {
             k=4;
             gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
         }
         else{
                k=k-1;
                gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
         }


       }
       else if (d==27)
       {

    break;
       }


}
      else if ( d==13)
{
    if (k==0)
    {
          system("cls");
             textattr( 15);
             printf("enter the name\n");
             scanf("%s",emp.name);
            printf("enter the id\n");
            scanf("%d",&emp.id);
            printf("enter the salary\n");
            scanf("%d",&emp.salary);
          ptr=  create (emp);
            Add(ptr);

       getch();
            system("cls");
             textattr( 15);
         printf("\t\t\main menu\n");
   printf("\t\t\------------");


    }
    else if(k==1)
    {
         system("cls");
          textattr( 15);
           printf("enter the name\n");
             scanf("%s",emp.name);
            printf("enter the id\n");
            scanf("%d",&emp.id);
            printf("enter the salary\n");
            scanf("%d",&emp.salary);
            printf("enter the id to insert after\n");
            scanf("%d",&id);
            ptr=create (emp);
            insert=Search_forpointer(id);
            if(insert==NULL)
            {
                printf("error");
            }
            else
            {

            insertNodeInsideList(ptr ,insert);


            }

      getch();
           system("cls");
            textattr( 15);
                printf("\t\t\main menu\n");
   printf("\t\t\------------");


    }
     if (k==2)
    {
            system("cls");
          textattr( 15);
    printf("enter the id search\n");
            scanf("%d",&id);


             getch();
           system("cls");
            textattr( 15);
                printf("\t\t\main menu\n");
   printf("\t\t\------------");
    }
     if (k==3)

    {
              system("cls");
          textattr( 15);
         printf("enter the id to delete \n");
            scanf("%d",&id);
        ptr=Search_forpointer(id);
        Delete(ptr);
                  getch();
           system("cls");
            textattr( 15);
                printf("\t\t\main menu\n");
   printf("\t\t\------------");

   }
   else if(k==4)
{
     system("cls");
          textattr( 15);

             struct Node*pdisplay=pfirst;
             while(pdisplay!=NULL)
             {
                 printf("%s\n",pdisplay->emp.name);
                  printf("%d\n",pdisplay->emp.id);
                   printf("%d\n",pdisplay->emp.salary);
                   a=getch();
                   switch(a)
                   {
                   case -32:
                    {
                        a=getch();
                        if(a==75)
                        {
                          pdisplay=pdisplay->prev;
                        }
                        if(a==77)
                        {
                            pdisplay=pdisplay->next;
                        }

                    }
                    break;
                   }


             }
               getch();
           system("cls");
            textattr( 15);
                printf("\t\t\main menu\n");
   printf("\t\t\------------");

}


}

    }
    return 0;
   }




