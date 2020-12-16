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









    
}

