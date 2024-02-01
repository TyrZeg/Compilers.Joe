/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Fall, 2023
* Author: TO_DO
* Professors: Paulo Sousa
************************************************************
=---------------------------------------------------------------------------=
|                   COMPILERS - ALGONQUIN COLLEGE (W24)                     |
=---------------------------------------------------------------------------=
          _____                   _______                   _____          
         /\    \                 /::\    \                 /\    \         
        /::\    \               /::::\    \               /::\    \        
        \:::\    \             /::::::\    \             /::::\    \       
         \:::\    \           /::::::::\    \           /::::::\    \      
          \:::\    \         /:::/~~\:::\    \         /:::/\:::\    \     
           \:::\    \       /:::/    \:::\    \       /:::/__\:::\    \    
           /::::\    \     /:::/    / \:::\    \     /::::\   \:::\    \   
  _____   /::::::\    \   /:::/____/   \:::\____\   /::::::\   \:::\    \  
 /\    \ /:::/\:::\    \ |:::|    |     |:::|    | /:::/\:::\   \:::\    \ 
/::\    /:::/  \:::\____\|:::|____|     |:::|    |/:::/__\:::\   \:::\____\
\:::\  /:::/    \::/    / \:::\    \   /:::/    / \:::\   \:::\   \::/    /
 \:::\/:::/    / \/____/   \:::\    \ /:::/    /   \:::\   \:::\   \/____/ 
  \::::::/    /             \:::\    /:::/    /     \:::\   \:::\    \     
   \::::/    /               \:::\__/:::/    /       \:::\   \:::\____\    
    \::/    /                 \::::::::/    /         \:::\   \::/    /    
     \/____/                   \::::::/    /           \:::\   \/____/     
                                \::::/    /             \:::\    \         
                                 \::/____/               \:::\____\        
                                  ~~                      \::/    /        
                                                           \/____/         
                                                                        
=----------------------------------------------------------------------------=
*/

/*
***********************************************************
* File name: Reader.c
* Compiler: MS Visual Studio 2022
* Course: CST 8152 � Compilers, Lab Section: [011, 012, 013]
* Assignment: A12.
* Date: May 01 2023
* Professor: Paulo Sousa
* Purpose: This file is the main code for Buffer/Reader (A12)
************************************************************
*/

/*
 *.............................................................................
 * MAIN ADVICE:
 * - Please check the "TODO" labels to develop your activity.
 * - Review the functions to use "Defensive Programming".
 *.............................................................................
 */

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef READER_H_
#include "Reader.h"
#endif

/*
***********************************************************
* Function name: readerCreate
* Purpose: Creates the buffer reader according to capacity, increment
	factor and operational mode ('f', 'a', 'm')
* Author: Svillen Ranev / Paulo Sousa
* History/Versions: S22
* Called functions: calloc(), malloc()
* Parameters:
*   size = initial capacity
*   increment = increment factor
*   mode = operational mode
* Return value: bPointer (pointer to reader)
* Algorithm: Allocation of memory according to inicial (default) values.
* TODO ......................................................
*	- Adjust datatypes for your LANGUAGE.
*   - Use defensive programming
*	- Check boundary conditions
*	- Check flags.
*************************************************************
*/

BufferPointer readerCreate(int size, int increment, int mode) {
	BufferPointer readerPointer;
	/* TO_DO: Defensive programming  DONE*/
	if(!size){
		size = READER_DEFAULT_SIZE;
		increment = READER_DEFAULT_INCREMENT;}

	if(!increment)
		mode = MODE_FIXED;
	
	if(mode != MODE_FIXED && mode != MODE_ADDIT && mode != MODE_MULTI)	
		return NULL;
	/* TO_DO: Adjust the values according to parameters */
	readerPointer = (BufferPointer)calloc(1, sizeof(Buffer));
	if (!readerPointer)
		return NULL;
	readerPointer->content = (str)malloc(size);
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer -> content)
		return NULL;
	/* TO_DO: Initialize the histogram DONE*/
	for (int i = 0; i < NCHAR; i++)
		readerPointer -> histogram[i] = 0;
	readerPointer->size = size;
	readerPointer->increment = increment;
	readerPointer->mode = mode;
	/* TO_DO: Initialize flags ????*/
	SET(READER_DEFAULT_FLAG);
	/* TO_DO: The created flag must be signalized as EMP DONE*/
	SET(EMP_FLAG);
	/* NEW: Cleaning the content */
	if (readerPointer->content)
		readerPointer->content[0] = READER_TERMINATOR;
	readerPointer->position.wrte = 0;
	readerPointer->position.mark = 0;
	readerPointer->position.read = 0;
	return readerPointer;
}


/*
***********************************************************
* Function name: readerAddChar
* Purpose: Adds a char to buffer reader
* Parameters:
*   readerPointer = pointer to Buffer Reader
*   ch = char to be added
* Return value:
*	readerPointer (pointer to Buffer Reader)
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/

BufferPointer readerAddChar(BufferPointer const readerPointer, char ch) {
	str tempReader = NULL;
	int newSize = 0;
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return NULL;	

	if(ch < 0)
		return NULL;	
	/* TO_DO: Reset Realocation DONE*/
	RESET(REL_FLAG);
	/* TO_DO: Test the inclusion of chars ??? */
	if (readerPointer->position.wrte * (int)sizeof(char) < readerPointer->size) {
		/* TO_DO: This buffer is NOT full ??? */

		
	} else {
		/* TO_DO: Reset Full flag DONE*/
		RESET(FUL_FLAG);
		switch (readerPointer->mode) {
		case MODE_FIXED:
			return NULL;
		case MODE_ADDIT:
			/* TO_DO: Adjust new size DONE*/
			newSize = readerPointer->size + readerPointer->increment;
			/* TO_DO: Defensive programming DONE*/
			if(newSize < readerPointer -> size)
				return NULL;
			break;
		case MODE_MULTI:
			/* TO_DO: Adjust new size DONE*/
			newSize = readerPointer->size * readerPointer->increment;
			/* TO_DO: Defensive programming */
			if(newSize < readerPointer -> size)
				return NULL;
			break;
		default:
			return NULL;
		}
		/* TO_DO: New reader allocation */
		tempReader = realloc(readerPointer->content, newSize);
		/* TO_DO: Defensive programming */
		if (!tempReader)
				return NULL;
		/* TO_DO: Check Relocation ??? */
		if (tempReader != readerPointer->content){
			SET(REL_FLAG);
		}
		readerPointer -> content = tempReader;
		readerPointer -> size = newSize;
	}
	/* TO_DO: Add the char DONE*/
	readerPointer->content[readerPointer->position.wrte++] = ch;
	/* TO_DO: Updates histogram DONE*/
	readerPointer->histogram[ch]++;
	return readerPointer;
}

/*
***********************************************************
* Function name: readerClear
* Purpose: Clears the buffer reader
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
joe_boln readerClear(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
		if (!readerPointer)
			return False;	
	/* TO_DO: Adjust flags original ???*/
	readerPointer->position.wrte = readerPointer->position.mark = readerPointer->position.read = 0;
	RESET(FUL_FLAG);
	return True;
}

/*
***********************************************************
* Function name: readerFree
* Purpose: Releases the buffer address
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
joe_boln readerFree(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer){
		return False;
	}
	/* TO_DO: Free pointers DONE*/
	free(readerPointer -> content);
	free(readerPointer);
	return True;
}

/*
***********************************************************
* Function name: readerIsFull
* Purpose: Checks if buffer reader is full
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
joe_boln readerIsFull(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming ???*/
	if (!readerPointer)
		return False;
	/* TO_DO: Check flag if buffer is FUL DONE*/
	if(CHK(FUL_FLAG))
		return True;
	
	return False;
}


/*
***********************************************************
* Function name: readerIsEmpty
* Purpose: Checks if buffer reader is empty.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
joe_boln readerIsEmpty(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming ???*/
	if(!readerPointer)
		return True;

	/* TO_DO: Check flag if buffer is EMP DONE*/
	if(CHK(EMP_FLAG))
		return True;
	
	return False;
}

/*
***********************************************************
* Function name: readerSetMark
* Purpose: Adjust the position of mark in the buffer
* Parameters:
*   readerPointer = pointer to Buffer Reader
*   mark = mark position for char
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
joe_boln readerSetMark(BufferPointer const readerPointer, int mark) {
	/* TO_DO: Defensive programming Done ???*/
	if(!readerPointer)
		return False;

	if(readerPointer->position.wrte < mark < 0)
		return False;
	/* TO_DO: Adjust mark ???*/
	readerPointer->position.mark = mark;
	return True;
}


/*
***********************************************************
* Function name: readerPrint
* Purpose: Prints the string in the buffer.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Number of chars printed.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
* 	DO THIS!!!
*************************************************************
*/
int readerPrint(BufferPointer const readerPointer) {
	int cont = 0;
	char c;
	/* TO_DO: Defensive programming (including invalid chars) Done*/
	if(!readerPointer)
		return READER_ERROR;
	c = readerGetChar(readerPointer);
	/* TO_DO: Check flag if buffer EOB has achieved ???*/
	while (cont < readerPointer->position.wrte && c!= READER_TERMINATOR) {
		cont++;
		printf("%c", c);
		c = readerGetChar(readerPointer);
	}
	return cont;
}

/*
***********************************************************
* Function name: readerLoad
* Purpose: Loads the string in the buffer with the content of
	an specific file.
* Parameters:
*   readerPointer = pointer to Buffer Reader
*   fileDescriptor = pointer to file descriptor
* Return value:
*	Number of chars read and put in buffer.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
int readerLoad(BufferPointer const readerPointer, FILE* const fileDescriptor) {
	int size = 0;
	char c;
	/* TO_DO: Defensive programming ???*/
	if(!readerPointer)
		return READER_ERROR;
	if(!fileDescriptor)
		return READER_ERROR;
	

	c = (char)fgetc(fileDescriptor);
	while (!feof(fileDescriptor)) {
		if (!readerAddChar(readerPointer, c)) {
			ungetc(c, fileDescriptor);
			return READER_ERROR;
		}
		c = (char)fgetc(fileDescriptor);
		size++;
	}
	/* TO_DO: Defensive programming ???*/
	if (!(c = getchar()) != READER_TERMINATOR)
		return READER_ERROR;
	return size;
}


/*
***********************************************************
* Function name: readerRecover
* Purpose: Rewinds the buffer.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
joe_boln readerRecover(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return False;
	/* TO_DO: Recover positions ???*/
	readerPointer->position.read = 0;
	readerPointer->position.mark = 0;
	return True;
}


/*
***********************************************************
* Function name: readerRetract
* Purpose: Retracts the buffer to put back the char in buffer.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
joe_boln readerRetract(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return False;
	/* TO_DO: Retract (return 1 pos read) ???*/
	if(readerPointer -> position.read > 0){
		readerPointer -> position.read --;
	}
	return True;
}


/*
***********************************************************
* Function name: readerRestore
* Purpose: Resets the buffer.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
joe_boln readerRestore(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return False;
	/* TO_DO: Restore positions (read/mark) ???*/
	readerPointer->position.read = readerPointer->position.mark;
	return True;
}


/*
***********************************************************
* Function name: readerGetChar
* Purpose: Returns the char in the getC position.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Char in the getC position.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
char readerGetChar(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return READER_TERMINATOR;
	/* TO_DO: Check condition to read/wrte DONE*/
	if (readerPointer->position.read == readerPointer->position.wrte) {
		/* TO_DO: Set EOB flag DONE*/
		SET(END_FLAG);
		return READER_TERMINATOR;
	}
	/* TO_DO: Reset EOB flag DONE*/
	RESET(END_FLAG);
	if (readerPointer->position.wrte > 0)
		return readerPointer->content[readerPointer->position.read++];
	return READER_TERMINATOR;
}


/*
***********************************************************
* Function name: readerGetContent
* Purpose: Returns the pointer to String.
* Parameters:
*   readerPointer = pointer to Buffer Reader
*   pos = position to get the pointer
* Return value:
*	Position of string char.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
str readerGetContent(BufferPointer const readerPointer, int pos) {
	/* TO_DO: Defensive programming DONE?*/
	if(!readerPointer)
		return NULL;
	if (pos < 0)
		return NULL;
	/* TO_DO: Return content (string) DONE */
	return readerPointer->content + pos;;
}



/*
***********************************************************
* Function name: readerGetPosRead
* Purpose: Returns the value of getCPosition.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	The read position offset.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
int readerGetPosRead(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return READER_ERROR;
	/* TO_DO: Return read ???*/
	return readerPointer->position.read;
}


/*
***********************************************************
* Function name: readerGetPosWrte
* Purpose: Returns the position of char to be added
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Write position
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
int readerGetPosWrte(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return READER_ERROR;
	/* TO_DO: Return wrte ???*/
	return readerPointer -> position.wrte;
}


/*
***********************************************************
* Function name: readerGetPosMark
* Purpose: Returns the position of mark in the buffer
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Mark position.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
int readerGetPosMark(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return READER_ERROR;
	/* TO_DO: Return mark */
	return readerPointer -> position.mark;
}


/*
***********************************************************
* Function name: readerGetSize
* Purpose: Returns the current buffer capacity
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Size of buffer.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
int readerGetSize(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if(!readerPointer)
		return READER_ERROR;
	/* TO_DO: Return size */
	return readerPointer -> size;
}

/*
***********************************************************
* Function name: readerGetInc
* Purpose: Returns the buffer increment.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	The Buffer increment.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
int readerGetInc(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return READER_ERROR;
	/* TO_DO: Return increment DONE*/
	return readerPointer -> increment;
}

/*
***********************************************************
* Function name: readerGetMode
* Purpose: Returns the operational mode
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Operational mode.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
int readerGetMode(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return READER_ERROR;
	/* TO_DO: Return mode DONE*/
	return readerPointer -> mode;
}


/*
***********************************************************
* Function name: readerGetFlags
* Purpose: Returns the entire flags of Buffer.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Flags from Buffer.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
joe_byte readerGetFlags(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return READER_ERROR;
	/* TO_DO: Return flags DONE*/
	return readerPointer -> flags;
}



/*
***********************************************************
* Function name: readerPrintStat
* Purpose: Shows the char statistic.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value: (Void)
* TO_DO:
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
joe_void 
readerPrintStat(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return;
	/* TO_DO: Print the histogram DONE*/
	for(int i=0; i<NCHAR; i++)
		if (readerPointer -> histogram[i]>0)
		printf("Histogram[%c] = %d\n", i, readerPointer -> histogram[i]);
		 
}

/*
***********************************************************
* Function name: readerNumErrors
* Purpose: Returns the number of errors found.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Number of errors.
* TO_DO:
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
int readerNumErrors(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming DONE*/
	if(!readerPointer)
		return READER_ERROR;
	/* TO_DO: Returns the number of errors DONE*/
	return readerPointer -> numReaderErrors;
}
