#!/bin/sh


PKG=$(ls $HOME/2TB/All16 | grep qemu_vmm)

doas rm $HOME/2TB/All16/$PKG
sshpass -p 639639 ssh pi@192.168.8.45 "rm ~/All16/$PKG"
cd $HOME/2TB/All16/
doas pkg create qemu_vmm
cd -
doas pkg repo /ntfs-2TB/All16

ncftpput  -R -z -r 10 -v -u "pi" -p     "639639"     192.168.8.45             /home/pi/      /ntfs-2TB/All16
ncftpput     -z -r 10 -v -u "pi" -p     "639639"     192.168.8.45             /home/pi/All15   /ntfs-2TB/All16/packagesite.txz
ncftpput     -z -r 10 -v -u "pi" -p     "639639"     192.168.8.45             /home/pi/All15   /ntfs-2TB/All16/meta.txz
ncftpput     -z -r 10 -v -u "pi" -p     "639639"     192.168.8.45             /home/pi/All15        /ntfs-2TB/All16/packagesite.txz
sshpass -p 639639 ssh pi@192.168.8.45 'chmod -R 777 /home/pi/All16'

