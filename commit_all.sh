cd qmk_firmware
echo "pushing qmk_firmware submodule"
git add .
git status
git commit -m "updated user files"
git push
cd ../
echo "pushing qmk module"
git add .
git status
git commit -m "updated user files"
git push
