/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Winter, 2024
* Author: Brayden Johnston
* Professors: Paulo Sousa
************************************************************
=---------------------------------------=
|  COMPILERS - ALGONQUIN COLLEGE (F23)  |
=---------------------------------------=
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
                                                                           
*/

/*
************************************************************
* File name: compilers.c
* Compiler: MS Visual Studio 2022
* Course: CST 8152 � Compilers, Lab Section: [011, 012]
* Assignment: A12, A22, A32.
* Date: May 01 2023
* Professor: Paulo Sousa
* Purpose: This file is the main program of Compilers Project
* Function list: main().
************************************************************
*/


#include <stdio.h>
#include <stdlib.h>

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

/*
 * ............................................................................
 * ADVICE 1:
 * Please check the "TODO" labels to develop your activity.
 *
 * ADVICE 2: This file must be updated according to each assignment
 * (see the progression: reader > scanner > parser).
 * ............................................................................
 */

/*
***********************************************************
* Function name: main
* Purpose: Main function
* Author: Paulo Sousa
* History/Versions: Ver F22
* Called functions: mainReader(), mainScanner(), mainParser()
* Parameters: Command line arguments - argc, argv
* Return value: Status
* Algorithm: -
*************************************************************
*/

int main(int argc, char** argv) {
	int i;
	printLogo();
	if (DEBUG) {
		for (i = 0; i < argc; ++i)
			printf("argv[%d] = %s\n", i, argv[i]);
	}
	if (argc < 2) {
		printf("%s%c%s%c%s%c%s", "OPTIONS:\n* [",
			PGM_READER, "] - Reader\n* [",
			PGM_SCANNER, "] - Scanner\n* [",
			PGM_PARSER, "] - Parser\n");
		return EXIT_FAILURE;
	}
	char option = argv[1][0];
	switch (option) {
	case PGM_READER:
		printf("%s%c%s", "\n[Option '", PGM_READER, "': Starting READER .....]\n\n");
		mainReader(argc, argv);
		break;
	/* TO_DO: Include later SCANNER (A22) and PARSER (A32) */
	default:
		printf("%s%c%s%c%s%c%s", "* OPTIONS:\n- [",
			PGM_READER, "] - Reader\n- [",
			PGM_SCANNER, "] - Scanner\n- [",
			PGM_PARSER, "] - Parser\n");
		break;
	}
	return EXIT_SUCCESS;
}

/*
***********************************************************
* Function name: printLogo
* Purpose: Print Logo
* Author: Paulo Sousa
* History/Versions: Ver S23
* Called functions: -
* Parameters: -
* Return value: (Null)
* Algorithm: -
*************************************************************
*/

/* TO_DOc: Update your logo with your own language message */

joe_void printLogo() {
	printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		"\t=-----------------------------------------------------------------------------=\n",
		"\t|                  COMPILERS - ALGONQUIN COLLEGE (W24)                        |\n",
		"\t=-----------------------------------------------------------------------------=\n",  
		"\t           _____                   _______                   _____            |\n",     
		"\t|         /\\    \\                 /::\\    \\                 /\\    \\           |\n",
		"\t|        /::\\    \\               /::::\\    \\               /::\\    \\          |\n",
		"\t|        \\:::\\    \\             /::::::\\    \\             /::::\\    \\         |\n",
		"\t|         \\:::\\    \\           /::::::::\\    \\           /::::::\\    \\        |\n",
		"\t|          \\:::\\    \\         /:::/~~\\:::\\    \\         /:::/\\:::\\    \\       |\n",
		"\t|           \\:::\\    \\       /:::/    \\:::\\    \\       /:::/__\\:::\\    \\      |\n",
		"\t|           /::::\\    \\     /:::/    / \\:::\\    \\     /::::\\   \\:::\\    \\     |\n",
		"\t|  _____   /::::::\\    \\   /:::/____/   \\:::\\____\\   /::::::\\   \\:::\\    \\    |\n",
		"\t| /\\    \\ /:::/\\:::\\    \\ |:::|    |     |:::|    | /:::/\\:::\\   \\:::\\    \\   |\n",
		"\t|/::\\    /:::/  \\:::\\____\\|:::|____|     |:::|    |/:::/__\\:::\\   \\:::\\____\\  |\n",
		"\t|\\:::\\  /:::/    \\::/    / \\:::\\    \\   /:::/    / \\:::\\   \\:::\\   \\::/    /  |\n",
		"\t| \\:::\\/:::/    / \\/____/   \\:::\\    \\ /:::/    /   \\:::\\   \\:::\\   \\/____/   |\n",
		"\t|  \\::::::/    /             \\:::\\    /:::/    /     \\:::\\   \\:::\\    \\       |\n",
		"\t|   \\::::/    /               \\:::\\__/:::/    /       \\:::\\   \\:::\\____\\      |\n",
		"\t|    \\::/    /                 \\::::::::/    /         \\:::\\   \\::/    /      |\n",
		"\t|     \\/____/                   \\::::::/    /           \\:::\\   \\/____/       |\n",
		"\t|                                \\::::/    /             \\:::\\    \\           |\n",
		"\t|                                 \\::/____/               \\:::\\____\\          |\n",
		"\t|                                  ~~                      \\::/    /          |\n",
		"\t|                                                           \\/____/           |\n",
		"\t=-----------------------------------------------------------------------------=\n"
	);
}
