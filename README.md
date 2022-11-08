# OpenCR_idminer_custom

- 2022/11/08 - mecanum opencr code

# How to use

1. Connect the [OpenCR](https://emanual.robotis.com/docs/en/parts/controller/opencr10/) to the Rasbperry Pi using the micro USB cable.
2. Install required packages on the Raspberry Pi to upload the [OpenCR](https://emanual.robotis.com/docs/en/parts/controller/opencr10/) firmware.
```
$ sudo dpkg --add-architecture armhf
$ sudo apt-get update
$ sudo apt-get install libc6:armhf
```
3. Depending on the platform, use meanum_noetic for the OPENCR_MODEL name.
```
$ export OPENCR_PORT=/dev/ttyACM0
$ export OPENCR_MODEL=mecanum_noetic
$ rm -rf ./opencr_update_idm_custom.tar.bz2
```
4. Download the firmware and loader, then extract the file.
```
$ wget https://github.com/zhl017/OpenCR_idm_custom/raw/main/binaries/22.11.08/opencr_update_idm_custom.tar.bz2
$ tar -xvf opencr_update_idm_custom.tar.bz2
```
5. Upload firmware to the OpenCR.
```
$ cd ./opencr_update
$ ./update.sh $OPENCR_PORT $OPENCR_MODEL.opencr
```
