# thumbledore

*I only uploaded this so that it may serve as inspiration. It is still being 
tweaked.*

Typing on a standard keyboard is not a great experience. Your thumbs 
idle while your weakest finger contorts to reach keys like `escape` and 
`backspace`. Exotic keyboards can remedy this, but lack portability.

`thumbledore` is a set of tweaks that is meant for keyboards with at 
least three keys per thumb, like the Corne, but that *also* fits within 
the constraints of a laptop keyboard.

-   **Each finger travels one key at most.** Your thumbs pick up the slack.
-   **Easy to remember.** There is only one additional layer for 
    symbols, one for navigation keys, and one for functions.
-   **Graceful degradation.** You can keep a somewhat consistent layout 
    even when you're stuck on a laptop keyboard.
-   **Progressive learning.** You don't have to learn everything all at 
    once --- or ever. Start with just the symbol layer, assigned to 
    `altgr`.
-   **One-handed control.** The number pad can be controlled with just 
    the right hand. Navigation keys that complement mouse actions can be 
    controlled with exclusively your left hand.
    (If your left hand is dominant, you may want to mirror some layers.)

The *power keys* are controlled with your thumbs. Their location depends 
on what's convenient based on your keyboard, hands, and habits. The 
*character keys* remain consistent across keyboards and are controlled 
with the remaining fingers.


## Power keys

Assuming you have at least 3 thumb keys on either hand, these are the 
power keys with their suggested locations:

1.  On the left-hand side, from left to right:
    1.  `meta`. This key accesses the **Nav/Meta** layer that contains 
        direction keys. The rest of this layer simply activates the 
        `meta`-modifier, useful for binding actions in your window 
        manager. The key gets an additional function when you *tap* 
        rather than hold it: it then triggers `escape`, useful for modal 
        applications like `vim`.
    2.  `space`.
    3.  `ctrl`. Tapping gets you `enter`, the logical counterpart to 
        `escape`. ^[Ideally, you can still get repeating enters by 
        double tapping and holding, but this isn't implemented 
        everywhere.]
2.  On the right hand, from right to left:
    1.  `shift`. This is technically a modifier, but you could also see 
        it as providing access to the **Shift** layer. It is a one-shot 
        key: when you tap it, it will be activated for the following 
        keypress.
    2.  `sym`. Accesses the **Symbol** layer for the remaining 
        characters. Also a one-shot key.
    3.  `alt`. Tapping it generates the `compose` key, allowing you to 
        type special characters by typing intuitive keys in succession 
        (e.g. `alt ' e` becomes `é`).

On a standard laptop keyboard, your thumbs hover over `alt_l`, `space` 
and `alt_r`, so for easy access, it makes sense to turn `alt_l` into 
`meta`, and `alt_r` into the `sym` key. The `shift` and `ctrl` keys can 
stay where they are. `alt` can be tucked away in the bottom left corner 
where the `meta` key was, left of the original `alt`.


## Character keys

There are 6x3 symbol keys for each hand.

#### ✎ Default layer

Don't worry, the default layer don't change much from what you're used 
to (be it QWERTY or something else). The major difference is that 
`capslock` becomes `backspace`, avoiding the huge move your pinky would 
usually make. Left shift, for compatibility with standard keyboards, 
will continue to function as `shift` when held, but it will emit the 
`compose` key when tapped. Right space becomes `delete`. Finally, the 
square brackets on the top right are dropped so that the backslash can 
scoot over.

    tab  q   w   e   r   t       y   u   i   o   p   \
    bsp  a   s   d   f   g       h   j   k   l   ;   '
    cmp  z   x   c   v   b       n   m   ,   .   /  del


#### ⇧ Shift

You're already familiar with one of the layers, too: the one exposed by 
*shift*.

    tab  Q   W   E   R   T       Y   U   I   O   P   |
    bsp  A   S   D   F   G       H   J   K   L   :   "
    cmp  Z   X   C   V   B       N   M   <   >   ?  del


#### ◇ Symbol

The *symbol* layer has been crammed full with the remaining symbols.

    tab  {   [   #   ]   }       ^   7   8   9   @   &
    bsp  (   *   -   =   )       ~   4   5   6   0   `
    cmp  !   +   _   $   /       %   1   2   3  .:  del

Because the symbol key is usually pressed with your right-hand thumb, 
the left-hand side is preferred for the most common symbols (according 
to personal usage) --- except for number pad, which can be controlled 
entirely with your right hand. There are two duplicate keys: `/` and 
`.`, which are also on the default layer but often needed in conjunction 
with numbers. For the same reason, you can get `:` by tapping `.` twice.


#### 🮰 Nav / Meta

    XXX hom  ↑  end pgu XXX     XXX XXX XXX XXX XXX XXX
    bsp  ←   ↓   →  pgd XXX     XXX XXX XXX XXX XXX XXX
    XXX clo men des lay XXX     XXX XXX XXX XXX XXX XXX

The meta/nav layer has a *navigation cluster* in the top right, placed 
so that you can control it with one hand. It contains directional keys, 
`home`/`end`, and `pageup`/`pagedown`.

The remaining keys on the left side are for navigating your window 
manager: `clo`sing a window, opening the `men`u, shifting the virtual 
`des`ktop, changing the window `lay`out.

The remaining keys act as if they were pressed with a `meta` modifier. 
This is convenient as the one key for all non-application-specific 
shortcuts that you might want to set.

For completeness, tapping `space` in this layer exposes the remaining 
keys that you might want to send with a `meta` modifier. For example, 
although pressing `meta+f` would generate `pgdn`, you can instead get to 
`meta+pgdn` via `meta+space+f`, while pressing `meta+space` and *then* 
`f` will send `meta+f`.


#### ✲ Function

Finally, the function layer can be reached by holding the `meta` and 
`sym` keys simultaneously. This layer contains the F keys, media 
controls, screen brightness, as well as toggles for wireless, touchpad, 
keyboard layout, headphones...

     📶  ⏮   🔊  ⏭   ◼  🔆     sclk f7  f8  f9 f12 srq
     🖰   ⏪  🔉  ⏩  ⏯  🔅     prsc f4  f5  f6 f11 ins
     ᛒᚼ  🎙️   🔇  🎧  ⏺  ⌨     paus f1  f2  f3 f10 del


## Usage

Install [keyd](https://github.com/rvaiya/keyd) (version >=2.3) and copy 
`keyd/default.conf` to `/etc/keyd/`.


## Other

-   [Seniply](https://stevep99.github.io/seniply/) has similar goals.

