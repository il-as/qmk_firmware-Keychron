# A take on qwerty lafayette
**Work in progress**


TODO: explain better (brain is cooked can't make sentences that go vroom)
This is a reimplementation of the qwerty lafayette keymap.
Qerty Lafayette is an ergonomic keymap made for developers and rigorous typists.

The concept around this reimplementation is to make qwerty lafayette work on an ANSI keyboard without losing the ability to do "<" and ">" on the base layer with shift.
A second important factor is portability:
qwerty-lafayette is an installable keymap that lives at the OS level, this is great because it makes it available to every keyboard. 



On the normal Qwerty Lafayette, those keys are used for colon and semicolon as positioned on an ISO keyboard and the "<" and ">" are typed using the key next to Lshift, that key doesn't exist on an ANSI layout.

This is unfortunate on an ANSI keyboard as the Ralt layer allready outputs colon and semi colons with the same key.

Reimplementing it with QMK offers two benefits:
1. portability :
    + since the keymap lives in the keyboard firmware, it will work on servers as long as you are able to switch the keymap to US ANSI international. This keymap is usually installed by default. For example, on my linux machine I do:
    `setxkbmap -layout us -variant intl`
    and I'm set.
2. Keyboard layout configuration:
    + Qwerty-lafayette is build to be used with an ISO layout, this is because France uses ISO keyboards. When using this keymap with an ANSI keyboard, you lose one key (<> (TODO: FIND THE KEYCODE)), and qwerty lafayette still changes key positions to match ISO keyboards, making the experience less transparent if you are a weirdo with an ANSI keyboard in France like me.

Use this
https://dry.sailingissues.com/us-international-keyboard-layout.html


## Keys not mapped 
Some keys are not mapped because they are unavailable in the US intl afaik
TODO: MAP WITH UNICODE

DK1 KC_1        „
DK1 S(KC_5)     ‰
DK1 S(KC_9)     ‹
DK1 S(KC_0)     ›
DK1 KC_MINS     —
DK1 KC_EQL      ≠
DK1 S(KC_EQL)   ±


