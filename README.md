# fokoos-odin-marlin2.0.x-w_bltouch
The stock firmware for Fokoos Odin 5F3, but with BLTouch and different start screen.
Update Nov 11, 2021:  Updated firmware to enable dual-z steppers.  This also enables use of G34 gcode to allow automatic alignment of z-steppers which aids in leveling the bed.  It outputs values to the terminal as well.

# How to use:
Remove previous firmware files from your microSD card.
Copy 'assets' folder and .bin file to root of microSD card.
Insert into machine, power machine on, wait for install of new firmware and update of UI.

The probe-to-nozzle X/Y offsets are based on this touch-sensor mount:  https://www.thingiverse.com/thing:4938873
You should change them if you use a different mount (can be done via touchscreen UI).  Additionally, you will want to set your own z-offset even if you are using the same mount as I am (again, this can be done in the touchscreen UI).

I have a short video showing how to access the internals of the case so you can wire the touch-sensor:  https://youtu.be/l-Co34yshsM

# Experimental Branch Available:
Go to the 'experimental' branch from the dropdown above to get new menu options such as manual corner leveling and temperature controls in the 'tool', 'move', and 'home' screens.
This branch also removes 'tramming assistant' until more specific parameters can be input for it and enables 'z min probe repeatability test' for gaugeing accuracy of ABL probe (M48).

# Future updates:
I plan to update more of the UI icons and customize the menus further, but I do not have a lot of free-time so expect this development to be slow.
Apparently the LVGLUI has some weirdness with Marlin and filament runout / resume after power loss.  I hope to find a way to improve the filament runout actions of the stock firmware.

If you are looking for a firmware for Fokoos Odin with BLTouch / 3DTouch then I hope you find this useful.  Thank you.
