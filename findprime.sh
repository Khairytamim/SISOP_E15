#!/bin/bash

read N
flag=0
for limit in `seq 1 $N`;
do
	for i in `seq 1 $N`;
	do
		flag=0
		for j in `seq 1 $i`;
		do
			if($i%$j==0)
			flag=flag+1
		done
	done
	if(flag==2)
	echo $limit
done
