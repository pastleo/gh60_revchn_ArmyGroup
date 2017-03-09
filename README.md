GH60 RevCHN from ArmyGroup firmware
=========

Tutorial: [http://blog.dm4.tw/blog/2015/03/17/build-gh60-revchn-on-mac/](http://blog.dm4.tw/blog/2015/03/17/build-gh60-revchn-on-mac/)

Copied and modified from [https://github.com/kairyu/tmk_keyboard_custom/tree/master/keyboard/gh60](https://github.com/kairyu/tmk_keyboard_custom/tree/master/keyboard/gh60)

## Flashing system requirements

 * [dfu-programmer](https://dfu-programmer.github.io/)
 * [avr-gcc](http://www.nongnu.org/avr-libc/)

#### For OSX

Just use [homwbrew](https://brew.sh) to install dfu-programmer:

```
brew install dfu-programmer
```

And follow guide [here](https://github.com/osx-cross/homebrew-avr#installing-homebrew-avr-formulae) to install `avr-gcc`

## Quick Steps:

 * `git clone --recursive <this_repo>`
 * `cd <this_repo>`
    * just make the rom files: `make clean; make`
    * or make and burn into keyboard: `make clean; make dfu`

