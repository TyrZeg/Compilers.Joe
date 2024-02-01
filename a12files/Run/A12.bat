:: ---------------------------------------------------------------------
:: COMPILERS COURSE - SCRIPT                                           -
:: SCRIPT A12 - CST8152 - Fall 2023                                    -
:: ---------------------------------------------------------------------

CLS
SET COMPILER=joe.exe

SET FILE1=Magic8
SET FILE2=Password
SET FILE3=OddEven
SET FILE4=Anagram
::SET FILE5=INPUT4_Datatypes
::SET FILE6=INPUT5_General
::SET FILE7=INPUT6_Big

:: 1:12:28
SET ASSIGNMENT=A12
SET EXTENSION=joe
SET OUTPUT=out
SET ERROR=err

SET PARAM=r

:: ---------------------------------------------------------------------
:: Begin of Tests (A12 - F23) ------------------------------------------
:: ---------------------------------------------------------------------

@echo off

ECHO "=-------------------------------------------------------------------------="
ECHO "|                COMPILERS - ALGONQUIN COLLEGE (W24)                      |"
ECHO "=-------------------------------------------------------------------------="
ECHO "          _____                   _______                   _____          " 
ECHO "         /\    \                 /::\    \                 /\    \         " 
ECHO "        /::\    \               /::::\    \               /::\    \        " 
ECHO "        \:::\    \             /::::::\    \             /::::\    \       " 
ECHO "         \:::\    \           /::::::::\    \           /::::::\    \      " 
ECHO "          \:::\    \         /:::/~~\:::\    \         /:::/\:::\    \     " 
ECHO "           \:::\    \       /:::/    \:::\    \       /:::/__\:::\    \    " 
ECHO "           /::::\    \     /:::/    / \:::\    \     /::::\   \:::\    \   " 
ECHO "  _____   /::::::\    \   /:::/____/   \:::\____\   /::::::\   \:::\    \  " 
ECHO " /\    \ /:::/\:::\    \ |:::|    |     |:::|    | /:::/\:::\   \:::\    \ " 
ECHO "/::\    /:::/  \:::\____\|:::|____|     |:::|    |/:::/__\:::\   \:::\____\" 
ECHO "\:::\  /:::/    \::/    / \:::\    \   /:::/    / \:::\   \:::\   \::/    /" 
ECHO " \:::\/:::/    / \/____/   \:::\    \ /:::/    /   \:::\   \:::\   \/____/ " 
ECHO "  \::::::/    /             \:::\    /:::/    /     \:::\   \:::\    \     " 
ECHO "   \::::/    /               \:::\__/:::/    /       \:::\   \:::\____\    " 
ECHO "    \::/    /                 \::::::::/    /         \:::\   \::/    /    " 
ECHO "     \/____/                   \::::::/    /           \:::\   \/____/     " 
ECHO "                                \::::/    /             \:::\    \         " 
ECHO "                                 \::/____/               \:::\____\        " 
ECHO "                                  ~~                      \::/    /        " 
ECHO "                                                           \/____/         " 
ECHO "                                                                           " 
ECHO "=-------------------------------------------------------------------------="
ECHO "                                   "
ECHO "[READER SCRIPT .........................]"
ECHO "                                   "

ren *.exe %COMPILER%

::
:: BASIC TESTS  ----------------------------------------------------------
::
:: Basic Tests (A12 - F23) - - - - - - - - - - - - - - - - - - - - - -

%COMPILER% %PARAM% %FILE1%.%EXTENSION%	> %FILE1%-%ASSIGNMENT%.%OUTPUT%	2> %FILE1%-%ASSIGNMENT%.%ERROR%
%COMPILER% %PARAM% %FILE2%.%EXTENSION%	> %FILE2%-%ASSIGNMENT%.%OUTPUT%	2> %FILE2%-%ASSIGNMENT%.%ERROR%
%COMPILER% %PARAM% %FILE3%.%EXTENSION%	> %FILE3%-%ASSIGNMENT%.%OUTPUT%	2> %FILE3%-%ASSIGNMENT%.%ERROR%
%COMPILER% %PARAM% %FILE4%.%EXTENSION%	> %FILE4%-%ASSIGNMENT%.%OUTPUT%	2> %FILE4%-%ASSIGNMENT%.%ERROR%
%COMPILER% %PARAM% %FILE5%.%EXTENSION%	> %FILE5%-%ASSIGNMENT%.%OUTPUT%	2> %FILE5%-%ASSIGNMENT%.%ERROR%
%COMPILER% %PARAM% %FILE6%.%EXTENSION%	> %FILE6%-%ASSIGNMENT%.%OUTPUT%	2> %FILE6%-%ASSIGNMENT%.%ERROR%

::
:: ADVANCED TESTS  -------------------------------------------------------
::
:: Advanced Tests (A12 - F23) - - - - - - - - -- - - - - - - - - - - -

%COMPILER% %PARAM% %FILE7%.%EXTENSION%	f 100 10	> %FILE7%-%ASSIGNMENT%-f-100-10.%OUTPUT%	2> %FILE7%-%ASSIGNMENT%-f-100-10.%ERROR%
%COMPILER% %PARAM% %FILE7%.%EXTENSION%	a 100 10	> %FILE7%-%ASSIGNMENT%-a-100-10.%OUTPUT%	2> %FILE7%-%ASSIGNMENT%-a-100-10.%ERROR%
%COMPILER% %PARAM% %FILE7%.%EXTENSION%	m 100 10	> %FILE7%-%ASSIGNMENT%-m-100-10.%OUTPUT%	2> %FILE7%-%ASSIGNMENT%-m-100-10.%ERROR%

:: SHOW OUTPUTS - - - - - - - - - - - - - - - - - - - - - - - - - - -
DIR *.OUT
DIR *.ERR

:: ---------------------------------------------------------------------
:: End of Tests (A12 - F23) --------------------------------------------
:: ---------------------------------------------------------------------
