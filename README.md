# Elil_50 Corne keyboard QMK firmware
<img src="./Images/Keyboard_horizontal.jpg" width=max-width>

This project is subdivided as it follows:
1. An explaination of my custom firmware, written for the 6 columns [Corne keyboard V3](https://github.com/foostan/crkbd/) (a 42 keys ortholinear split keyboard), based on [QMK](https://github.com/qmk/qmk_firmware/) framework.
2. My hardware customization: from printable files for the case, to key switches and keycaps, and even mounting tips for the trackpoint (optional).
3. My desktop enviroment shortcuts (optional).

# Just a keyboard for show?
<img src="./Images/Keyboard_horizontal_open.jpg" width=max-width>

I coded, but my hands always feel lost on big keyboards: I couldn't learn touch typing and my eyes hurt each time I took a quick glance at the keyboard.<br/>
I coded, but my desk is comically high and I had the habit of pressing my wrists against its edges: my knuckles literally bled for months due to circulation issues. I tried using a comically high chair, but then it was my knees' turn to ache. I bought a footrest, but it didn't change anything.

That's when I went down the ergonomic keyboard rabbit hole and discovered split keyboards.

I needed to mount it to my chair to stop worrying about the desk height.<br/>
I needed just the right amount of keys: too few and it would reduce the typing speed, too many and I would lose my hands on it.<br/>
I needed a split design to easily sit and stand, without moving a big rectangular slab over my legs.<br/>
I needed a firmware to customize it to my heart's content.<br/>
I needed a built-in pointing device to replace a standalone mouse. <br/>
I needed something portable.

This is the solution I found and I'm learning touch typing for the first time in my life.


# :one: Keyboard firmware
When it comes to firmware, there are mainly 2 options: QMK(for wired keyboards) and ZMK(for wireless keyboards). My old laptop has a fried wireless module, so I chose the adaptability of wired over the comfort of wireless.

This layout was optimized for coding and typing purposes. It works only if you set the OS language to english.

The trackpoint can be disabled by turning false the flag ```MY_TRACKPOINT_ENABLE``` in ```./Elil_50/rules.mk```. This action removes the automatic mouse layer, so reduce ```MY_MAX_LAYER``` by 1 at the beginning of ```./Elil_50/keymap.c```.<br/>
This option will not affect any other functionality.

Unicode symbols can be disabled by turning false the flag ```MY_UNICODE_ENABLE``` in ```./Elil_50/rules.mk```.<br/>
This option will not affect any other functionality.

Unicode support depends on both OS and software used: most recent Linux and Mac OS do support it by default, but you need to install Wincompose for Windows (another reason to avoid it).<br/> 
The keymap I wrote does an automatic OS detection to use the right unicode input method.

<img src="./Images/1_1.jpg" width=max-width>
<img src="./Images/2.jpg" width=max-width>
<img src="./Images/3.jpg" width=max-width>
<img src="./Images/4.jpg" width=max-width>

The main selling point of flashable keyboards is the layout customization, so get comfy with writing in the last part of ```./Elil_50/keymap.c``` and flashing it: it's really easy. Instead of remapping softwares and videogames, additional layers can be added in ```./Elil_50/keymap.c``` after layer 3 (follow my comments) and linked in layer 2 with the syntax documented by QMK developers. Remember to change ```MY_MAX_LAYER``` according to the layers added or removed.

## User files and changes to qmk_firmware

* ### Executables

**qmk_file_inject.sh:** inject user files (described below) in qmk_firmware

**flash.sh:** execute qmk_file_inject and qmk flash in user keyboard folder

**commit_all.sh:** commits all changes, both of qmk_firmware submodule and my_qmk module (main folder)

* ### Keymap.c, rules.mk, config.h

Add the folder ``` Elil_50 ``` in the following path:
```
./qmk_firmware/keyboards/crkbd/keymaps
```

* ### PS/2 Driver Trackpoint (optional)

The host needs pull-up resistors on PS/2 DATA and CLK lines. The built-in pullup resistors from the host 4k to 100k are acceptable. 
So, I need to add those pull-up resistors (didn't do it), or apply the following patch:

Add in line 150 of file:
```
./qmk_firmware/platforms/chibios/drivers/vendor/RP/RP2040/ps2_vendor.c
```
The line ``` PAL_RP_PAD_PUE | ``` so that it looks like:
```c
    // clang-format off
    iomode_t pin_mode = PAL_RP_PAD_IE |
                        PAL_RP_GPIO_OE |
                        PAL_RP_PAD_SLEWFAST |
                        PAL_RP_PAD_DRIVE12 |
                        PAL_RP_PAD_PUE |
```

---

<br>

# :two: Keyboard Hardware
The main components are:

* 2 PCB: Helidox Corne V3, 6 columns
* 2 Microcontroller: Elite-Pi
* 1 Trackpoint: SK8707-01-002(3.3V) Integrated (optional)
* 42 key switches and keycaps

There are tons of sites who sell DIY kits and pre-builts: each one has their own well-documented and similar guide on little details I won't write here. Nowadays even aliexpress sells low cost pre-builts, but be aware they are not easily flashable.

## External shell
<img src="./Images/portable_config.jpg" width="400">

I 3D printed [this case](https://www.printables.com/model/347524-corne-keyboard-case-5-and-6-columns) and designed for portability purposes the light grey interlocking "case wall" depicted above. Note that you don't need to unplug the TRRS cable from the keyboard (the less mechanical stress, the longer the life span). You can find its file in ```./stl_files/eiga-wall-Elil50.stl```.


## Key Switches and Keycaps
The world of key switches is really big. The important keywords you need to know are: low-profile(choc), standard profile (MX), tactile, linear, clicky, silent, lubed. I built a MX compatible one for aesthetics (most artisanal keycaps are cherry (MX) ) and bought tactile silent switches. However I forgot to check if they were pre-lubed: they were not and they feel scratchy as hell. I won't complain as I'm not building this keyboard for the mechanical switch pleasure, even though I admit the linear gateron of a friend of mine feel like heaven. 

Keycaps have an equally vast range of options: I'll show some in the image below. I bought DSA profile keycaps from Aliexpress and scratched the home rows with sandpaper (1 minute at most of handwork).

<img src="./Images/keycaps_profile.png" width="400">

## Trackpoint pinout setup (optional)
<img src="./Images/Trackpoint_pinout.jpg" width="400">

## Trackpoint extensor sketch (optional)
In order to raise the trackpoint keycap, I 3D printed the following sketch, cut the excess height and manually reduced the diameter of the part which goes inside the PCB. It's probably better to print with 3mm instead of 4mm. I increased the diameter of the PCB holes with a drill.

<img src="./Images/trackpoint_extensor_project.jpg" width="400">

---

<br>

# :three: Desktop Enviroment (KDE Plasma) (optional)
<img src="./Images/Monitor_overview.png" width=max-width>


In ```KDE_Plasma``` folder you can find both monitor overview and keyboard shortcuts files. This is totally optional and it's more related to my typing experience than the keyboard.

* Replace ```./KDE_Plasma/overview.page``` in the following path:
```
.local/share/plasma-systemmonitor/overview.page
```

* Replace ```./KDE_Plasma/kglobalshortcutsrc``` in the following path:
```
.config/kglobalshortcutsrc
```

## OS Shortcuts

<img src="./Images/0.jpg" width=max-width>

---

<br>

# :star2: Thanks

I thank the whole open source ergonomic mechanical keyboard community for the projects they pushed out in the world and QMK developers for their support over their discord server. A special thanks to my friend Luca which helped me mounting and soldering the trackpoint.
