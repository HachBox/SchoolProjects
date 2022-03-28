#!bin/bash

clear
case $2 in
	-l) echo -n "Leasing a $1 "
		months=`expr $3`
		price=400
		ttotal1=`expr $price \* 2`
		ttotal2=`expr $price \* 3`
		tproduct1=`expr $ttotal1 / 100`
		tproduct2=`expr $ttotal2 / 100`
		if (( $3 <= 24 ))
		then
			echo "for $3 months at \$400 per month with 2 percent interest will end up costing: `expr $months \* $price + $tproduct1`"
		else
			echo "for $3 months at \$400 per month with 3 percent interest will end up costing: `expr $months \* $price + $tproduct2`"
		fi;;
	-b) echo -n "Buying a $1 "
		fee=500
		sPrice=`expr $fee + $3`
		tax=`expr $sPrice \* 8` 
		taxtax=`expr $tax / 100`
		echo " at a price of $3 including set up fee (\$500) and sales tax (8 percent) will end up totaling: `expr $taxtax + $sPrice`";;

	*) echo "The only valid options are -b to buy and -l to lease ";;
esac
