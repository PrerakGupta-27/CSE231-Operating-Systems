#!/bin/bash

function add(){
    
    ans=0
    for i in "$@"
    do
        if [[ "$i" == "$Add" ]];
        then
            continue
        fi
        ans=`expr $ans + $i`
    done

    echo "ans is : $ans"

}

function sub(){
    
    for i in "$@"
    do  
        if [[ "$i" == "$Sub" ]];
        then
            continue
        fi
        ans=`expr $ans - $i`
    done
    
    echo "ans is : $ans"
}

function mul(){
    
    ans=1
    for i in "$@"
    do
        if [[ "$i" == "$Mul" ]];
        then
            continue
        fi
        ans="$(( $ans * $i ))"
    done

    echo "ans is : $ans"
}

function div(){
 
    for i in "$@"
    do  
        if [[ "$i" == "$Div" ]];
        then
            continue
        fi
        
        if [[ $i != 0 ]];
        then
            ans="$(( $ans / $i ))"
            
        else
            echo "cannot divide by 0"
            exit 1
        fi
    done
    echo "ans is : $ans"
}

function expo(){
    c=1
    for i in "$@"
    do  
        
        if [[ "$i" == "$Exp" || $c == 2 ]];
        then
            c="$(( $c + 1 ))"
            continue
        fi

        ans="$(( $ans ** $i ))"
    done
    echo "ans is : $ans"
}
ans=0

Add="add"
Sub="sub"
Mul="mul"
Div="div"
Exp="exp"

if [[ "$1" == "$Add" ]];
then
    add $@
    
elif [[ "$1" == "$Sub" ]];
then 
    ans="$(( $2 * 2 ))"
    sub $@
elif [[ "$1" == "$Mul" ]];
then 
    mul $@
elif [[ "$1" == "$Div" ]];
then
    ans="$(( $2 * $2 ))"
    div $@
elif [[ "$1" == "$Exp" ]];
then
    ans=$2
    expo $@
else
    echo "operation name not valid"
fi
