#!/bin/bash
clear
for file in *
do
	echo " "
	sed -i 'l i END OF FILE L' @file
done

