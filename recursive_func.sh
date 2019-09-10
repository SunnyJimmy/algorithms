#! /bin/sh

#this script is used for listing all files and directories under current dir

list_one_dir()
{
    local level=$2 #needed add local key word, as variable in shell is global in defalt
    local name=$1


    for((i=0; i<$level*4; i++));do
        echo -n " "
    done
    echo "`basename $name`"


    local next_level=$(($level + 1))
    sub_files=`ls $name`
    for file in $sub_files;do
        if [ -d "$name/$file" ];then
            list_one_dir "$name/$file" $next_level
        else
            for((i=0; i<$next_level*4; i++));do
                echo -n " "
            done
            echo "$file"
        fi
    done
}


list_one_dir . 0
