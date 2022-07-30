#!usr/bin/bash

# Two sources to bash files which's functions are called from the menu
source browseRepos.sh
source addRepo.sh

# Function which displays the path to the directory and a menu to the user
interf(){
    clear
    echo -e "\n#==================== Menu ====================#"
    echo "1. Browse repositories"
    echo "2. Create a new repository"
    echo "3. Delete a repository (no recovery)"
    echo "4. Exit the program"
    echo "#==============================================#"
}

# A function which reads a user input and after that executes a command based on the user's input
menu_pick(){
    local input
    read -p "Enter the corresponding number for the operation you want to perform: " input
    case "$input" in
    1) browseRepos     # Call to a function in browseRepos.sh ( the function has the same name as the .sh file)
        ;;
        #echo "browseRepo - call"
        #clear
        
    2)  buildRepo       # call to a function in addRepo.sh
        ;;
        #echo "addRepo - call"
       
    3)  cd repositories
        # A while loop which is present in our program to check if a specific user input is correct.
        # This loops until a user inputs correctly or leaves by inputting "-q"
        while true; do            
            ls
            read -p "Enter the name of the repository you wish to delete ('-q' to go back to the menu): " delRepo

            if [ -z "$delRepo" ]; then
                echo "Please enter the name of the repository"
                continue
            fi

            if [[ "$delRepo" = -* ]]; then
                if [ "$delRepo" = "-q" ]; then
                    cd ..
                    break
                fi
                echo "Invalid Input - please don't use | - | in the beginning."
                continue
            elif [[ "$delRepo" == *"."* ]]; then
                echo "Invalid Input - please don't use | . | in the name."
                continue
            elif [ -d "$delRepo" ]; then
                rm -rf $delRepo   
                cd ..
                break      
            else
                echo "Please enter a valid Repository name"
                continue
            fi
	    done
    ;;
    
    4) exit             # Exits the program
        ;;
    *) echo - "${RED}Error... 1 Second delay${STD}" && sleep 1
    esac
}

# The main function of our program, everything is started from here
main(){
    while true
    do  
        interf      # A call to the interf function in mainmenu.sh
        menu_pick   # A call to the menu_pick function in mainmenu.sh
    done
}

# Call to 
main