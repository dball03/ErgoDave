# ErgoDox "ErgoDave"/"ErgoDvor" Configuration

## Motivation

Attempting to create an effective Dvorak-based, ErgoDox layout, largely for programming using (Neo)Vim in Linux environment.
The idea is to create a base Dvorak layout with convenient access to a "coding" layer for numberpad and the full complement of symbols.
This should minimise the amount of "shifting" and stretching that is required, particularly for programming.

## Overview and philosophy

Note: This layout is designed to be used with a US software layout such that:
* ' and " are on the same key and Shift+2 produces @, rather than "
* Shift+3 produces #, rather than £ in a UK layout.

### Base Layer (Dvorak)
<pre><code>
,--------------------------------------------------.           ,--------------------------------------------------.
|   ESC  |   1  |   2  |   3  |   4  |   5  | left |           |right |   6  |   7  |   8  |   9  |   0  |   \    |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|   DEL  |   '  |   ,  |   .  |   p  |   y  |  TG  |           |      |   f  |   g  |   c  |   r  |   l  |   /    |
|--------+------+------+------+------+------|MEDIA |           |      |------+------+------+------+------+--------|
|   ESC  |   a  |   o  |   e  |   u  |   i  |------|           |------|   d  |   h  |   t  |   n  |   s  |   -    |
|--------+------+------+------+------+------|  TO  |           |      |------+------+------+------+------+--------|
| LSHIFT |   ;  |   q  |   j  |   k  |   x  |QWERTY|           |      |   b  |   m  |   w  |   v  |   z  | RSHIFT |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  | LCTRL| LGUI | ALT  |      |  L2  |                                       |  L2  |  LFT |  DWN |  UP  | RGHT |
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.       ,-------------.
                                       |      |      |       |      |      |
                                ,------|------|------|       |------+------+------.
                                |      |      |      |       |      |      |      |
                                | SPC  | BSPC |------|       |------| TAB  | ENTR |
                                |      |      |      |       |      |      |      |
                                `--------------------'       `--------------------'
</code></pre>

* **Accessible symbol layer keys** Layer keys to switch to the symbol layer are provided under each thumb. Other layer keys are provided but are not convenient as these will not be commonly used.
* **No "speciality" keys (tap/hold differentiation)** Honestly, I figure that this is more hassle than it is worth.
* **Common symbol keys** Some symbol common symbol keys are provided in the base layer (other than the standard .,'; set. I figured /\- are valuable to have on the base layer for typing paths and such.

### Secondary Typing layer (QWERTY)
<pre><code>
,--------------------------------------------------.           ,--------------------------------------------------.
|   ESC* |   1  |   2  |   3  |   4  |   5  | left |           |right |   6  |   7  |   8  |   9  |   0  |   \*   |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|   DEL* |   q  |   w  |   e  |   r  |   t  |  TG  |           |      |   y  |   u  |   i  |   o  |   p  |   /*   |
|--------+------+------+------+------+------|MEDIA |           |      |------+------+------+------+------+--------|
|   ESC* |   a  |   s  |   d  |   f  |   g  |------|           |------|   h  |   j  |   k  |   l  |   ;  |   -*  |
|--------+------+------+------+------+------|  TO  |           |      |------+------+------+------+------+--------|
| LSHIFT*|   z  |   x  |   c  |   v  |   b  | BASE |           |      |   n  |   m  |   ,  |   .  |   /  | RSHIFT*|
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  | CTRL* | GUI* | ALT*|      |  L2  |                                       |  L2  | LFT* | DWN* |  UP* | RGHT*|
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.       ,-------------.
                                       |      |      |       |      |      |
                                ,------|------|------|       |------+------+------.
                                |      |      |      |       |      |      |      |
                                | SPC* | BSPC*|------|       |------| TAB* | ENTR*|
                                |      |      | HOME*|       | END* |      |      |
                                `--------------------'       `--------------------'
</code></pre>

* A QWERTY layer is provided because reasons... Thought it could be handy to practice properly touch typing both Dvorak and QWERTY. It may also be useful for others who want to try it out :) This layer is functionally the same as the Dvorak layer in terms of the layer switching and usage.

### Symbol layer
<pre><code>
,--------------------------------------------------.           ,--------------------------------------------------.
|   ESC* |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           |  F7  |  F8  |  F9  | F10  | F11  |  F12 |        |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|   DEL* |   !  |   @  |   {  |   }  |   &  |      |           |      |   +  |   7  |   8  |   9  |   *  |        |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|   ESC* |   #  |   $  |   (  |   )  |   `  |------|           |------|   =  |   4  |   5  |   6  |   0  |        |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
| LSHIFT*|   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   -  |   1  |   2  |   3  |   \  |        |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  | CTRL* | GUI* | ALT*|      |  L2  |                                       |  L2  | LFT* | DWN* |  UP* | RGHT*|
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.       ,-------------.
                                       |      |      |       |      |      |
                                ,------|------|------|       |------+------+------.
                                |      |      |      |       |      |      |      |
                                | SPC* | BSPC*|------|       |------| TAB* | ENTR*|
                                |      |      | HOME*|       | END* |      |      |
                                `--------------------'       `--------------------'
</code></pre>

* **Brackets and Braces** These are all provided explicitly (without shifting) and arranged in-line.
* **Other symbols** All symbols should be present somewhere on this layer, mostly in common typing positions.

### Media and Motions layer

<pre><code>
,--------------------------------------------------.           ,--------------------------------------------------.
|        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
|-------- ------ ------ ------ ------ -------------|           |------ ------ ------ ------ ------ ------ --------|
|        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
|-------- ------ ------ ------ ------ ------|      |           |      |------ ------ ------ ------ ------ --------|
|        | MLFT | MDWN | MUP  | MRGT |      |------|           |------|      |      |      |      |      |        |
|-------- ------ ------ ------ ------ ------|      |           |      |------ ------ ------ ------ ------ --------|
|        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  |      |      |      |      |      |                                       |      |      |      |      |      |
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.       ,-------------.
                                       |      |      |       |      |      |
                                ,------|------|------|       |------+------+------.
                                |  M   |  M   |      |       |      |      |      |
                                | LFT  | RGT  |------|       |------|      |      |
                                | CLK  | CLK  |      |       |      |      |      |
                                `--------------------'       `--------------------'
</code></pre>

* **Scope for many media (and other) control keys** Currently none of these keys are added, at least not until I figure out what these should look like. In any case, an entire layer is dedicated to the potential of providing this functionality. If this layer is useful, it will be worth making this layer more easily accessible.
* Provided mouse keys although I do not fully intend to use them.

## Building and flashing

* This layout should be built as part of the [QMK firmware](https://github.com/qmk/qmk_firmware) repository.

* Depends on avr-libc and gcc-avr packages

Clone the firmware repo and plant this layout into its ergodox keymappings:
```bash
$ git clone https://github.com/qmk/qmk_firmware
$ cd qmk_firmware
$ git clone http://github.com/dball03/ErgoDave keyboards/ergodox_ez/keymaps/ergodave
```

Build the firmware, specifying the desired layout:
```bash
make keyboard=ergodox keymap=ergodave

or

cd keyboards/ergodox_ez
make ergodave
```

Then load the .hex file using a teensy loader (pjrc etc).


## Author

[David Ball](https://github.com/dball03)
