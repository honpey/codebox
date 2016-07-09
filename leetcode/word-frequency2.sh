#!/bin/bash
egrep -o "\b[[:alpha:]]+\b" words.txt | awk '{count[$0]++} END{for(ind in count) printf("%s %d\n",ind,count[ind])}' | sort -n -r -k 2
