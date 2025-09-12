echo "injecting file"
./qmk_file_inject.sh
cd qmk_firmware/keyboards/crkbd/keymaps/Elil_50
echo "flashing"
qmk flash
