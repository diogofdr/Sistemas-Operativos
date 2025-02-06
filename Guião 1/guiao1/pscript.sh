#!/bin/bash

for ((i = 1; i <= $1; i++))
do
    IDADE=$(((RANDOM % 100)+1))
    # echo "./guiao1 -i Pessoa${i} $IDADE"
    
    ./guiao1 -i Pessoa${i} $IDADE

done
