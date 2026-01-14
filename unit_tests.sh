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
	local to_execute=$1
	local should_fail=${2:-0}

	eval "$to_execute > /dev/null 2>&1";
	local exit_code=$?

	local normalized_exit_code=0;
	if [ $exit_code -ne 0 ]; then
		normalized_exit_code=1;
	fi

	local final_result=$(($normalized_exit_code ^ $should_fail))

	if [ $final_result -eq 0 ]; then
		printf "✅"
	else
		printf "\n❌"
		printf " -- command executed: %s\n" "$to_execute";
	fi
	sleep 0.05
}

# -------------------------------- VARIABLES --------------------------------
command="sudo ./ft_ping"
command_bonus="sudo ./ft_ping_bonus"
website="google.com"
localhost="127.0.0.1"

# -------------------------------- COMPILING --------------------------------
printf $BLUE"Compiling program..."$RESET
result "make re"
result "make bonus"
echo ""

# -------------------------------- MAIN TESTS --------------------------------
printf $GREEN"Main tests:"$RESET
echo ""
printf $MAGENTA"Parsing tests:"$RESET
echo ""

# Succeeding tests
printf "Succeeding tests:"
result "$command $website -c 1 > /dev/null 2>&1"
result "$command $localhost -c 1 > /dev/null 2>&1"
result "$command -c 1 $website > /dev/null 2>&1"
result "$command -c 1 $localhost > /dev/null 2>&1"
echo ""

# Failing tests
printf "Failing tests:"
result "$command $website -c 1 $website > /dev/null 2>&1" 1
result "$command $localhost -c 1 $website > /dev/null 2>&1" 1
result "$command $website -c 1 $localhost > /dev/null 2>&1" 1

# -------------------------------- BONUS TESTS --------------------------------
echo ""
printf $YELLOW"Bonus tests:"$RESET
# Succeeding tests
echo ""
printf "Succeeding tests:"
result "$command_bonus $website -c 1 > /dev/null 2>&1"
result "$command_bonus $localhost -c 1 > /dev/null 2>&1"
result "$command_bonus -c 1 $website > /dev/null 2>&1"
result "$command_bonus -c 1 $localhost > /dev/null 2>&1"

echo ""
# Failing tests
printf "Failing tests:"
result "$command_bonus $website -c 1 $website > /dev/null 2>&1" 1
result "$command_bonus $localhost -c 1 $website > /dev/null 2>&1" 1
result "$command_bonus $website -c 1 $localhost > /dev/null 2>&1" 1








echo ""