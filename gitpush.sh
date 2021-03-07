#!/bin/bash
cd /home/wgt/Github/2021study
time1 = $(date)
echo $time1 >> gitHistory.log
git status >> gitHistory.log
git add .
git commit -m ""$1""
git push
