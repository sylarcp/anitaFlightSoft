#!/bin/bash

if df -h | grep -q "satamini"
then
	sudo umount /mnt/satamini
fi

disabled=`getConfigValue anitaSoft.config global disableSatamini`
if [ $disabled -eq 1 ] ; then
    echo "Satamini disk disabled"
    exit 0
fi


sudo chmod a-w /mnt/satamini
label=`getConfigString anitaSoft.config global sataminiName`
echo "Trying to mount $label on /mnt/satamini"
sudo mount -L $label -o defaults /mnt/satamini
if df -h | grep -q "satamini"
then
	sudo chmod a+wrx /mnt/satamini
fi
