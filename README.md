# Tomas's QMK Userspace

My personal QMK userspace. Most of the fun stuff is currently under
`./users/tomas`.

## Code structure

I have tried to utilize QMK userspace as much as possible, to keep a single,
unified source for my keymap. Currently this keymap is shared between my two
main keyboards, the Charybdis Nano and the Piantor Pro.

The shared keymap code can be found in the `users` directory. This contains the
layout as well as helpers and support for some custom keycodes, and a norwegian
ANSI setup for QMK on macOS. The keymap is defined as a macro which can be
mapped onto different keyboard layouts.

In the `keyboards` directory you can see how these mappings are used to map the
same keymap onto different keyboard layouts, while also giving flexibility to
define additional layers and hooks for specific keyboards.
