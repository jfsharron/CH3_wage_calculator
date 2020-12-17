//  ============================================================================
//  Program:                CH3_wage_calculator
//  File:                   CH3_wage_calculator_struct.c
//  Software Engineer:      Jonas Sharron
//  Date:                   25-September-2018
//  Purpose:                Program which determines gross pay (calculate both
//                          standard pay and overtime) with output sent to 
//                          screen and file.  Employee data is stored in an
//                          array(s).
//  ============================================================================

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)  // statement to surpress VS2017 scanf warnings

//  ============================================================================
//  constant declarations
//  ============================================================================

# define NUM_EMP 5
# define STD_HOURS 40.0f
# define OT_RATE 1.5f

struct DATE {
    int month;              //  1-12 format
    int day;                //  1-31 format
    int year;               //  4 digit format  
};

typedef struct DATE StartDate;

struct EMPLOYEE {
    long int clockNum;      //  employee number
    float wage;             //  employee wage
    float hours;            //  hours employee worked
    float ot;               //  ot hours employee worked
    float gross;            //  gross pay (standard + ot) for employee
    float bonus;            //  yearly bonus amount for employee
    StartDate;              //  employee start date
    int exempt;             //  exempt status (0 = nonexempt; 1 = exempt)
    float vacHours;         //  number of vacation hours available to employee
    int benefits;           //  employee qualify for benefits (0 = no; 1 = yes)
};

typedef struct EMPLOYEE Employee;

//  ============================================================================
//  fuction prototypes
//  ============================================================================

void banner();
void getHours(Employee data[], int size);
void getOt(Employee data[], int size);
void getGross(Employee data[], int size);
void printRep(Employee data[], int size);

//  ============================================================================

//  ============================================================================
int main() 
{
    //  create Employee data array and initialize values
    Employee data[NUM_EMP]=
    {
    { 98401, 10.6, 0, 0, 0, 1500,{ 07, 02, 1971 }, 1, 42.5, 1 },
    { 526488, 9.75, 0, 0, 0, 2500,{ 04, 01, 2001 }, 1, 16, 1 },
    { 765349, 10.5, 0, 0, 0, 3500,{ 01, 05, 2011 }, 0, 4, 0 },
    { 34645, 12.25, 0, 0, 0, 4500,{ 05, 04, 2017 }, 0, 0, 0 },
    { 127615, 8.35, 0, 0, 0, 5500,{ 03, 12, 1988 }, 1, 12.5, 1 }
    };

    //  display banner
    banner();

    //  collect hours
    getHours(data, NUM_EMP);

    //  calculate ot
    getOt(data, NUM_EMP);

    //  calculate gross
    getGross(data, NUM_EMP);

    //  print output to screen
    printRep(data, NUM_EMP);

    return(0);
}  //  end main

//  ============================================================================
//  Function:   banner
//  Purpose:    display program purpose to user
//  Parameters: none
//  Returns:    nothing (informational output only)
//  ============================================================================

void banner()
{
    printf("=============================================================\n");
    printf("This is a program to calculate gross pay.\n");
    printf("You will be prompted for employee data.\n");
    printf("=============================================================\n\n");
}  //  end banner
//  ============================================================================

//  ============================================================================
//  Function:   getHours
//  Purpose:    collect employee hours from user
//  Parameters: clockNum - array of clock numbers for employees
//              hours -    array of hoursworked per employee
//              size -     number of employees
//  Returns:    nothing (void function, values written to hours array)
//  ============================================================================

void getHours(Employee data[], int size)
{
    for (int ii = 0; ii < size; ++ii)
    {
        printf("Enter the number of hours employee %d worked: ", ii + 1);
        scanf("%f", &data[ii].hours);   
    }
    printf("\n\n");
}  //  end getHours
//  ============================================================================

//  ============================================================================
//  Function:   getOt
//  Purpose:    calculate overtime hours of employee
//  Parameters: hours -    array of hours worked per employee
//              ot -       array to hold calculated ot hours
//              size -     number of employees
//  Returns:    nothing (void function, values written to ot array)
//  ============================================================================

void getOt(Employee data[], int size)
{
    for (int ii = 0; ii < size; ++ii)
    {
        if (data[ii].hours > STD_HOURS)
        {
            data[ii].ot = (data[ii].hours - STD_HOURS);
        }
        else
        {
            data[ii].ot = 0.0;
        }
    }  
}  //  end getOt
//  ============================================================================

//  ============================================================================
//  Function:   getGross
//  Purpose:    calculate gross pay for employee
//  Parameters: wage -     array of employee wages
//              hours -    array of hours worked per employee
//              ot -       array of ot hours worked per employee
//              gross -    array to hold calculated gross pay
//              size -     number of employees
//  Returns:    nothing (void function, values written to gross array)
//  ============================================================================

void getGross(Employee data[], int size)
{
    for (int ii = 0; ii < size; ++ii)
    {
        if (data[ii].hours <= STD_HOURS)
        {
            data[ii].gross = (data[ii].wage * data[ii].hours);
        }
        else
        {
            data[ii].gross = (STD_HOURS * data[ii].wage) + (data[ii].ot * 
            (data[ii].wage * OT_RATE));
        }
    }
}  //  end getGross
//  ============================================================================

//  ============================================================================
//  Function:   printRep
//  Purpose:    print report to screen
//  Parameters: clockNum - array of clock numbers for employees
//              wage -     array of employee wages
//              hours -    array of hoursworked per employee
//              ot -       array of ot hours worked per employee
//              gross -    array ogf gross pay per employee
//              size -     number of employees
//  Returns:    nothing (void function, output printed to screen)
//  ============================================================================

void printRep(Employee data[], int size)
{
    //  local variables used to calculate summary (total and average) data
    //  ===================================================================
    float totWage = 0;		    //  total of wages
    float totHours = 0;         //  total of hours
    float totOt = 0;            //  total of ot
    float totGross = 0;         //  total of gross
    float totBonus = 0;			//  total of bonuses
    float totVac = 0;           //  total of vacation hours

    printf("\n\n");
    printf("============================================================");
    printf("============================================\n");
    printf("Clock#\tStart Date\tWage\tHours\tOT\tExempt\t Gross\t    Bonus");
    printf("\tVacation\tBenefits\n");
    printf("============================================================");
    printf("============================================\n");

    for (int ii = 0; ii < size; ++ii)
    {
        char exempt;
        char benefits;

        if (data[ii].exempt == 0)
        {
            exempt = 78;
        }
        else
        {
            exempt = 89;
        }

        if (data[ii].benefits == 0)
        {
            benefits = 78;
        }
        else
        {
            benefits = 89;
        }

        printf("%06i\t%02i/%02i/%04i\t%.2f\t%.1f\t%.1f\t  %c\t%.2f\t   %.2f\t%.1f\t\t  %c\n\n",
            data[ii].clockNum, data[ii].month, data[ii].day, data[ii].year,
            data[ii].wage, data[ii].hours, data[ii].ot, exempt,
            data[ii].gross, data[ii].bonus, data[ii].vacHours, benefits);

        totWage += data[ii].wage;
        totHours += data[ii].hours;
        totOt += data[ii].ot;
        totGross += data[ii].gross;
        totBonus += data[ii].bonus;
        totVac += data[ii].vacHours;
    }

    printf("======\t==========\t=====\t====\t====\t=====\t=======\t");
    printf("  ========\t=====\t\t ====\n\n");
    printf("Total\t\t\t%.2f\t%.1f\t%.1f\t\t%.2f\t  %.2f\t%.1f\n\n", totWage,
        totHours, totOt, totGross, totBonus, totVac);
    printf("Average\t\t\t%.2f\t%.1f\t%.1f\t\t%.2f\t  %.2f\t%.1f\n\n",
        (totWage / NUM_EMP), (totHours / NUM_EMP), (totOt / NUM_EMP),
        (totGross / NUM_EMP), (totBonus / NUM_EMP), (totVac / NUM_EMP));

}  //  end print
//  ===========================================================================