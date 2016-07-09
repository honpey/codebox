#!/bin/bash

pos=0
count[$pos]="hello"
count[$pos]=`echo ""`
let pos++
count[$pos]=1
let pos++
count[$pos]=2

echo ${count[*]}
