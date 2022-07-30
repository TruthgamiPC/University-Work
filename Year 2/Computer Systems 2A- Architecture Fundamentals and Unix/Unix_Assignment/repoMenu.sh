#!usr/bin/bash
source logging.sh

#Does what it says in the name - various validation checks for user input file name.
validateFileName(){
	while true; do
		echo -e "\nIf you would like to go back to the menu use the command: -q"
		read -p "Please enter a valid file name with its path: " file_name
		if [ -z "$file_name" ]; then
			echo "Please enter the name of a file that exists"
			continue
		fi

		if [[ "$file_name" == *".txt"* ]]; then
			echo "Invalid Input - please exclude | .txt | after the file name."
			continue
		fi

		if [[ "$file_name" == -* ]]; then
			if [ "$file_name" == "-q" ]; then
				file_name=""
				break
			fi
			echo "Invalid Input - please don't use | - | in the beginning."
			continue
		fi
        
        if [[ "$file_name" == *"."* ]]; then
			echo "Invalid Input - please don't use | . | in the name."
			continue
        fi

		if [ -f "$file_name.txt" ]; then
			echo "Valid file name"
			break
		else
			pwd
			echo "$file_name"
			echo "No file with that name found"
			continue
		fi
	done
}

repositoryMenu(){
	# This will be the menu that will allow the user to pick action inside the repository
	# Add file is being added now

	echo -e "\n==================================="
	pwd
	ls -R

	echo -e "\nSelect what you want to do."
	echo "1. View a file"									
	echo "2. Edit a file" 									
	echo "3. Create a new file"								
	echo "4. Create a new folder/directory for your file."	
	echo "5. Move a file"
	echo "6. Delete a file"									
	echo "7. Delete a folder/directory"						
	echo "8. Exit to main menu"								
	echo "9. Exit out of the program"						
}

reposMenuPick(){
	repo="${PWD##*/repositories/}"
	local input
	read -p "Enter the corresponding number for the operation you want to perform: " input
	case "$input" in

	#==================== NONE OF THE BACKUPS ARE TESTED CAN SOMEONE PLS DO THAT I CBA ANYMORE ====================#
	#STILL NEED DELETE REPO AND RENAME FILE
	1) echo "view_file"			#no need for backup STILL NEED TO CHANGE EDITOR TO SUBL WITHOUT WRITE PERMS
		view_file
		;;
	
	2) echo "edit_file"			#backup done
		edit_file
		;;

	3) echo "create_file"		#backup done
		create_file
		;;
		
	4) echo "create_directory"	#backup done
		create_directory
		;;

	5) echo "move_file"			#backup done
		moveFile
		;;
	
	6) echo "delete_file"		#backup done
		delete_file
		;;

	7) echo "delete_dir"		#backup done
        delete_dir
		;;
		
	8) return 0;;
	9) exit 0;;
	*) echo - "${RED}Error... 1 Second delay${STD}" && sleep 1
	esac
	return 1
}

callInMenu(){
	while true; do
		repositoryMenu
		if reposMenuPick; then
			break
		fi
	done
}

#method to view a file
view_file(){
	cd ./latest
	validateFileName
	if [ "$file_name" != "-q" ]; then
		less "$file_name.txt"
	fi
	cd ..
}

#method to create a directory within the repo
create_directory(){
	cd ./latest
	echo "----------------------------------------------"
	echo -e "Here are the current directories:\n"
	ls

	while true; do
		read -p "Enter a name for the directory ('-q' to go back to main menu): " newDirectory

		if [ -z "$newDirectory" ]; then
			echo "Please enter a name for the new directory"
			continue
		fi

		if [[ "$newDirectory" = -* ]]; then
			if [ "$newDirectory" = "-q" ]; then
				break
			fi
			echo "Invalid Input - please don't use | - | in the beginning."
			continue
		elif [[ "$newDirectory" == *"."* ]]; then
			echo "Invalid Input - please don't use | . | in the name."
			continue
		elif [ ! -d "$newDirectory" ]; then
			echo "Valid directory"
			backup_repo &
			if [ $(cat < ../../../toFunc) == "to_function" ]; then
				mkdir $newDirectory
				echo "repo_back" > ../../../toBackUp
			fi
			if [ $(cat < ../../../toFunc) == "back_done" ]; then
				createNewDirecLog "$newDirectory"
			fi
			ls
			break          
		else
			pwd
			echo "Please enter a valid directory name"
			continue
		fi
	done
	cd ..
}

#method to delete a file from the repo
delete_file(){
	cd ./latest
	validateFileName
	if [ "$file_name" != "-q" ]; then
		backup_repo &
		if [ $(cat < ../../../toFunc) == "to_function" ]; then
			rm "$file_name.txt"
			echo "del_back" > ../../../toBackUp
		fi
		if [ $(cat < ../../../toFunc) == "back_done" ]; then
			deleteFileLog "$file_name"
		fi
	fi
	cd ..
}

#method to delete a folder ffrom the repo
delete_dir(){
	cd ./latest
	pwd
	ls

	while true; do
		read -p "Search for a directory to delete ('-q' to go back to the menu): " DeletingDir

		if [ -z "$DeletingDir" ]; then
			echo "Please enter the name of the directory"
			continue
		fi

		if [[ "$DeletingDir" = -* ]]; then
			if [ "$DeletingDir" = "-q" ]; then
				break
			fi
			echo "Invalid Input - please don't use | - | in the beginning."
			continue
		elif [[ "$DeletingDir" == *"."* ]]; then
			echo "Invalid Input - please don't use | . | in the name."
			continue
		elif [ -d "$DeletingDir" ]; then
			backup_repo &
			if [ $(cat < ../../../toFunc) == "to_function" ]; then
				rm -rf $DeletingDir
				echo "repo_back" > ../../../toBackUp
			fi
			if [ $(cat < ../../../toFunc) == "back_done" ]; then
				deleteDirecLog "$DeletingDir"
			fi
			ls
			break           
		else
			pwd
			echo "Please enter a valid directory name"
			continue
		fi
	done
	cd ..
}

#method to create a file in the repo
create_file(){
	cd ./latest
	pwd
	while true; do
		echo -e "\nIf you would like to go back to the menu use the command: -q"
		read -p "Please enter a valid path with a valid file name: " new_file
		if [ -z "$new_file" ]; then
			echo "Please enter a non null directory"
			continue
		fi

		if [[ "$new_file" == *".txt"* ]]; then
			echo "Invalid Input - please exclude | .txt | after the file name."
			continue
		fi

		if [[ "$new_file" == -* ]]; then
			if [ "$new_file" == "-q" ]; then
				$new_file = ""
				break
			fi
			echo "Invalid Input - please don't use | - | in the beginning."
			continue
		fi

        if [[ "$new_file" == *"."* ]]; then
			echo "Invalid Input - please don't use | . | in the name."
			continue
        fi

		if [ ! -f "$new_file.txt" ]; then
			echo "Valid file name"
			backup_repo &
			if [ $(cat < ../../../toFunc) == "to_function" ]; then
            	touch "$new_file.txt"
				echo "repo_back" > ../../../toBackUp
			fi
			if [ $(cat < ../../../toFunc) == "back_done" ]; then
				createNewFileLog "$new_file"
			fi
            ls
			break
		else
			echo "That file already exists"
			continue
		fi
	done
	cd ..
}

#method that checks if a directory entry from the user is valid.
checkDir(){
	while true; do
		read -p "Search for a valid directory ('-q' to go back to the menu): " searchDir

		if [ -z $searchDir ]; then
			echo "Please enter the name of the directory"
			continue
		fi

		if [[ "$searchDir" == -* ]]; then
			if [ "$searchDir" == "-q" ]; then
				searchDir=""
				break
			fi
			echo "Invalid Input - please don't use | - | in the beginning."
			continue
		elif [[ "$searchDir" == *"."* ]]; then
			echo "Invalid Input - please don't use | . | in the name."
			continue
		elif [ -d "$searchDir" ]; then
			break        
		else
			pwd
			echo "Please enter a valid directory name"
			continue
		fi
	done
}

#method to move a file within the repo
moveFile() {
	
	cd ./latest

	#I'm doing stuff here.
	echo "Please select the file you want to move"
	validateFileName
	
	if [ -z "$file_name" ]; then
		cd ..
		return
	fi

	checkDir
	if [ -z "$searchDir" ]; then
		cd ..
		return
	fi
	

	backup_repo &
	if [ $(cat < ../../../toFunc) == "to_function" ]; then
		mv $file_name.txt ./$searchDir
		echo "repo_back" > ../../../toBackUp
	fi
	if [ $(cat < ../../../toFunc) == "back_done" ]; then
		moveFileLog "$file_name" "$searchDir"
	fi

	cd ..
}

#method that backs up the repo (automated.)
backup_repo(){
	pwd
	date=$(date +%Y-%m-%d.%H:%M:%S)
	cp -R -p ../latest ../archived/"$date"
	echo "to_function" > ../../../toFunc
	piped=$(cat < ../../../toBackUp)
	echo "$piped"
	if [ "$piped" == "edit_back" ]; then
		echo PIPED
		if [[ $(diff -Z -q ../archived/"$date"/"$1" "$1") != "" ]]; then
			tar -zcf ../archived/"$date".tar.gz ../archived/"$date" >&- 2>&-
			echo "back_done" > ../../../toFunc
		fi
	elif [ "$piped" == "repo_back" ]; then
		echo PIPED
		if [[ $(ls -R) != $(ls -R ../archived/"$date") ]]; then
			echo DIFF_STRUCT
			tar -zcf ../archived/"$date".tar.gz ../archived/"$date" >&- 2>&-
			echo "back_done" > ../../../toFunc
		fi
	elif [ "$piped" == "del_back" ]; then
		echo PIPED
		tar -zcf ../archived/"$date".tar.gz ../archived/"$date" >&- 2>&-
		echo "back_done" > ../../../toFunc
	fi
	rm -r ../archived/"$date"
}

#method that allows you to pick a file and open it in an editor. When saved allows you to comment. Comment done by logging.sh script and saved in the log file.
edit_file(){
	cd ./latest
	validateFileName
	if [ "$file_name" != "-q" ]; then
		backup_repo "$file_name.txt" &
		if [ $(cat < ../../../toFunc) == "to_function" ]; then
			if mv "$file_name.txt" "../editing/"; then
				# check out log. Not tested yet, but this once should work fine.
				beganEditFileLog "$file_name.txt"
				nano "../editing/${file_name##*/}.txt"
			fi
		fi
		if read -n 1 -s -r -p "Press any key to continue"; then
			if mv "../editing/${file_name##*/}.txt" "${file_name%/*}"; then
				echo "edit_back" > ../../../toBackUp
			fi
		fi
		if [ $(cat < ../../../toFunc) == "back_done" ]; then
			editFileLog "$file_name.txt"
		fi	
	fi
	cd ..
}




# -------------------------------------------
# =============The Shadow Realm==============
#    		Code that doesn't work,
#		was given up on or is deprecated
# -------------------------------------------

#Method to restore repo from the archives - WIP.
# restore_repo_latest(){
# 	cd ./archived
# 	ls
# 	echo -e "Above are the previous versions of the repository\nDate & time it was backed up, archived (tar), compress:\nYYYY-MM-DD.hh:mm:ss.tar.gz"
# 	echo -e "Restoring an archived version will archive the currently active one\nThis will also automatically check-in all files currently checked-out\nRegardless if they're saved or not"
# 	echo "Enter the date and time of the version you would like to restore"
# 	read -p "YYYY-MM-DD.hh:mm:ss " date
# 	if [ -f "$date".tar.gz ]; then
# 		backup_repo &
# 		if [ $(cat < ../../../toFunc) == "to_function" ]; then
# 			rm -rf ../latest
# 			mv "$date".tar.gz ../latest
# 			tar xzvf $date.tar.gz
# 			echo "del_back" > ../../../toBackUp
# 		fi
# 		if [ $(cat < ../../../toFunc) == "back_done" ]; then
# 			#log
# 		fi
# 	fi
# 	cd ..
# }

# restore_file(){
# 	while true; do
# 		echo "----------------------------------------------------------------------------------"
# 		ls ./archived
# 		echo "----------------------------------------------------------------------------------"
# 		echo "Please choose a file to restore."
# 		read -p "File to restore: " fileName
# 		newFileName=${fileName::-24}
# 		pwd
# 		fullFileName="$newFileName.txt"
# 		if fileDir=${test -f ./latest/*/"$fullFileName"}; then
# 			today=$(date +%Y-%m-%d.%H:%M:%S) # or whatever pattern you desire
# 			newFileName="$newFileName-$today.txt"
# 			echo $fileDir
# 			echo $newFileName
# 			cp "$fileDir" ./archived/"$newFileName"
# 		fi
# 		#echo "$newFileName" #replace echo with mv after moving latest succeeds or doesnt exist
# 		break
# 	done
# }

# Edit a file, automatically saves the file when exiting with ctrl + X
	# if subl "$file_name.txt"; then              #FILE IS OPENED HERE IN A TEXT EDITOR
	# 	today=$(date +%Y-%m-%d.%H:%M:%S) # or whatever pattern you desire
	# 	today="-$today"
	# 	full_file_name=${file_name##*/}
	# 	path=${file_name%/*}
	# 	full_file_name="$full_file_name$today$path.txt"
	# 	cp "$file_name.txt" ../archived/"$full_file_name"
	# 	read -n 1 -s -r -p "Press any key to continue"          # THIS IS USED TO LET THE USER EDIT THE FILE OR w/e then save it
	# 	if [ ! $(diff -Z -q "$file_name.txt" ../archived/"$full_file_name") ]; then #check if file was not changed
	# 		echo DID_NOT_BACKUP         # if the file wasn't changed this follows
	# 		rm ../archived/"$full_file_name"        #deletes backup
	# 	else
	# 		editFileLog "$file_name" #file has been changed, get's logged.
	# 	fi
	# fi


#log(){
 #   echo $user >> log.txt
  #  echo date >> log.txt
   # echo file >> log.txt
	#diff file fileOld >> log.txt
#}

		# if [[ "$file_name" == "*/*" ]]; then
		#     echo "Invalid Input - please don't use | / | in the name."
		#     continue
		# fi

# Edit a file, automatically saves the file when exiting with ctrl + X
    # if subl "$file_name.txt"; then              #FILE IS OPENED HERE IN A TEXT EDITOR
    # 	today=$(date +%Y-%m-%d.%H:%M:%S) # or whatever pattern you desire
    # 	today="-$today"
    # 	full_file_name=${file_name##*/}
    # 	path=${file_name%/*}
    # 	full_file_name="$full_file_name$today$path.txt"
    # 	cp "$file_name.txt" ../archived/"$full_file_name"
    # 	read -n 1 -s -r -p "Press any key to continue"          # THIS IS USED TO LET THE USER EDIT THE FILE OR w/e then save it
    # 	if [ ! $(diff -Z -q "$file_name.txt" ../archived/"$full_file_name") ]; then #check if file was not changed
    # 		echo DID_NOT_BACKUP         # if the file wasn't changed this follows
    # 		rm ../archived/"$full_file_name"        #deletes backup
    # 	else
    # 		editFileLog "$file_name" #file has been changed, get's logged.
    # 	fi
    # fi


		# while [ ! -d "$movePath" ]; do
  	# 	read -p "That was not a valid path, please enter a valid path: " movePath
	# done