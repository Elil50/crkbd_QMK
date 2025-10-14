> [!CAUTION]
> Mouse buttons MS_BTN* are correctly pressed, but they wait for the next mouse movement to release the key press. 

This has direct implications when clicking buttons (you need to move the cursor before the click is recognized, with the lack of double click capabilities and in software with buttons which recognize the time you hold down the button (it holds it down until you move the cursor again).

* ### Executables

**qmk_file_inject.sh:** injects user files (described below) in ```qmk_firmware```. 

**flash.sh:** executes ```qmk_file_inject.sh``` and ```qmk flash``` in the user keyboard folder. 

> [!TIP] 
> All the following actions are automatically performed by running ```./qmk_file_inject.sh```. <br/>
Before running a program, remember to change its execution permissions. For example, on Linux you run ```chmod +x program_name.sh```.  

* ### Keymap.c, rules.mk, config.h

Add ```Keymap.c```, ```rules.mk```, ```config.h``` in the following path:
```
../qmk_firmware/keyboards/crkbd/keymaps/Elil_50
```

* ### PS/2 Driver Trackpoint (optional)

The host needs pull-up resistors on PS/2 DATA and CLK lines. The built-in pullup resistors from the host 4k to 100k are acceptable. <br/>
In conclusion, you need to add those pull-up resistors (I didn't), or apply the following patch:

Add ```PAL_RP_PAD_PUE |``` in line 150 of file
```
../qmk_firmware/platforms/chibios/drivers/vendor/RP/RP2040/ps2_vendor.c
```
so that it looks like:
```c
    // clang-format off
    iomode_t pin_mode = PAL_RP_PAD_IE |
                        PAL_RP_GPIO_OE |
                        PAL_RP_PAD_SLEWFAST |
                        PAL_RP_PAD_DRIVE12 |
                        PAL_RP_PAD_PUE |
```
Before this patch the trackpoint didn't work. After this patch, it moves the cursor

You also need - according to https://github.com/qmk/qmk_firmware/issues/24455 - to apply the following patches to file
```
../qmk_firmware/drivers/ps2/ps2_mouse.c
```
* Comment ```mouse_report->buttons = 0;``` in line 234 so that it looks like:
```c
static inline void ps2_mouse_clear_report(report_mouse_t *mouse_report) {
    mouse_report->x       = 0;
    mouse_report->y       = 0;
    mouse_report->v       = 0;
    mouse_report->h       = 0;
    // mouse_report->buttons = 0;
} 
```
* Comment ```return``` in both line 89 and 102, so that it looks like:
```c
    } else {
        if (debug_mouse) print("ps2_mouse: fail to get mouse packet\n");
        /* return here to avoid updating the mouse button state */
        //return;
    }
```
Before this patch the mouse keys worked only while moving the cursor. After this patch they always work. 

