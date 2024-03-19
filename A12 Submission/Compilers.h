/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Fall, 2023
* Author: Brayden / Lys
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
************************************************************
* File name: Compilers.h
* Compiler: MS Visual Studio 2022
* Course: CST 8152 � Compilers, Lab Section: [011, 012]
* Assignment: A12, A22, A32.
* Date: May 01 2023
* Professor: Paulo Sousa
* Purpose: This file defines the functions called by main function.
* Function list: mainReader(), mainScanner(), mainParser().
*************************************************************/

#ifndef COMPILERS_H_
#define COMPILERS_H_

#define DEBUG 0

/*
 * ............................................................................
 * ADVICE 1:
 * Please check the "TODO" labels to develop your activity.
 *
 * ADVICE 2: This file must be updated according to each assignment
 * (see the progression: reader > scanner > parser).
 * ............................................................................
 */

/* TO_DO: Adjust your language (cannot be "Sofia") */

/* Language name */
#define STR_LANGNAME	"Joe"

/* Logical constants - adapt for your language */
#define True 1
#define False 0

/*
------------------------------------------------------------
Data types definitions
NOTE: Some types may not be directly used by your language,
		but they can be necessary for conversions.
------------------------------------------------------------
*/


/* TO_DO: Define your typedefs */
typedef char			joe_char;
typedef char* 			str;
//typedef int				joe_int;
typedef float			joe_float;
typedef void			joe_void;

typedef unsigned char	joe_boln;
typedef unsigned char	joe_byte;

typedef long			joe_long;
//typedef double			joe_doub;
typedef struct {
    int rows;
    int cols;
    float **data; // Assuming a 2D array of floats for matrix representation
} joe_matrix;

typedef struct {
    int size;
    float *data; // Assuming a 1D array of floats
} joe_array;

typedef union {
    int int_val;
    float float_val;
    char char_val;
    // Add more data types as needed
} joe_nonType;


/*
------------------------------------------------------------
Programs:
1: Reader - invokes MainReader code
2: Scanner - invokes MainScanner code
3: Parser - invokes MainParser code
------------------------------------------------------------
*/
enum PROGRAMS {
	PGM_READER	= 'r',
	PGM_SCANNER = 's',
	PGM_PARSER	= 'p'
};

/*
------------------------------------------------------------
Main functions signatures
(Code will be updated during next assignments)
------------------------------------------------------------
*/
int mainReader(int argc, str* argv);

joe_long mainScanner(joe_long argc, str* argv);

/* 
TO_DO: Include later mainScaner (A22) and mainParser (A32)
*/
joe_void printLogo();

#endif
