# OpenCR_idminer_custom

- 2022/11/18 - modify function
- 2022/11/08 - mecanum opencr code


## OpenCR Setup

<details> <summary> Binary Install [comming soon]</summary>
1. Connect the [OpenCR] to the Rasbperry Pi using the micro USB cable.

2. Install required packages on the Raspberry Pi to upload the [OpenCR] firmware.
  ```bash
$ sudo dpkg --add-architecture armhf
$ sudo apt-get update
$ sudo apt-get install libc6:armhf
  ```

3. Depending on the platform, use either `meacnum` for the **OPENCR_MODEL** name.
  ```bash
$ export OPENCR_PORT=/dev/ttyACM0
$ export OPENCR_MODEL=mecanum
$ rm -rf ./opencr_update.tar.bz2
  ```

4. Download the firmware and loader, then extract the file.
  ```bash
$ wget https://github.com/... 
$ tar -xvf opencr_update.tar.bz2 
  ```

5. Upload firmware to the OpenCR.
  ```bash
$ cd ./opencr_update
$ ./update.sh $OPENCR_PORT $OPENCR_MODEL.opencr
  ```  

6. A successful firmware upload for TurtleBot3 Burger will look like below.  
  ![](/assets/images/platform/turtlebot3/opencr/shell01.png)

7. If firmware upload fails, try uploading with the recovery mode. Below sequence activates the recovery mode of OpenCR. Under the recovery mode, the `STATUS` led of [OpenCR] will blink periodically.
  - Hold down the `PUSH SW2` button.
  - Press the `Reset` button.
  - Release the `Reset` button.
  - Release the `PUSH SW2` button.
</details>

<details><summary>Upload using **Arduino IDE**</summary>

Please be aware that [OpenCR] board manager **does not support Arduino IDE on ARM based SBC such as Raspberry Pi or NVidia Jetson**.  
In order to upload the [OpenCR] firmware using Arduino IDE, please follow the below instructions on your PC.
{: .notice--danger}

1. If you are using Linux, please configure the USB port for OpenCR. For other OS(OSX or Windows), you can skip this step.
  ```bash
$ wget https://raw.githubusercontent.com/ROBOTIS-GIT/OpenCR/master/99-opencr-cdc.rules
$ sudo cp ./99-opencr-cdc.rules /etc/udev/rules.d/
$ sudo udevadm control --reload-rules
$ sudo udevadm trigger
$ sudo apt install libncurses5-dev:i386
  ```
  
2. Install Arduino IDE.
  - [Download the latest Arduino IDE](https://www.arduino.cc/en/software)

3. After completing the installation, run Arduino IDE.

4. Press `Ctrl` + `,` to open the Preferences menu

5. Enter below address in the `Additional Boards Manager URLs`.  
  ```bash
https://raw.githubusercontent.com/ROBOTIS-GIT/OpenCR/master/arduino/opencr_release/package_opencr_index.json
  ```  

6. Open the TurtleBot3 firmware. Depending on your platform, please select the correct firmware.
  - Mecanum : **File > Examples > turtlebot3 > turtlebot3_mecanum > turtlebot3_core**

7. Open the `turtlebot3_core_config.h` and uncomment the **NOETIC_SUPPORT** defintion in the line 21.

8. Connect [OpenCR] to the PC and Select ***OpenCR > OpenCR Board*** from ***Tools > Board*** menu.

9. Select the [OpenCR] connected USB port from ***Tools > Port*** menu.

10. Upload the TurtleBot3 firmware sketch with `Ctrl` + `U` or the upload icon.  

11. If firmware upload fails, try uploading with the recovery mode. Below sequence activates the recovery mode of OpenCR. Under the recovery mode, the `STATUS` led of [OpenCR] will blink periodically.
  - Hold down the `PUSH SW2` button.
  - Press the `Reset` button.
  - Release the `Reset` button.
  - Release the `PUSH SW2` button.
</details>
