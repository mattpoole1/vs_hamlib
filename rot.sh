#!/bin/bash

# Author: Matt Poole
# Date: 2nd May 2018
# Personal Contact: matt.poole1@gmail.com
# Function: Runs the required programs for Gpredict to communicate with and control the M2 Antenna Positioner

FLAGS=""

while getopts ":vc" opt; do
case $opt in
    v ) 
        FLAGS=$FLAGS"-v "
        ;;
    c )
        FLAGS=$FLAGS"-c" 
        ;;     
    \? )
        echo "Unknown option given"
        ;;
esac
done    
# Define Azimuth and Elevation Rotator Models in Hamlib
AZ_MODEL=1001
EL_MODEL=1002

# Define serial ports connected to Azimuth and Elevation controllers
AZ_CON=/dev/ttyMP0
EL_CON=/dev/ttyMP1

# Define TCP ports that the Hamlib TCP servers open on
AZ_PORT=4533
EL_PORT=4535

# Define TCP port Gpredict sends commands to
COM_PORT=4537

# Start Az control TCP Server
rotctld -m $AZ_MODEL -r $AZ_CON -t $AZ_PORT &
# At the same time, start El control TCP Server
rotctld -m $EL_MODEL -r $EL_CON -t $EL_PORT &
# At the same time, run python script to forward Gpredict commands to controller
python /home/technician/Hamlib/gptom2.py $COM_PORT $AZ_PORT $EL_PORT $FLAGS

trap "kill 0" EXIT
rotctld -m $AZ_MODEL -r $AZ_CON -t $AZ_PORT &
rotctld -m $EL_MODEL -r $EL_CON -t $EL_PORT &
python /home/technician/Hamlib/gptom2.py $COM_PORT $AZ_PORT $EL_PORT $FLAGS
wait



