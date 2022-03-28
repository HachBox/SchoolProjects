BEGIN {
print "           ABC Computing "
print "       2017 Sales Associate "
printf ("%-10s %10s %20s \n", "Name", "Position", "Sales Amount")
print "============================================="
FS = ":"
}

NF == 4{
	pIDA[$1] = $4
}

NF == 3{
	assNA[$1] = $2
	assPA[$1] = $3
	assIDA[$1] = $1
}

NF == 5{
	if ( $4 ~ /2017/ ) {
		sSA[$5] += pIDA[$2] * $3
	}
}

END {
	for ( x in assIDA )
	{
		printf("%-20s %20s %20.2d \n", assNA[x], assPA[x], sSA[x])
		printf("%10s %-20s %-20s \n", assIDA[x], assNA[x], sSA[x]) | "sort -nrk4"
	}
	print ""
	print " Sorted Sales List"
}
