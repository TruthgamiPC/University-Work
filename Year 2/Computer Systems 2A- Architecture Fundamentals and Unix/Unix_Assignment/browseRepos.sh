#!usr/bin/bash

# Single source to bash file which's functions are called from the this bash
source repoMenu.sh

# main function of this script file, works as a while loop controls the user's input asking for a valid repository name
browseRepos(){
    while true; do
        # Display the repositories to the user
        echo "----------------------------------------------"
        echo -e "Here are the current repositories:\n"
        # Conditional statement which runs within the "repositories" directory
        if cd ./repositories; then
            ls && echo
            if select_repo; then
                break
            fi
        else
            break
        fi
    done
    return 0
}

select_repo(){
    # Here the user is asked for an input which should be the name of a repository, or the command "-q" which will exit to main menu
    echo "----------------------------------------------"
    read -p "Enter name of the repository to view/edit ('-q' to go back to main menu): " repo
    if [ "$repo" == "-q" ]; then
        cd ..
        return 0


    elif cd ./"$repo" 2>> ../errors; then

        # In this part of the code, the program will ask the user for a password, the uesr can't pull back and has to enter two matching password, entering nothing is valid as well
        filename="passFile.txt"
            while read -r line; do
                passwordCheck="$line"
            done < "$filename"


        read -p "Please enter the password for this repo: " passwordTry

        if [[ "$passwordTry" == "$passwordCheck" ]] ; then
            echo "SUCCESS"
            while true; do
                if callInMenu; then
                    break
                fi
            done
            cd ../..
            return 0
        else
            echo "FAIL"
            cd ../..
            return 0;
        fi
    else
        clear
        echo "Please enter a valid repository name" && cd ..
        return 1
    fi
}


# -------------------------------------------
# =============The Shadow Realm==============
#    		Code that doesn't work,
#		was given up on or is deprecated
# -------------------------------------------

# in_latest_repo(){
#     while true; do
#         if cd ./latest; then
#             echo "=============================================="
#             echo "Currently in: ${PWD##*/repositories/}"
#             echo "----------------------------------------------"
#             if [ -d "$(./*)" ]; then
#                 echo "DIR HERE"
#             fi
#             cd ..
#         fi
#         break
#     done
# }

# in_archived_repo(){
#     while true; do
#         if cd ./archived; then
#             echo "=============================================="
#             echo "Currently in: ${PWD##*/repositories/}"
#             echo "----------------------------------------------"
#             cd ..
#         fi
#         break
#     done
# }

# select_version(){
#     clear
#     echo "-------------------------------------------------------------"
#     echo "[ $repo ]: What would you like to do next? (1-3)"
#     echo "1. Edit a file in the repository"
#     echo "2. View archived old versions of files and/or restore them"
#     echo -e "3. Go back to main menu\n"
#     read -p "Choice: " choice
#     case $choice in
#         1) in_latest_repo
#             cd ..
#             return 0;;
#         2) in_archived_repo
#             cd ..
#             return 0;;
#         3) cd ..
#             return 0;;
#         *) clear
#             return 1
#     esac
# }