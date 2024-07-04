#!/bin/bash

save_dir="attachments"
mkdir -p $save_dir
num_photos=20
for ((i=1; i<=$num_photos; i++))
do
    width=$((RANDOM%1000+400))
    height=$((RANDOM%600+300))

    photo_url="https://picsum.photos/$width/$height"
    
    file_name="photo_$(width)x$height.jpg"

    curl -s $photo_url -o "$save_dir/$file_name"
    echo "Downloaded photo $1: $file_name"
done

echo "All photos downloaded to $save_der"
