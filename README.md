# fokoos-odin-marlin2.0.x-w_bltouch
The stock firmware for Fokoos Odin 5F3, but with BLTouch and different start screen.

Update Nov 11, 2021:  Updated firmware to enable dual-z steppers.  This also enables use of G34 gcode to allow automatic alignment of z-steppers which aids in leveling the bed.  It outputs values to the terminal as well.

Update Dec 15, 2021:  Updated firmware to include two corner-leveling options in the 'more menu; these include manual corner leveling with and without homing axes first.  The temperature of the bed and nozzle are now displayed on many more screens.  Added 'z min probe repeatability test' (M48).  Added MKS Robin / tft / lvglui specific filament runout parameters.  Tried to test it with Octoprint, but it didn't detect the runout (I think Octoprint needs a seperate physical sensor).  Will test soon on print from SD.

Update Mar 9, 2022:<br/>
	-add emergency stop button on main screen to stop prints from octoprint when you dont have the time to pull-up the web ui<br/>
	-change probe points in mesh grid from 6x6 to 5x5<br/>
	-increase homing/probing travel speed<br/>
	-enable sw_mode for bltouch as rec. by ANTClabs<br/>
	-enable HOTEND_IDLE_TIMEOUT: 10 mins no movement @ 150 degrees<br/>
	-disabled EXTRAPOLATE_BEYOND_GRID option in bed mesh settings<br/>
	-change baud rate from 250000 to 125000 because that's what MKS have set in the config.h on their github for the robin nano marlin firmware<br/>
	-enable PRINTCOUNTER: view print stats with M78; total jobs, total success, total fail, total time printing<br/>
	-enable G26_MESH_VALIDATION: 0.4mm nozzle, 0.2mm layer height, 200C/60C temp, 25mm/s print travel<br/>
	-enable MULTIPLE_PROBING: 2 does fast/slow probes with a weighted average<br/>
	-discovered that you cannot enable advanced pause feature.  it causes random pauses<br/>
	-added all project files so people can edit them as they please<br/>
	-added two different pre-compiled firmware.  one with normal bed size, one with 230mm 'X' bed size because I was getting weirdness on the right edge of my bed meshes.  look in folder 'pre-compiled', with subfolders corresponding to desired bed size<br/>

Update Apr 8, 2022:<br/>
	-change stepper drivers to TMC2209_STANDALONE, which is what MKS have set for this board in their firmware file (https://github.com/makerbase-mks/Mks-Robin-Nano-Marlin2.0-Firmware/blob/master/Marlin/Configuration.h)<br/>
	-change DEFAULT_AXIS_STEPS_PER_UNIT for extruder from '94' to '93'.<br/>
	-enabled EXTRAPOLATE_BEYOND_GRID again<br/>
	-enabled bilinear subdivision<br/>
	-experimented with linear advance, but it is not possible on TMC2209 on Robin Nano V2 without first modifying the hardware.  DO NOT ENABLE!<br/>

Update Apr 9, 2022:<br/>
	-removed heatsinks from my stepper drivers, visually confirmed they are twotrees 2208 v3.  Change firmware to 2208_standalone.<br/>

# How to use:
Remove previous firmware files from your microSD card.<br/>
Copy 'assets' folder and .bin file to root of microSD card.<br/>
Insert into machine, power machine on, wait for install of new firmware and update of UI.<br/>

The probe-to-nozzle X/Y offsets are based on this touch-sensor mount:  https://www.thingiverse.com/thing:4938873 <br/>
You should change them if you use a different mount (can be done via touchscreen UI).  Additionally, you will want to set your own z-offset even if you are using the same mount as I am (again, this can be done in the touchscreen UI).

I have a short video showing how to access the internals of the case so you can wire the touch-sensor:  https://youtu.be/l-Co34yshsM

# Experimental Branch Available:
Currently, the experimental branch has no new features and the experimental features from it have been debugged and added to main branch.

# Future updates:
I plan to update more of the UI icons, change the font, and customize the menus further, but I do not have a lot of free-time so expect this development to be slow.<br/>

If you are looking for a firmware for Fokoos Odin with BLTouch / 3DTouch then I hope you find this useful.  If you find bugs or have feature requests, please let me know.  Thank you.
