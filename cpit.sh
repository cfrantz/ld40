#!/bin/bash

sudo mount /dev/sdb1 /mnt
sudo cp lildigger2.nes /mnt/test
sudo umount /mnt
sync
sync
sync
