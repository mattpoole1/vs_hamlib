To use gpredict with M2 RC2800 Positioner:
==========================================

Author: Matthew Poole
Email: matt.poole1@gmail.com
Date: 10th April 2018

## Initial Setup:
1. Launch gpredict (/usr/local/bin/gpredict)
2. Navigate to Edit>Preferences>Interfaces>Rotators>Add New
3. Set up the rotator as follows:
* ConfigName: M2AzEl
* Host: localhost
* Port: 4537
* Min Az: 0
* Max Az: 360
* Min El: 0
* Max El: 90
* Az Type: 0->180->360

## Before Using
1. Launch a terminal anywhere
2. Type: 'rotctld -m 1001 -r /dev/ttyS0 -t 4533 <-vvvvv>' to open the port to the Azimuth controller. Use the -v options for verbose mode.
3. Launch another terminal, keeping the first open.
4. Type: 'rotctld -m 1002 -r /dev/ttyUSB0 -t 4535 <-vvvvv>' to open the port to the Elevation controller. Use the -v options for verbose mode.
5. Launch another terminal in /home/technician/Hamlib
6. Type 'python gptom2.py 4537 4533 4535' Note the order of these port numbers is important!

## To use
1. Navigate into your desired Gpredict module
2. In the upper right hand corner of the window, click the drop down arrow and click Antenna Control
3. In the Settings window, select the M2AzEl Device
4. Gpredict should now be able to be used to operate the controller

