#!usr/bin/bash

#Okay so this is technically "done" but really it isn't. Because I needd to intergrate it with the rest of the program, can't do that right now though cause I can't log the use of functions that don't actually exist yet. However, in theory, it shouldn't be hard. I onyl need to fuck with working directories. Make sure when the log functions are called they start and end in the right place, and that the correct variable/arguments (such as file names) are passed to the log functions.


today=`date +%Y-%m-%d.%H:%M:%S` # or whatever pattern you desire


#Done. Tested, working.
buildRepoLog() {
	echo "$today: Repository created by $USER" >> ./"$1"/logFile.txt
    cd ..
}

#This is checking out a file
beganEditFileLog() {
    echo "$today: $USER checked out file $1 for edits." >> ../logFile.txt
}

#Done. Not tested, because this only triggers if a file is both edited AND changed, and so far our program doesn't get that far (when I tried, I just for "It works finally" before the program stopped.)
#This is checking in a file
editFileLog() {
    pwd
    read -p "Please leave a comment for your edits: " comment
	#Need to make sure I'm in the right directory for this.
    echo "$today: $USER edited file $1 with comment: $comment" >> ../logFile.txt
}

createNewFileLog() {
    
    #This won't work instantly. I don't know what Directory I'm in. So, once we can get around to testing I can fix the inevitable directory issue.
    #Need to make sure I'm in the right directory for this.
	echo "$today: $USER created new file $1" >> ../logFile.txt
}

createNewDirecLog() {
    #Need to make sure I'm in the right directory for this.
    echo "$today: $USER created new directory $1" >> ../logFile.txt
}

deleteFileLog() {
    #Need to make sure I'm in the right directory for this.
    echo "$today: $USER deleted file $1" >> ../logFile.txt
}

deleteDirecLog() {
    #Need to make sure I'm in the right directory for this.
    echo "$today: $USER deleted directory $1" >> logFile.txt
}

moveFileLog() {
    # There was a space after $2
    # Unix doesn't like random spaces
    echo "$today: $USER moved file $1 to $2" >> ../logFile.txt # doesnt work   
}

# restoreArchFileLog() {
#     #Need to make sure I'm in the right directory for this.
#     echo "$today: $USER restored archived file $1" >> logFile.txt #probably not gonna have this but keep it anyway -Tadas
# }
