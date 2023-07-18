rm -rf MYSIL-X*-*-*.tgz MYSIL-X*-*-*.zip MYSIL-X* 

git pull

./fbt.cmd updater_package

DATE_VAR=`date +%m%d`
TIME_VAR=`date +%H%M`
VER_VAR=`git log -1 --pretty=%B`

mv dist/f7-C/f7-update-MYSIL-X "MYSIL-X-$DATE_VAR-$TIME_VAR-$VER_VAR"
zip -rq "MYSIL-X-$DATE_VAR-$TIME_VAR.zip" "MYSIL-X-$DATE_VAR-$TIME_VAR-$VER_VAR"
tar -czf "MYSIL-X-$DATE_VAR-$TIME_VAR.tgz" "MYSIL-X-$DATE_VAR-$TIME_VAR-$VER_VAR"

./Copy.bat

#msg "*" BUILD COMPLETED, TGZ BACKED UP TO GDRIVE" "MYSIL-X-$DATE_VAR-$TIME_VAR-$VER_VAR