#!usr/bin/bash

# This bash file is used to generate a completely new repository with its key elemnts
# the key elemets are: a password to the repository, several directories and a log file which records changes to the repository
buildRepo(){
    cd repositories
    pwd
    # Endless while loop, interrupted by a break command
    while true; do
        echo -e "\nHere are the current repositories:"
        ls
        echo "If you would like to go back to the menu use the command: -q"
        read -p "Enter the name of the repository you would like to add: " name
        
        # Checks if the input from the user is empty or not
        if [ -z "$name" ]; then
            echo "Please enter a valid name for the repository"
            continue
        fi

        # Checks if the input by the user contains a / , if yes it will restart the loop asking for an input again
        if [[ "$name" == *"/"* ]]; then
            echo "Invalid Input - please don't use | / | in the name."
            continue
        fi
        
        # Checks if the user started the input with the character "-", if yes the program will restart the loop as that would be an invalid name with our program
        if [[ "$name" = -* ]]; then
            if [ "$name" = "-q" ]; then     # If the user had entered -q on the other hand it will automatically exit the loop and return to main menu
                cd .. 
                break
            fi
            echo "Invalid Input - please don't use | - | in the beginning."
            continue
        fi

        # Checks if the input the user provided is matching another repository's name, if yes would call it as invalid
        if [ -d ./"$name" ]; then
            echo "Please enter a directory name that doesn't exist yet"
            continue
        else                                # In case the user enters a input that is correct by our program, the process continues by creating the repo and its key components inside it
            mkdir "$name"
            mkdir "$name/latest"
            mkdir "$name/archived"
            mkdir "$name/editing"

            # Asks the user ot enter a password, the password can be anything as it will be directly stored for later use when trying to enter the repository
            echo "You have succesfully created a new directory. Please create a password for it."
            read -p "New Password: " password
            read -p "Confirm Password: " passwordCheck

            # Checks if the password which were just entered match
            while [[ "$password" != "$passwordCheck" ]]; do
                echo "Your passwords don't match. Please try again"
                read -p "New Password:" password
                read -p "Confirm Password:" passwordCheck
            done
            
            pwd
            echo "$password" > ./"$name"/passFile.txt       # Saves the password in a file in the repository
            buildRepoLog "$name"                            # Logs the creation of the repository as successful
            break
        fi
    done
}