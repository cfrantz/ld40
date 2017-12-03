#!/bin/bash

sudo mount /dev/sdb1 /mnt
sudo cp lildigger.nes /mnt/test
sudo umount /mnt
sync
sync
sync
