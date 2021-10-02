#!/bin/sh

for var in 1 2 3 4 5 6 7 8 9 10
do
   echo jstack instance $var
   jstack $1 > curvemanager_jstack_$var.txt
   sleep 300s
done
