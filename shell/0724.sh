#!/bin/bash

# awk 'BEGIN{RS="]";count=0;}{gsub("\n","",$0); print substr($0,2,length($0));}` file

sed '/\[/{:a;N;/\n\[/!{s/\n//;ta};P;D}'

sed '/\[/{:a;N;/\n\[/!{s/\n//;ta};P;D}'

sed '/\[/{:a;N;/\n\[/!{s/\n\[//g;ta}};P;D;'

sed '/^\[/{:a;N;/^\[/!{s/\n\[//g;ta}};P;D;'

