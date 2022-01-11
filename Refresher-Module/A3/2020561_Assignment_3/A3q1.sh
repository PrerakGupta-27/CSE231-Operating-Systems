#! /bin/bash


#enter date in dd mm yyyy format 

if [[ $1 >0 && $2 <13 && $3 >0 ]]; then
    #statements
    echo "calender for the month is"
    cal $2 $3
else
    echo "wrong input"
fi