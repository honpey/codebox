#!/bin/bash

# awk 'BEGIN{RS="]";count=0;}{gsub("\n","",$0); print substr($0,2,length($0));}` file
