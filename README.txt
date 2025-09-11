
Add in line 150 of:
/home/elil50/Documents/qmk/qmk_firmware/platforms/chibios/drivers/vendor/RP/RP2040/ps2_vendor.c

The following line:
PAL_RP_PAD_PUE |

So that it looks like:
    // clang-format off
    iomode_t pin_mode = PAL_RP_PAD_IE |
                        PAL_RP_GPIO_OE |
                        PAL_RP_PAD_SLEWFAST |
                        PAL_RP_PAD_DRIVE12 |
                        PAL_RP_PAD_PUE |

Add in folder:
/home/elil50/Documents/qmk/qmk_firmware/keyboards/crkbd/keymaps

The folder:
Elil_50
