#include "STB.h"
student s[10];
unit8 numberOfStudent=0;
//check if the database is full or not.
bool SDB_IsFull()
{
    if(SDB_GetUsedSize()==10)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//get how many students in your database have added
unit8 SDB_GetUsedSize()
{
    return numberOfStudent;
}
/*When the user chooses to
add entry this function asks him for the
required data in the database to add one
student which is his (id, year, Course1_ID,
Course1_grade, Course2_ID,
Course2_grade, Course3_ID, and
Course3_grade) and then add to your
database.*/
bool SDB_AddEntry()
{
    if(!SDB_IsFull())
    {
label1:
        printf("Enter Student Id :    ");
        scanf("%d",&s[numberOfStudent].Student_ID);
        if(SDB_IsIdExist(s[numberOfStudent].Student_ID))
        {
            printf("Enter Student Year:   ");
            scanf("%d",&s[numberOfStudent].Student_year);
            printf("Enter Course1_ID:     ");
            scanf("%d",&s[numberOfStudent].Course1_ID);
            printf("Enter Course1_grade:  ");
            scanf("%d",&s[numberOfStudent].Course1_grade);
            printf("Enter Course2_ID:     ");
            scanf("%d",&s[numberOfStudent].Course2_ID);
            printf("Enter Course2_grade:  ");
            scanf("%d",&s[numberOfStudent].Course2_grade);
            printf("Enter Course3_ID:     ");
            scanf("%d",&s[numberOfStudent].Course3_ID);
            printf("Enter Course3_grade:  ");
            scanf("%d",&s[numberOfStudent].Course3_grade);
            numberOfStudent++;
            printf("Data add successfully!\n\n\n");
            return true;
        }
        else
        {
            printf("Try Again\n");
            goto label1;
        }
    }
    else
        printf("Data is full\n");
    return false;
}
//delete the student data with the given id.
void SDB_DeletEntry(unit32 id)
{
    unit32 flag =0,index;
    student temp;
    if (numberOfStudent>3 && !SDB_IsIdExist(id))
    {
        for(unit32 i=0; i<numberOfStudent; i++)
        {
            if(s[i].Student_ID==id)
            {
                index=i;
                for (unit32 j=index; j<numberOfStudent-1; j++)
                {
                    temp =s[index];
                    s[index]=s[j+1];
                    s[j+1]=temp;
                    index++;
                }
                numberOfStudent--;
            }
        }
        printf("Delete successfully!\n");
    }
    else if( SDB_IsIdExist(id))
    {
        printf("This Id not found! \n");

    }
    else
    {
        printf("You Can Not Delete! \n");
    }

}
//print the data of the user by searching on his data by the given id
bool SDB_ReadEntry(unit32 id)
{
    unit32 flag=0,index;
    for(unit32 j=0; j<numberOfStudent; j++)
    {
        if(s[j].Student_ID==id)
        {
            flag++;
            index=j;
        }
    }
    if(flag)
    {
        printf("Student Id :             %d\n",s[index].Student_ID);
        printf("Student Year :           %d\n",s[index].Student_year);
        printf("Student Cource1_ID :     %d\n",s[index].Course1_ID);
        printf("Student Cource1_grade :  %d\n",s[index].Course1_grade);
        printf("Student Cource2_ID :     %d\n",s[index].Course2_ID);
        printf("Student Cource2_grade :  %d\n",s[index].Course2_grade);
        printf("Student Cource3_ID :     %d\n",s[index].Course3_ID);
        printf("Student Cource3_grade :  %d\n\n\n",s[index].Course3_grade);

        return true;
    }
    else
    {
        printf("this Id Not Found !\n\n\n");
        return false;
    }
}

/*it gets the number of ids in the
count and the list of all ids in list array that’s
you get his base address.*/
void SDB_GitList(unit8 *count,unit32 *list)
{
    for (unit32 i=0; i<*count; i++)
    {
        if(!SDB_IsIdExist(list[i]))
        {
            SDB_ReadEntry(list[i]);
        }
        else
        {
            printf("This Id Not Found!\n");
        }
    }
}
//Checks if the given id the is Exist
bool SDB_IsIdExist(unit32 id)
{
    unit32 flag=0;
    for(unit32 j=0; j<numberOfStudent; j++)
    {
        if(s[j].Student_ID==id)
        {
            flag++;
        }
    }
    if(flag)
        return false;
    else
        return true;
}
