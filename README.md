# fokoos-odin-marlin2.0.x-w_bltouch
The stock firmware for Fokoos Odin 5F3, but with BLTouch and different start screen

# How to use:
Remove previous firmware files from your microSD card.
Copy 'assets' folder and .bin file to root of microSD card.
Insert into machine, power machine on, wait for install of new firmware and update of UI.

The probe-to-nozzle X/Y offsets are based on this touch-sensor mount:  https://www.thingiverse.com/thing:4938873
You should change them if you use a different mount (can be done via touchscreen UI).  Additionally, you will want to set your own z-offset even if you are using the same mount as I am (again, this can be done in the touchscreen UI).

I have a short video showing how to access the internals of the case so you can wire the touch-sensor:  https://youtu.be/l-Co34yshsM

# Experimental Branch Notes:
!! Currently, the experimental branch has no new features and the experimental features from it have been debugged and added to main branch.  You should use that.  !!

-I removed the 'tramming assistant' until I can be sure of the correct parameters for the Odin machine.
-I have enabled 'Z_MIN_PROBE_REPEATABILITY_TEST'.  This allows you to send 'M48' through console to the machine to guage the accuracy of your ABL probe.
-The experimental branch adds some menu options that are absent in the stock menu.  For example, by default the firmware will give you either automatic leveling menu OR manual corner leveling menu.  In this firmware, I have enabled custom menu which allows for manual corner leveling to be added to the 'more' menu under 'tools'.  There are two options for manual corner leveling.  The first will pre-heat nozzle and bed and do an XYZ home before moving to first corner position.  The second does not pre-heat or home first.  Please note that there is a bug in the menu UI wherein the 1st corner icon will display as 'back' button until pressed.  Additionally, the menu will freeze and prompt the machine to reset when you select 'back' after you are finished leveling.  I have not found a solution to this yet and this may be why the stock firmware leaves manual leveling off if you have ABL enabled.
-Please note that I have attempted to add the temperature controls to the 'tool' screen as well as the 'home' and 'move' screens.  This allows you to jump to the preheat menu from those screens.  It seems to be buggy wherein every now-and-then the screen will freeze prompting the machine to reset.  In order to fit this information on those screens, I had to create two new icons which are included in the assets folder.  The old assets are still in the folder, renamed to '.old'.  I attempted to add this information to the 'corner leveling' screen but it wouldn't even show and caused the whole menu to become glitchy.

# Future updates:
I plan to update more of the UI icons and customize the menus further, but I do not have a lot of free-time so expect this development to be slow.
Apparently the LVGLUI has some weirdness with Marlin and filament runout / resume after power loss.  I hope to find a way to improve the filament runout actions of the stock firmware.

If you are looking for a firmware for Fokoos Odin with BLTouch / 3DTouch then I hope you find this useful.  Thank you.
