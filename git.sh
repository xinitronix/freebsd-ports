#!/bin/sh
dir=$(dirname "$(realpath $0)")
cd $dir
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
git add --all
git add .
git commit -n
#git push https://github.com/xinitronix/mate.git
git push ssh://git@github.com/xinitronix/freebsd-ports.git

