//  ============================================================================
//  Program:                CH3_wage_calculator
//  File:                   CH3_wage_calculator_functions.c
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
//  fuction prototypes
//  ============================================================================

void banner();
void getHours(long int clockNum[], float hours[], int size);
void getOt(float hours[], float ot[], int size);
void getGross(float wage[], float hours[], float ot[], float gross[], int size);
void print(long int clockNum[], float wage[], float hours[], float ot[], 
            float gross[], int size);

//  ============================================================================
//  constant declarations
//  ============================================================================

# define NUM_EMP 5
# define STD_HOURS 40
# define OT_RATE 1.5f


//  ============================================================================

//  ============================================================================
int main() 
{
    //  ========================================================================
    //  array and variable declarations
    //  ========================================================================

    // arrays for holding employee data
    long int clockNum[NUM_EMP] = { 98401, 526488, 76349, 34645, 127615 };
    float wage[NUM_EMP] = { 10.6, 9.75, 10.5, 12.25, 8.35 };
    float hours[NUM_EMP];
    float ot[NUM_EMP];
    float gross[NUM_EMP];

    //  display banner
    banner();

    //  collect hours
    getHours(clockNum, hours, NUM_EMP);

    //  calculate ot
    getOt(hours, ot, NUM_EMP);

    //  calculate gross
    getGross(wage, hours, ot, gross, NUM_EMP);

    //  print output to screen
    print(clockNum, wage, hours, ot, gross, NUM_EMP);

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

void getHours(long int clockNum[], float hours[], int size)
{
    for (int ii = 0; ii < size; ++ii)
    {
        printf("Enter the number of hours employee %d worked: ", ii + 1);
        scanf("%f", &hours[ii]);   
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

void getOt(float hours[], float ot[], int size)
{
    for (int ii = 0; ii < size; ++ii)
    {
        if (hours[ii] > STD_HOURS)
        {
            ot[ii] = (hours[ii] - STD_HOURS);
        }
        else
        {
            ot[ii] = 0.0;
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

void getGross(float wage[], float hours[], float ot[], float gross[], int size)
{
    for (int ii = 0; ii < size; ++ii)
    {
        if (hours[ii] <= STD_HOURS)
        {
            gross[ii] = (wage[ii] * hours[ii]);
        }
        else
        {
            gross[ii] = (STD_HOURS * wage[ii]) + (ot[ii] * (wage[ii] * OT_RATE));
        }
    }
}  //  end getGross
//  ============================================================================

//  ============================================================================
//  Function:   print
//  Purpose:    print report to screen
//  Parameters: clockNum - array of clock numbers for employees
//              wage -     array of employee wages
//              hours -    array of hoursworked per employee
//              ot -       array of ot hours worked per employee
//              gross -    array ogf gross pay per employee
//              size -     number of employees
//  Returns:    nothing (void function, output printed to screen)
//  ============================================================================

void print(long int clockNum[], float wage[], float hours[], float ot[], 
            float gross[], int size)
{
    //  totals used for calculating summary data (totals and averages)
    //  ========================================================================
    float totWage  = 0;
    float totHours = 0;
    float totOt    = 0;
    float totGross = 0;

    printf("\n\n");
    printf("======================================\n");
    printf("Clock#\tWage\tHours\tOT\tGross\n");
    printf("======================================\n");

    for (int ii = 0; ii < size; ++ii)
    {
        printf("%06i\t%.2f\t%.1f\t%.1f\t%.2f\n\n", clockNum[ii], wage[ii], 
                hours[ii], ot[ii], gross[ii]);
        
        totWage  += wage[ii];
        totHours += hours[ii];
        totOt    += ot[ii];
        totGross += gross[ii];
    }

    printf("======\t=====\t====\t====\t=====\n\n");
    printf("Total\t%.2f\t%.1f\t%.1f\t%.2f\n\n", totWage, totHours, totOt, 
            totGross);
    printf("Average\t%.2f\t%.1f\t%.1f\t%.2f\n\n", (totWage/NUM_EMP),
            (totHours/NUM_EMP), (totOt/NUM_EMP), (totGross/NUM_EMP));
 }  // end print
 //  ===========================================================================