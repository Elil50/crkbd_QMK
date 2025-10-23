KEYMAP="./Elil_50/keymap.c"
CONFIG="./Elil_50/config.h"
RULES="./Elil_50/rules.mk"
TARGET="./qmk_firmware/keyboards/crkbd/keymaps"
PS2="./PS2_patches"

mkdir -p "$TARGET/Elil_50"
cp "$KEYMAP" "$TARGET/Elil_50"
cp "$CONFIG" "$TARGET/Elil_50"
cp "$RULES" "$TARGET/Elil_50"

mkdir -p ./qmk_firmware/PS2_patches
cp "$PS2/ps2_pointing_device.diff" ./qmk_firmware/PS2_patches
cp "$PS2/ps2_vendor.diff" ./qmk_firmware/PS2_patches

cd ./qmk_firmware

if git apply --reverse --check "$PS2/ps2_pointing_device.diff"; then
  echo "ps2_pointing_device.diff patch already applied"
else
  git apply "$PS2/ps2_pointing_device.diff"
fi

if git apply --reverse --check "$PS2/ps2_vendor.diff"; then
  echo "ps2_vendor.diff patch already applied"
else
  git apply "$PS2/ps2_vendor.diff"
fi
