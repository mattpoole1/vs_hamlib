Hamlib Software + Utilities for Venture Southland UHF Ground Station
====================================================================

Author: Matthew Poole
Email: matt.poole1@gmail.com
Date: 10th April 2018

## Making Changes:
1. Make a new branch in which you can make and test your changes
`git branch <your-branch>`
2. Change to your new branch
`git checkout <your-branch>`
3. Now you can freely make changes and test them
4. To backup any local changes to your current branch
```
git add .
git commit -m "<Your message describing changes>"
git push
```
5. Once you are happy your changes work as planned, merge your branch with master
```
git checkout master
git merge <your-branch>
```
6. If there are conflicts to resolve, use `git diff` to highlight these conflicts, then resolve them in a text editor. Once all conflicts have been resolved, push the edited files to the master branch.
```
git add .
git commit -m "Resolved conflicts by review"
git push
```
7. Delete your branch as all changes are now in the master branch
`git branch -d <your-branch>

Using the M2 RC2800 Antenna Positioner
======================================

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
2. Run the command `. rot.sh` to run the utility background programs.

## To use
1. Navigate into your desired Gpredict module
2. In the upper right hand corner of the window, click the drop down arrow and click Antenna Control
3. In the Settings window, select the M2AzEl Device
4. Gpredict should now be able to be used to operate the controller

