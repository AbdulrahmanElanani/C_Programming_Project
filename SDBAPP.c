#include "STB.h"
/*it has a super loop it will make
your project until the user chose to exit you
will ask the user to choose between these
options*/
void SDB_APP()
{
    unit8 choice;
    label1:
    printf("===============================================\n");
    printf("To add entry, enter                       \"1\"\n");
    printf("To get used size in database, enter       \"2\"\n");
    printf("To read student data, enter               \"3\"\n");
    printf("To get the list of all student IDs, enter \"4\"\n");
    printf("To check is ID is existed, enter          \"5\"\n");
    printf("To delete student data, enter             \"6\"\n");
    printf("To check is database is full, enter       \"7\"\n");
    printf("To exit enter                             \"0\"\n");
    printf("===============================================\n");
    printf("Enter Choice: ");
    scanf("%d",&choice);
        SDB_action(choice);
        if (choice==0)
        {
            return 0;
        }
        goto label1;


}
/*it well takes the user choice
and call the responding function for this
choice.You make the right response to give a valid
Output for the user*/
void SDB_action(unit8 choice)
{
        unit32 id,i;
        unit8 num=10;
        unit32 list[num];
    switch (choice)
    {
    case 1:

        SDB_AddEntry();
        break;
    case 2:
        printf("size = %d\n\n\n",SDB_GetUsedSize());
        break;
    case 3:
        printf("Enter ID: ");
        scanf("%d",&id);
        SDB_ReadEntry(id);
        break;
    case 4:
        printf("Enter number of ids:");
        scanf("%d",&num);

        printf("Enter ids:\n");
        for( i=0;i<num;i++)
        {
            scanf("%d",&list[i]);

        }
        SDB_GitList(&num,&list);
        break;
    case 5:
        printf("Enter ID :");
        scanf("%d",&id);
        if(!SDB_IsIdExist(id))
        {
            printf("Id is not exist!\n\n\n");
        }
        else
            printf("Id is exist!\n\n\n");
        break;
    case 6:
        printf("Enter ID:");
        scanf("%d",&id);
        SDB_DeletEntry(id);
        break;
    case 7:
        if(SDB_IsFull())
        {
            printf("Is full!\n\n\n");
        }
        else
        {
            printf("Is not full!\n\n\n");
        }
        break;
    default:
        printf("End!\n");
    }
}
