#!/bin/bash

# result percents
percs=(90 95 99)

function round()
{
	echo $1
	((($1 + 500) / 1000))
}

function percentile()
{
	#cat /var/log/httpd/*.log | awk -F ' ' '{print NF}' >> time.log
	declare -A stat
	declare -A count=0
	for line in $(cat time.log)
	do
		#echo $line
		stat[count++]=$((line))
	done

	#echo ${stat[@]}
	echo ${#percs[@]}
    echo $count
	for ((i=0; i<${#percs[@]}; ++i))
	do
        #echo ${percs[i]}
        #percent=${percs[i]}
		if [ ${percs[i]} -le 0 ]
        then
          ehco "0%	never"
		elif [ ${percs[i]} -ge 100 ]
        then
          echo "100% of requests return a response in $(round($stat[$count-1])) ms"
		else
          #echo "------ ${stat[$count * ${percs[i]} / 1000]} ------"
          result=${stat[$count * ${percs[i]} / 1000]}
          #echo $result
          echo "${percs[i]}% of requests return a response in $(round($result)) ms"
		fi
	done
}

# run
percentile
