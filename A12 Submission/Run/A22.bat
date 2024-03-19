:: ---------------------------------------------------------------------
:: COMPILERS COURSE - SCRIPT                                           -
:: SCRIPT A22 - CST8152 - Fall 2023                                    -
:: ---------------------------------------------------------------------

CLS
SET COMPILER=Joe.exe

SET FILE1=INPUT0_Empty
SET FILE2=INPUT1_Hello
SET FILE3=INPUT2_Var
SET FILE4=INPUT3_Km
SET FILE5=INPUT4_Magic

SET ASSIGNMENT=A22
SET EXTENSION=joe
SET OUTPUT=out
SET ERROR=err

SET PARAM=s

:: ---------------------------------------------------------------------
:: Begin of Tests (A22 - F23) ------------------------------------------
:: ---------------------------------------------------------------------

@echo off

ECHO "=---------------------------------------------------------------------------="
ECHO "|                   COMPILERS - ALGONQUIN COLLEGE (W24)                     |"
ECHO "=---------------------------------------------------------------------------="
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
ECHO "                                                                        "
ECHO "=----------------------------------------------------------------------------="
ECHO "                                   "
ECHO "[Scanner SCRIPT .........................]"
ECHO "                                   "

ren *.exe %COMPILER%

::
:: BASIC TESTS  ----------------------------------------------------------
::
:: Basic Tests (A22 - F23) - - - - - - - - - - - - - - - - - - - - - -

%COMPILER% %PARAM% %FILE1%.%EXTENSION%	> %FILE1%-%ASSIGNMENT%.%OUTPUT%	2> %FILE1%-%ASSIGNMENT%.%ERROR%
%COMPILER% %PARAM% %FILE2%.%EXTENSION%	> %FILE2%-%ASSIGNMENT%.%OUTPUT%	2> %FILE2%-%ASSIGNMENT%.%ERROR%
%COMPILER% %PARAM% %FILE3%.%EXTENSION%	> %FILE3%-%ASSIGNMENT%.%OUTPUT%	2> %FILE3%-%ASSIGNMENT%.%ERROR%
%COMPILER% %PARAM% %FILE4%.%EXTENSION%	> %FILE4%-%ASSIGNMENT%.%OUTPUT%	2> %FILE4%-%ASSIGNMENT%.%ERROR%
%COMPILER% %PARAM% %FILE5%.%EXTENSION%	> %FILE5%-%ASSIGNMENT%.%OUTPUT%	2> %FILE5%-%ASSIGNMENT%.%ERROR%


:: SHOW OUTPUTS - - - - - - - - - - - - - - - - - - - - - - - - - - -
DIR *.OUT
DIR *.ERR

:: ---------------------------------------------------------------------
:: End of Tests (A22 - F23) --------------------------------------------
:: ---------------------------------------------------------------------
