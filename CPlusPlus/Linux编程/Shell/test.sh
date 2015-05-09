#!/bin/sh

if [ -f /bin/bash ]
then
    echo "file /bin/bash exists"
fi

if [ -d /bin/bash ]
then
    echo "/bin/bash is a directory"
else
    echo "/bin/bash is NOT a directory"
fi

echo "Is it morning? Please answer yes or no"
read timeofday
# use "$timeofday" instead of $timeofday, beacuse sometimes $timeofday is null, thus 
# if [ $timeofday = "yes" ] became
# if [ = "yes" ]
# this totally wrong!
if [ "$timeofday" = "yes" ]
then
    echo "Good morning"
elif [ "$timeofday" = "no" ]
then
    echo "Good afternoon"
else
    echo "Sorry, $timeofday not recognized. Enter yes of no"
    exit 1
fi

exit 0
