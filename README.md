# fokoos-odin-marlin2.0.x-w_bltouch
The stock firmware for Fokoos Odin 5F3, but with BLTouch and different start screen.
Update Nov 11, 2021:  Updated firmware to enable dual-z steppers.  This also enables use of G34 gcode to allow automatic alignment of z-steppers which aids in leveling the bed.  It outputs values to the terminal as well.
Update Dec 15, 2021:  Updated firmware to include two corner-leveling options in the 'more menu; these include manual corner leveling with and without homing axes first.  The temperature of the bed and nozzle are now displayed on many more screens.  Added 'z min probe repeatability test' (M48).  Added MKS Robin / tft / lvglui specific filament runout parameters.  Tried to test it with Octoprint, but it didn't detect the runout.  Will test soon on print from SD.

# How to use:
Remove previous firmware files from your microSD card.
Copy 'assets' folder and .bin file to root of microSD card.
Insert into machine, power machine on, wait for install of new firmware and update of UI.

The probe-to-nozzle X/Y offsets are based on this touch-sensor mount:  https://www.thingiverse.com/thing:4938873
You should change them if you use a different mount (can be done via touchscreen UI).  Additionally, you will want to set your own z-offset even if you are using the same mount as I am (again, this can be done in the touchscreen UI).

I have a short video showing how to access the internals of the case so you can wire the touch-sensor:  https://youtu.be/l-Co34yshsM

# Experimental Branch Available:
Currently, the experimental branch has no new features and the experimental features from it have been debugged and added to main branch.

# Future updates:
I plan to update more of the UI icons and customize the menus further, but I do not have a lot of free-time so expect this development to be slow.

If you are looking for a firmware for Fokoos Odin with BLTouch / 3DTouch then I hope you find this useful.  Thank you.
