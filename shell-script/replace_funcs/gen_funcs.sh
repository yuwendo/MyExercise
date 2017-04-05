#!/bin/bash

###
#	File: gen_funcs.sh
#	Author: Yuwen
#	Date: 2017/03/30
#	Description:
#		generate new functions and replace the string from .h to .c
#		from testxxxxxx to genCXXXXX
###
genCpath="$(pwd)/genC.c"
headers=`ls $(pwd)/example_headers`
headerPath="$(pwd)/example_headers"

GetHeadersDeclartion () {
	for header in $headers
	do
		echo "#include \"./example_headers/$header\"" >> $genCpath
		
		count=0
		flag0=0
		cat $headerPath/$header | tr -d "\r" | awk '{
			if ( $1 == "#ifdef" || $1 == "#if" ) {
				if ( $2 == "0")
				{	flag0 = 1 }
				else  {
					count = count + 1
					print $1, $NF
				}
			}	 
			else if ( $1 == "#endif" && ( count >= 1 || flag0 == 1 )) {
				if ( flag0 == 1 )
				{	flag0 = 0 }
				else {
					count = count - 1
					print $1
				}
			}
			else if ( $1 == "#include" && flag0 != 1 )
			{	print $1, $NF }
		}' >> $genCpath
	done
}

GenerateFunctions () {
	if [ -e ./tmp ]; then
		rm -f ./tmp
	fi

	for header in $headers
	do
		flag=0
		cat $headerPath/$header | tr -d "\r" | sed '/typedef/, /}/d' | sed '/^\/\*.*.\*\/$/d' | sed '/^\/\//d' | sed '/^\/\*/, /\*\//d' | sed '/^#if 0/, /#endif$/d' | sed '/^#include/d' | awk '{ 
		if ($1 == "#ifdef") {
			flag = flag + 1
			print 
		} else if ($1 == "#endif" && flag>=1) {
			flag = flag - 1
			print
		} else if (match($2, "test")){
			print
		}
	}' | sed '/^ /d' >> ./tmp
	done

	index=0
	count=0
	flag=0
	while read line; do
		tmpstr=`echo "$line" | head -c 6`
		if [ "$tmpstr" = "#ifdef" ]; then
			count=0
			flag=1
		fi	
		if [ "$tmpstr" = "#endif" ] && [ $flag -eq 1 ]; then	
			flag=0
			if [ $count -eq 1 ]; then
				index=`expr $index - 1`
				continue
			fi
		fi
		funcs[index]=`echo $line | sed -e 's/;.*//g'`
		index=`expr $index + 1`
		count=`expr $count + 1`
	done < ./tmp

	echo "Generate function prototypes......"
	echo -e "\n/* function declartion */" >> $genCpath
	for ((i=0; i<${#funcs[@]}; i++))
	do
		tmpstr=`echo "${funcs[$i]}" | head -c 6`
		if [ "$tmpstr" = "#ifdef" ] || [ "$tmpstr" = "#endif" ]; then
			echo "${funcs[$i]}" >> $genCpath 
		else
			echo "${funcs[$i]};"  | sed -e 's/ test/ genC/g' >> $genCpath 
		fi
	done

	echo "Generate new function entities......"
	echo -e "\n/* function entities */" >> $genCpath
	for ((i=0; i<${#funcs[@]}; i++))
	do
		tmpstr=`echo "${funcs[$i]}" | head -c 3`
		if [ "$tmpstr" = "#if" ] || [ "$tmpstr" = "#en" ]; then
			echo "${funcs[$i]}" >> $genCpath
			continue
		fi

		echo "${funcs[$i]}" | sed -e 's/ test/ genC/g' >> $genCpath 
		echo "{ " >> $genCpath 
			if [ "$tmpstr" = "voi" ]; then
				echo -e "\treturn;" >> $genCpath
			else
				echo -e "\treturn (0);" >> $genCpath
			fi
		echo -e  "}\n" >> $genCpath
	done
	rm -f ./tmp
}

##--------- Start here ---------##
##### check genC.c is existed or not.
if [ -e $genCpath ] 
then
	rm -f $genCpath
fi

today=`date -R`
echo "/*
 * File: genC.c
 * Author: Yuwen
 * Generated Date: $today
 * Description: 
 *     This is an auto-generated file.
 *     It will be lost when edited this file.
 *     Replace testXXXX to genCxxxxx
 */
/********** Include **********/
#include <stdio.h>
#include <stdlib.h>" >> $genCpath

## Getting Headers
echo "Get headers......"
GetHeadersDeclartion

## Genarating functions
echo "Start replacing functions......"
GenerateFunctions

echo "int main(void) 
{
	printf(\"This is a test shell-script\n\");
	return (0);
}" >> $genCpath
