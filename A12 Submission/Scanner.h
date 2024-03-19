/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Spring, 2024
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
* File name: Scanner.h
* Compiler: MS Visual Studio 2022
* Course: CST 8152 � Compilers, Lab Section: [011, 012]
* Assignment: A22, A32.
* Date: May 01 2022
* Purpose: This file is the main header for Scanner (.h)
* Function list: (...).
*************************************************************/

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef READER_H_
#include "Reader.h"
#endif

#ifndef SCANNER_H_
#define SCANNER_H_


#ifndef NULL
#include <_null.h> /* NULL pointer constant is defined there */
#endif

/*#pragma warning(1:4001) */	/*to enforce C89 type comments  - to make //comments an warning */

/*#pragma warning(error:4001)*/	/* to enforce C89 comments - to make // comments an error */

/* Constants */
#define VID_LEN 20  /* variable identifier length */
#define ERR_LEN 40  /* error message length */
#define NUM_LEN 5   /* maximum number of digits for IL */

#define RTE_CODE 1  /* Value for run-time error */

/* TO_DO: Define the number of tokens */
#define NUM_TOKENS 37

/* TO_DO: Define Token codes - Create your token classes */
enum TOKENS {
	ERR_T,		/*  0: Error token */
	MNID_T,		/*  1: Method name identifier token (start: &) */
	INL_T,		/*  2: Integer literal token */
	STR_T,		/*  3: String literal token */
	LPR_T,		/*  4: Left parenthesis token */
	RPR_T,		/*  5: Right parenthesis token */
	LBR_T,		/*  6: Left brace token */
	RBR_T,		/*  7: Right brace token */
	KW_T,		/*  8: Keyword token */
	EOS_T,		/*  9: End of statement (semicolon) */
	RTE_T,		/* 10: Run-time error token */
	SEOF_T,		/* 11: Source end-of-file token */
	CMT_T,		/* 12: Comment token */
	ADD_T,		/* 13: Addition token */
	SUB_T,		/* 14: Subtraction token */
	MUL_T,		/* 15: Multiplication token */
	DIV_T,		/* 16: Division token */
	NOT_T,		/* 17: Not token */
	GRT_T,		/* 18: Greater than token */
	LST_T,		/* 19: Less than token */
	EQU_T,		/* 20: Equals token */
	FLT_T,		/* 21: Float literal token */
	MLC_T,		/* 22: Multiline-Comment token */
	COM_T,		/* 23: Comma token */
	MTX_T,		/* 24: Matrix token */
	ARY_T,		/* 25: Array token */
	NTP_T,		/* 26: Non-Type token */
	BOO_T,		/* 27: Boolean token */
	POW_T,		/* 28: Power of token */
	LSB_T,		/* 29: Left Square Bracket token */
	RSB_T,		/* 30: Right Square Bracket token */
	QUO_T,		/* 31: Single Quote token */
	VAR_T,		/* 32: Variable Name Iden token */
	COL_T,		/* 33: Collen token */
	BYT_T,		/* 34: Byte token */
	AND_T,		/* 35: And token */
	OR_T		/* 36: Or token */
};

/* TO_DO: Define the list of keywords */
static str tokenStrTable[NUM_TOKENS] = {
	"ERR_T",
	"MNID_T",
	"INL_T",
	"STR_T",
	"LPR_T",
	"RPR_T",
	"LBR_T",
	"RBR_T",
	"KW_T",
	"EOS_T",
	"RTE_T",
	"SEOF_T",
	"CMT_T",
	"ADD_T",
	"SUB_T",
	"MUL_T",
	"DIV_T",
	"NOT_T",
	"GRT_T",
	"LST_T",
	"EQU_T",
	"FLT_T",
	"MLC_T",
	"COM_T",
	"MTX_T",
	"ARY_T",
	"NTP_T",
	"BOO_T",
	"POW_T",
	"LSB_T",
	"RSB_T",
	"QUO_T",
	"VAR_T",
	"COL_T",
	"BYT_T",
	"AND_T",
	"OR_T"
};

/* TO_DO: Operators token attributes */
typedef enum ArithmeticOperators { OP_ADD, OP_SUB, OP_MUL, OP_DIV } AriOperator;
typedef enum RelationalOperators { OP_EQ, OP_NE, OP_GT, OP_LT } RelOperator;
typedef enum LogicalOperators { OP_AND, OP_OR, OP_NOT } LogOperator;
typedef enum SourceEndOfFile { SEOF_0, SEOF_255 } EofOperator;

/* TO_DO: Data structures for declaring the token and its attributes */
typedef union TokenAttribute {
	joe_long codeType;      /* integer attributes accessor */
	AriOperator arithmeticOperator;		/* arithmetic operator attribute code */
	RelOperator relationalOperator;		/* relational operator attribute code */
	LogOperator logicalOperator;		/* logical operator attribute code */
	EofOperator seofType;				/* source-end-of-file attribute code */
	joe_long intValue;				/* integer literal attribute (value) */
	joe_long keywordIndex;			/* keyword index in the keyword table */
	joe_long contentString;			/* string literal offset from the beginning of the string literal buffer (stringLiteralTable->content) */
	joe_float floatValue;				/* floating-point literal attribute (value) */
	double doubleContent;	/* Double literal attribute (value) */
	joe_matrix matrixContent;	/* Matrix literal attribute (value) */
	joe_byte byteContent;		/* byte literal attribute (value) */
	joe_array arrayContent;		/* array literal attribute (value) */
	joe_nonType nontypeContent;	/* nonType literal attribute (value) */
	joe_boln booleanContent;	/* boolean literal attribute (value) */
	joe_char idLexeme[VID_LEN + 1];	/* variable identifier token attribute */
	joe_char errLexeme[ERR_LEN + 1];	/* error token attribite */
} TokenAttribute;

/* TO_DO: Should be used if no symbol table is implemented */
typedef struct idAttibutes {
	joe_byte flags;			/* Flags information */
	union {
		joe_long intValue;				/* Integer value */
		joe_float floatValue;			/* Float value */
		str stringContent;		/* String value */
		joe_matrix matrixContent;	/* Matrix value */
		joe_array arrayContent;		/* array value */
		joe_byte byteContent;		/* byte value */
		joe_nonType nontypeContent;	/* nonType value */
		joe_boln booleanContent;	/* boolean value */
	} values;
} IdAttibutes;

/* Token declaration */
typedef struct Token {
	joe_long code;				/* token code */
	TokenAttribute attribute;	/* token attribute */
	IdAttibutes   idAttribute;	/* not used in this scanner implementation - for further use */
} Token;

/* Scanner */
typedef struct scannerData {
	joe_long scanHistogram[NUM_TOKENS];	/* Statistics of chars */
} ScannerData, * pScanData;

///////////////////////////////////////////////////////////////////////////////////////////////////////

/* EOF definitions */
#define CHARSEOF0 '\0'
#define CHARSEOF255 0xFF

/*  Special case tokens processed separately one by one in the token-driven part of the scanner:
 *  LPR_T, RPR_T, LBR_T, RBR_T, EOS_T, SEOF_T and special chars used for tokenis include _, & and ' */

/* TO_DO: Define lexeme FIXED classes */
/* These constants will be used on nextClass */
#define CHRCOL2 '_'
#define CHRCOL3 '('
#define CHRCOL4 '\''
#define CHRCOL6 '#'
#define CHRCOL10 '\n'
#define CHRCOL8 '.'
#define CHRCOL9 '='
/* These constants will be used on VID / MID function */
#define MNID_SUF '('
#define VAR_SUF '='
#define COMM_SYM '#'
#define COMM2_SYM '\n'

/* TO_DO: Error states and illegal state */
#define ESNR	9		/* Error state with no retract */
#define ESWR	10		/* Error state with retract */
#define FS		11		/* Illegal state */

 /* TO_DO: State transition table definition */
#define NUM_STATES		21
#define CHAR_CLASSES	12

/* TO_DO: Transition table - type of states defined in separate table */
static joe_long transitionTable[NUM_STATES][CHAR_CLASSES] = {
/*    [A-z],[0-9],    _,    (,   ', SEOF,    #, other,    .,	 =,   \n
	   L(0), D(1), U(2), M(3), Q(4), E(5), C(6),  O(7), P(8), V(9), N(10) */
	{     1,    7, ESNR, ESNR,    4, ESWR,	 11, ESNR, ESNR, ESNR, ESNR},	// S0: NOAS
	{     1,    1,    1,    2,	  3,    3,    3,    3,	  3,   20,	  3},	// S1: NOAS
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,   FS,	 FS,   FS,   FS},	// S2: ASNR (MVID)
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,   FS,	 FS,   FS,   FS},	// S3: ASWR (KEY)
	{     5,    5,    5,    5,   13, ESWR,	  5,    5,	  5,    5,	  5},	// S4: NOAS
	{	  5,    5,    5,    5,    6,	5,    5,	5,    5,    5,    5},	// S5: NOAS												  
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,   FS,	 FS,   FS,   FS},	// S6: ASNR (SL)
	{    FS,    7,   FS,   FS,   FS, ESWR,	 FS,    8,	 17,    8,    8},	// S7: NOAS
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,   FS,	 FS,   FS,   FS},	// S8: ASNR (INT)
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,   FS,	 FS,   FS,   FS},	// S9: ASNR (ES)
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,   FS,   FS,   FS,   FS},   // S10: ASWR (ER)
	{    11,   11,   11,   11,   11,   11,	 11,   11,   11,   11,   12},	// S11: NOAS
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,   FS,   FS,   FS,   FS},	// S12: ASWR (COM)
	{    FS,   FS,   FS,   FS,   14,   FS,	 FS,   FS,   FS,   FS,   FS},   // S13: NOAS
	{    14,   14,   14,   14,   15,   14,	 14,   14,   14,   14,   14},   // S14: NOAS
	{    14,   14,   14,   14,   16,   14,	 14,   14,   14,   14,   14},   // S15: NOAS
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,   FS,   FS,   FS,   FS},   // S16: ASWR (MCOM)
	{    FS,   18,   FS,   FS,   FS, ESWR,	 FS,   FS,   FS,   FS,   FS},   // S17: NOAS
	{    FS,   18,   FS,   FS,   FS, ESWR,	 FS,   19,   FS,   19,   19},   // S18: NOAS
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,   FS,   FS,   FS,   FS},   // S19: ASWR (FLOAT)
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,   FS,   FS,   FS,   FS},   // S20: ASWR (VAR)
};

/* Define accepting states types */
#define NOFS	0		/* not accepting state */
#define FSNR	1		/* accepting state with no retract */
#define FSWR	2		/* accepting state with retract */

/* TO_DO: Define list of acceptable states */
static joe_long stateType[NUM_STATES] = {
	NOFS, /* 00 */
	NOFS, /* 01 */
	FSNR, /* 02 (MID) - Methods */
	FSWR, /* 03 (KEY) */
	NOFS, /* 04 */
	NOFS, /* 05 */
	FSNR, /* 06 (SL) */
	NOFS, /* 07 */
	FSWR, /* 08 (INT) */
	FSNR, /* 09 (Err1 - no retract) */
	FSWR,  /* 10 (Err2 - retract) */
	NOFS, /* 11 */
	FSNR, /* 12 (COM) */
	NOFS, /* 13 */
	NOFS, /* 14 */
	NOFS, /* 15 */
	FSNR, /* 16 (MCOM) */
	NOFS, /* 17 */
	NOFS, /* 18 */
	FSWR, /* 19 (FLOAT)*/
	FSNR  /* 20 (VAR) */
};

/*
-------------------------------------------------
TO_DO: Adjust your functions'definitions
-------------------------------------------------
*/

/* Static (local) function  prototypes */
joe_long			startScanner(BufferPointer psc_buf);
static joe_long	nextClass(joe_char c);					/* character class function */
static joe_long	nextState(joe_long, joe_char);		/* state machine function */
joe_void			printScannerData(ScannerData scData);
Token				tokenizer(joe_void);

/*
-------------------------------------------------
Automata definitions
-------------------------------------------------
*/

/* TO_DO: Pointer to function (of one char * argument) returning Token */
typedef Token(*PTR_ACCFUN)(str lexeme);

/* Declare accepting states functions */
Token funcSL	(str lexeme);
Token funcIL	(str lexeme);
Token funcID	(str lexeme);
Token funcCMT   (str lexeme);
Token funcKEY	(str lexeme);
Token funcErr	(str lexeme);
Token funcMLC   (str lexeme);
Token funcFLT   (str lexeme);

/* 
 * Accepting function (action) callback table (array) definition 
 * If you do not want to use the typedef, the equvalent declaration is:
 */

/* TO_DO: Define final state table */
static PTR_ACCFUN finalStateTable[NUM_STATES] = {
	NULL,		/* -    [00] */
	NULL,		/* -    [01] */
	funcID,		/* MNID	[02] */
	funcKEY,	/* KEY  [03] */
	NULL,		/* -    [04] */
	NULL,		/* -    [05] */
	funcSL,		/* SL   [06] */
	NULL,		/* -    [07] */
	funcIL,		/*  INT [08] */
	funcErr,	/* ERR1 [09] */
	funcErr,	/* ERR2 [10] */
	NULL,		/* -    [11] */
	funcCMT,	/*  COM [12] */
	NULL,		/* -    [13] */
	NULL,		/* -    [14] */
	NULL,		/* -    [15] */
	funcMLC,	/* MCOM [16] */
	NULL,		/* -    [17] */
	NULL,		/* -    [18] */
	funcFLT,	/* FLOAT[19] */
	funcID		/*  VAR [20] */
};

/*
-------------------------------------------------
Language keywords
-------------------------------------------------
*/

/* TO_DO: Define the number of Keywords from the language */
#define KWT_SIZE 22

/* TO_DO: Define the list of keywords */
static str keywordTable[KWT_SIZE] = {
	"data",		/* KW00 */
	"code",		/* KW01 */
	"int",		/* KW02 */
	"real",		/* KW03 */
	"string",	/* KW04 */
	"if",		/* KW05 */
	"then",		/* KW06 */
	"else",		/* KW07 */
	"while",	/* KW08 */
	"do",		/* KW09 */
	"false",	/* KW10 */
	"random",	/* KW11 */
	"break",	/* KW12 */
	"true",		/* KW13 */
	"class",	/* KW14 */
	"return",	/* KW15 */
	"continue",	/* KW16 */
	"def",		/* KW17 */
	"for",		/* KW19 */
	"global",	/* KW20 */
	"try",		/* KW22 */
	"pow",		/* KW23 */
};

/* NEW SECTION: About indentation */

/*
 * Scanner attributes to be used (ex: including: intendation data
 */

#define INDENT '\t'  /* Tabulation */

/* TO_DO: Should be used if no symbol table is implemented */
typedef struct languageAttributes {
	joe_char indentationCharType;
	joe_long indentationCurrentPos;
	/* TO_DO: Include any extra attribute to be used in your scanner (OPTIONAL and FREE) */
} LanguageAttributes;

/* Number of errors */
joe_long numScannerErrors;

/* Scanner data */
ScannerData scData;

#endif
