/* 
 * File:   myShell.c
 * Created on August 26, 2015, 9:26 PM
 * Authors: Joshua			
 *		    Sam
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

/*
 * 
 */
int main(int argc, char *argv[]) {

	while(argc != 2)
	{
		fprintf(stdout, "USAGE: ./myShell [-Debug]\n");
		return 1;
	}        

	// Variables
	int i;
	char *inStr;

	// Structs
	Param_t *paramsP;
	
	// Initialize struct
	Param_t params = {NULL, NULL, 0, 0};
	for (i = 0 ; i < MAXARGS ; i++) params.argumentVector[i] = NULL;
  	paramsP = &params;
        
	
 	// Read parse and assign user input to struct

	do
	{
        printf("$$$ ");
	
  	inStr = readLine();
	parseStr(inStr, paramsP); 
	  
	if(strcmp(inStr, "-Debug\n") == 0){
	     printParams(paramsP);
	 }
               	
        } while(strcmp(inStr,"exit\n"));
 	
return (0); 
}