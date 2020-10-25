# error=$?
# if [ $error -eq 0 ]
# then
#    echo "$file1 and $file2 are the same file"
# elif [ $error -eq 1 ]
# then
#    echo "$file1 and $file2 differ"
# else
#    echo "There was something wrong with the diff command"
# fi

# function diff

echo "Start field test"
./a.out >> rez.txt
diff $file1 file2 > /dev/null 2>&1

# clang-format 
# clang-tidy
