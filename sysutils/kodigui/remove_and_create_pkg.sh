#!/bin/sh

REPO=All15
PKG=$(ls $HOME/2TB/$REPO | grep KodiGui)

doas rm $HOME/2TB/$REPO/$PKG
sshpass -p 639639 ssh pi@192.168.8.45 "rm ~/$REPO/$PKG"
cd $HOME/2TB/$REPO/
doas pkg create KodiGui
cd -
doas pkg repo /ntfs-2TB/$REPO

ncftpput  -R -z -r 10 -v -u "pi" -p     "639639"     192.168.8.45             /home/pi/      /ntfs-2TB/$REPO
ncftpput     -z -r 10 -v -u "pi" -p     "639639"     192.168.8.45             /home/pi/$REPO   /ntfs-2TB/$REPO/packagesite.txz
ncftpput     -z -r 10 -v -u "pi" -p     "639639"     192.168.8.45             /home/pi/$REPO   /ntfs-2TB/$REPO/meta.txz
ncftpput     -z -r 10 -v -u "pi" -p     "639639"     192.168.8.45             /home/pi/$REPO        /ntfs-2TB/$REPO/packagesite.txz
sshpass -p 639639 ssh pi@192.168.8.45 'chmod -R 777 /home/pi/$REPO'

