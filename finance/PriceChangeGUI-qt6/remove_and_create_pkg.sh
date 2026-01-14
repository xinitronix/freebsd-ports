#!/bin/sh


PKG=$(ls $HOME/2TB/All15 | grep PriceChangeGUI-qt6 )

doas rm $HOME/2TB/All15/$PKG
sshpass -p 639639 ssh pi@192.168.8.45 "rm ~/All15/$PKG"
cd $HOME/2TB/All15/
doas pkg create PriceChangeGUI-qt6
cd -
doas pkg repo /ntfs-2TB/All15

ncftpput  -R -z -r 10 -v -u "pi" -p     "639639"     192.168.8.45             /home/pi/      /ntfs-2TB/All15
ncftpput     -z -r 10 -v -u "pi" -p     "639639"     192.168.8.45             /home/pi/All15   /ntfs-2TB/All15/packagesite.txz
ncftpput     -z -r 10 -v -u "pi" -p     "639639"     192.168.8.45             /home/pi/All15   /ntfs-2TB/All15/meta.txz
ncftpput     -z -r 10 -v -u "pi" -p     "639639"     192.168.8.45             /home/pi/All15        /ntfs-2TB/All15/packagesite.txz
sshpass -p 639639 ssh pi@192.168.8.45 'chmod -R 777 /home/pi/All15'

