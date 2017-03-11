GH60 RevCHN from ArmyGroup firmware
=========

I recently bought a fully customized keyboard from ArmyGroup, after some digging, I found a tutorial about flashing GH60 revCHN here:

[http://blog.dm4.tw/blog/2015/03/17/build-gh60-revchn-on-mac/](http://blog.dm4.tw/blog/2015/03/17/build-gh60-revchn-on-mac/)

Thank you man, I did what it says and everything just works, finally I was sure that my keyboard is GH60 revCHN...

The code here is copied and modified from [https://github.com/kairyu/tmk_keyboard_custom/tree/master/keyboard/gh60](https://github.com/kairyu/tmk_keyboard_custom/tree/master/keyboard/gh60)

Using [tmk_core_custom](https://github.com/kairyu/tmk_core_custom/tree/927664794a5a24a0fe80640a76f077b4ef74634a) as framework which is a fork (maybe) from [tmk_keyboard](https://github.com/tmk/tmk_keyboard/tree/master/tmk_core)

## System requirements

 * [git](https://git-scm.com/) to get the source code
 * [avr-gcc](http://www.nongnu.org/avr-libc/) to compile the firmware
 * [dfu-programmer](https://dfu-programmer.github.io/) to flash into the chip

#### For OSX

Just use [homwbrew](https://brew.sh) to install dfu-programmer:

```
brew install dfu-programmer
```

And follow guide [here](https://github.com/osx-cross/homebrew-avr#installing-homebrew-avr-formulae) to install `avr-gcc`

#### For Windows

I havn't try out a working way to compile firmware on windows, I use [WSL (with wsltty)](https://github.com/mintty/wsltty) which is a easy way to get a linux with file sharing functionality.

After the firmware is compiled, use [dfu-programmer-win](https://sourceforge.net/projects/dfu-programmer/files/dfu-programmer/):

* Download and unzip somewhere
* Install driver from `dfu-prog-usb-*/atmel_usb_dfu.inf`, right click on it and choose `Install`
* Add the `dfu-programmer.exe` to PATH variable.
* If you can input `dfu-programmer` in console (CMD or powershell) and get no error then you are ready to flash

#### Compile firmware in linux (debian)

```
sudo apt-get update;
sudo apt-get install gcc-avr avr-libc make;
```

And your linux is ready to compile firmware

## Steps:

 * `git clone --recursive <this_repo>`
    * Remember the submodule `tmk_core_custom` must be cloned, donwloading the zip is not enough!
 * `cd <this_repo>`
    * just compile the firmware: `make clean; make`
        * compiled firmware is located at `build/gh60revchn_lufa.hex`
    * or make and burn into keyboard: `make clean; make dfu`
 * flashing: 
    * Press the button at the back of the keyboard PCB.
    * `dfu-programmer atmega32u4 get` to check if the keyboard flash device is connected
    * `dfu-programmer atmega32u4 erase` to erase current firmware
    * `dfu-programmer atmega32u4 flash build/gh60revchn_lufa.hex` to flash the compiled firmware
    * `dfu-programmer atmega32u4 reset` to restart your keyboard

## Keymap modifications

tmk keyboard is a great keyboard framework, and it is well-documented too.

I just follow docs [here](https://github.com/kairyu/tmk_core_custom/blob/927664794a5a24a0fe80640a76f077b4ef74634a/doc/keymap.md) and change `keymap_*.c`.

Finally `keymap_pastleo.c` is created with my very own keymap.

The result is not bad with some cost of time.

