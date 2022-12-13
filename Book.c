#! /bin/bash

create(){
	echo "Enter name of the address book"
	read ab
	if [ -e $ab ]
	then
		echo "address book is already present"
	else 
		touch 	$ab
		echo "address book is created"
	fi	


}

display(){
	echo "enter name of the address book"
	read ab
	if [ -e $ab ]
	then 
		 cat $ab
	else 
		echo "address book not exist"
	fi		


}

insert(){
	echo "enter name of the file"
	read ab
	opt="1"
	while [ $opt -ne "0" ]
	do
		echo "enter your id"
		read id
		echo "enter your name"
		read name
		echo "enter your address"
		read address
		echo "$id $name $address" >> $ab
		echo "enter 0 for exit and 1 for contnue inserting"
		read opt
	done

}

search()
{
	echo "enter name of the file"
	read ab
	echo "enter name to serach record"
	read name
	#result=$(grep -h $name $ab)
	result=$(grep -h $name $ab)
	if [ "$result" != 0 ]
	then
		echo $result
	else 
		echo record not found
	fi	

}

delete(){
	echo enter name of file
	read ab
	echo enter name of person
	read name
	grep -v $name $ab >>temp
	rm $ab
	mv temp $ab

}

modify(){
	echo enter file name
	read ab
	echo enter name you want to modify
	read name
	echo enter new name
	read newname
	
	sed s/"$name"/"$newname"/g $ab
	

}


while [ true ]
do
echo "Enter Your Choice"
echo "1) create "
echo "2) display "
echo "3) insert "
echo "4) search "
echo "5) delete "
echo "6) modify "
echo "7) exit "
read ch
	case $ch in
		1) create ;;
		2) display ;;
		3) insert ;;
		4) search ;;
		5) delete ;;
		6) modify ;;
		7) exit ;;
		*) echo "Wrong choice" ;;
	esac	

#this is comment


done
