#!/bin/sh

# -------------------------------- COLORS --------------------------------
RESET="\033[0m"
BLUE="\033[0;34m"
GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[0;33m"
MAGENTA="\033[0;35m"
CYAN="\033[0;36m"

# -------------------------------- FUNCTIONS --------------------------------
result()
{
	if [ $? -eq 0 ]; then
		printf "✅"
	else
		printf "❌"
	fi
	sleep 0.1
}

# -------------------------------- VARIABLES --------------------------------
command="sudo ./ft_ping"
command_bonus="sudo ./ft_ping_bonus"
website="google.com"
localhost="127.0.0.1"

# -------------------------------- COMPILING --------------------------------
printf $BLUE"Compiling program..."$RESET
make re > /dev/null 2>&1; result
make bonus > /dev/null 2>&1; result
echo ""

# -------------------------------- MAIN TESTS --------------------------------
printf $GREEN"Main tests:"$RESET
echo ""
printf $MAGENTA"Parsing tests:"$RESET
echo ""

# Succeeding tests
printf "Succeeding tests:"
$command $website -c 1 > /dev/null 2>&1; result
$command $localhost -c 1 > /dev/null 2>&1; result
$command -c 1 $website > /dev/null 2>&1; result
$command -c 1 $localhost > /dev/null 2>&1; result
echo ""

# Failing tests
printf "Failing tests:"
$command $website -c 1 $website > /dev/null 2>&1; result
$command $localhost -c 1 $website > /dev/null 2>&1; result
$command $website -c 1 $localhost > /dev/null 2>&1; result

# -------------------------------- BONUS TESTS --------------------------------
echo ""
printf $YELLOW"Bonus tests:"$RESET
# Succeeding tests
echo ""
printf "Succeeding tests:"
$command_bonus $website -c 1 > /dev/null 2>&1; result
$command_bonus $localhost -c 1 > /dev/null 2>&1; result
$command_bonus -c 1 $website > /dev/null 2>&1; result
$command_bonus -c 1 $localhost > /dev/null 2>&1; result

echo ""
# Failing tests
printf "Failing tests:"
$command_bonus $website -c 1 $website > /dev/null 2>&1; result
$command_bonus $localhost -c 1 $website > /dev/null 2>&1; result
$command_bonus $website -c 1 $localhost > /dev/null 2>&1; result








echo ""