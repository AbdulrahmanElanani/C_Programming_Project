#ifndef _STB_H
#define _STB_H
#include "STD.h"
bool SDB_IsFull();
unit8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeletEntry(unit32 id);
bool SDB_ReadEntry(unit32 id);
void SDB_GitList(unit8 *count,unit32 *list);
bool SDB_IsIdExist(unit32 id);
void SDB_APP();
void SDB_action(unit8 choice);

typedef struct SimpleDb
{
    unit32 Student_ID;
    unit32 Student_year;
    unit32 Course1_ID;
    unit32 Course1_grade;
    unit32 Course2_ID;
    unit32 Course2_grade;
    unit32 Course3_ID;
    unit32 Course3_grade;
}student;
#endif // _STB_H
