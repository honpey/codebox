#!/bin/bash
awk '
	BEGIN {
		lineMax=0;
		del=""
	}
	{
		lineMax=NF;
		if (NR>1)
			del=" "
		for (i=1; i<=NF; i++) {
			line[i]=(line[i]""del""$i);
		}
			
	}
	END {
		for (i=1; i<=lineMax; i++) {
			print line[i]
		}
	}

' file.txt
