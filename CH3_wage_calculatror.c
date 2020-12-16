//  ============================================================================
//  Program:                CH3_wage_calculator
//  File:                   CH3_wage_calculator.c
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
# difine STD_HOURS 40

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
    //  variables for calculating summary data
    float totWage =  0;         //  total of wages
    float totHours = 0;         //  total of hours
    float totOt =    0;         //  total of ot
    float totGross = 0;         //  total of gross

    //  ========================================================================
    //  program banner
    //  ========================================================================

    printf("=============================================================\n");
    printf("This is a program to calculate gross pay.\n");
    printf("You will be prompted for employee data.\n");
    printf("=============================================================\n\n");
    
    //  end banner
    //  ========================================================================

    //  ========================================================================
   
    //  collect data
    for (int ii = 0; ii < NUM_EMP; ii++)  //  collect data loop
    {
        float inputHours =  0.0;     //  number of hours worked (input variable)
        float otHours =     0.0;    //  number of overtime hours per week
        int   otTrue =      0;      //  flag if ot hours exist

        //  gather input (hours worksed)
        printf("Enter the number of hours employee %d worked: ", ii + 1);
        scanf("%f", &inputHours);

        //  send input to array
        hours[ii] = inputHours;

        //  check for ot
        if (inputHours > STD_HOURS)
        {
            otTrue = 1;
            otHours = (inputHours - STD_HOURS);
            ot[ii] = otHours;
        }
        else
        {
            ot[ii] = 0.0;
        }
        
        //  calculate gross
        if (otTrue ==1)
        {
            gross[ii] = (wage[ii] * STD_HOURS)) + 
                        (1.5 * (wage[ii] * otHours));
        }
        else
        {
            gross[ii] = (wage[ii] * inputHours);
        }

        totWage  += wage[ii]
        totHours += hours[ii]
        totOt    += ot[ii]
        totGross += gross[ii]

        }  // end collect data loop
        
        //  print output
        printf("\n\n");
        printf("=========================================================\n");
        printf("Clock#\tWage\tHours\tOT\tGross\n");
        printf("=========================================================\n");

        for (int ii = 0; ii < NUM_EMP; ii++)  // print output loop
        {
            printf("%06i\t%.2f\t%.1f\t%.1f\t%.2f\n\n", clockNum[ii], wage[ii],
                    hours[ii], ot[ii, gross[ii]]);

        }  //  end print output loop

        //  print summary data
        printf("======\t=====\t====\t====\t=====\n\n");
        printf("Total\t%.2f\t%.1f\t%.1f\t%.2f\n\n", totWage, totHours, totOt,
                totGross);
        printf("Average\t%.2f\t%.1f\t%.1f\t%.2f\n\n", (totWage/NUM_EMP), 
                (totHours/NUM_EMP), (totOt/NUM_EMP), totGross/NUM_EMP);")
} // end main

