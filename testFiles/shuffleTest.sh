#!/bin/bash

#for i in `seq 1 10`;
#do
#	./Blackjack > "results$i.txt"
#done

for j in `seq 1 10`;
do
	for k in `seq 1 10`;
	do
		if [ $j -ne $k ]; then
			diff results$j.txt results$k.txt | grep '>' | wc -l
		fi
	done
done
