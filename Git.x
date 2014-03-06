#!/bin/bash
#better have pulled first so pull
#and usage should give a check for commit name :)
git add -A
git commit -m "$1"
git push origin master
