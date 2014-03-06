#!/bin/bash
#better have pulled first so pull
#and usage should give a check for commit name :)
if [ -z "$1" ]
   then
	echo "usage: Git {commit message}" && exit
fi



git add -A
git commit -m "$1"
git push origin master
