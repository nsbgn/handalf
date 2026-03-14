# 🧙 Handalf

*I only uploaded this so that it may serve as inspiration. It is still 
being tweaked. The README may not completely match the implementation. 
It currently only supports Linux.*

## Philosophy

Touch typing on a standard keyboard is not a great experience. Your 
thumbs idle while your weakest finger contorts to reach keys like 
<kbd>Esc</kbd> and <kbd>BkSp</kbd>. Numbers and other common symbols 
force your hands to abandon the home row entirely. Exotic keyboards can 
remedy all this, but lack portability.

Handalf is a keyboard layout scheme that works well for fancy 40% 
keyboards with 3 or more thumb keys per hand, but it *also* fits broadly 
within the constraints of a laptop keyboard.

![The Handalf keyboard layout on top of a Qwerty layout.](handalf.svg)

-   **Each finger travels one key at most.** Your thumbs pick up the 
    slack.
-   **Graceful degradation.** You can keep a consistent layout, even 
    when you're stuck on a laptop keyboard.
-   **Easy to learn & remember.** The alpha keys may not change from 
    what you're used to, and all other symbols are accessible with just 
    <kbd>AltGr</kbd> modifier. There is one additional layer beyond 
    that, for navigation and function keys, and, when combined with 
    <kbd>AltGr</kbd>, media keys. There's no need to learn it all at 
    once: I've found the symbols under <kbd>AltGr</kbd> to carry the 
    most ergonomic benefit.
-   **No homerow mods.** While typing at speed, keypresses will often 
    overlap, which means that any attempt at assigning multiple 
    functions to the spacebar or alpha keys must resort to timeouts. 
    This introduces [visual delay][pftwp] and can cause misfires. You 
    can train yourself and there are other [ways][urob] to mitigate it, 
    but I have not made such sacrifices here.
-   **Overloading is used sparingly.** Even for non-alpha keys, 
    overloading has the above downsides, albeit to a lesser degree. 
    Therefore, only a *single* key is given double duty, and it is done 
    judiciously.
-   **Stateless.** Modal editors are great, but only because they can 
    provide continuous feedback about the current mode. Without glancing 
    at the keyboard, the only association upon which your brain can 
    build is tactile: the physical position of your hands. Therefore, 
    the key sent to your computer will depend *only* on the keys you are 
    currently pressing, or, at most, which keys you were pressing some 
    fraction of a second ago.
-   **No key combo is left behind.** When stuffing so much functionality 
    into a cramped space, it is inevitable that some sequences of keys 
    will become harder to type. However, care has been taken to avoid 
    assumptions about the programs you will be running. That is: all 
    modifier combinations are available, and they should still stack in 
    an intuitive and consistent way.
-   **Complete.** A 42-key board should have access to all keys that you 
    might find on a standard tenkeyless keyboard.

Above all, the layout should *feel* good. Many ideals are taken into 
consideration, like simplicity, rolling motions, muscle memory, semantic 
clustering, symmetry, separating actions from symbols, etcetera --- but 
the final decision is based on vibes. A good mapping will almost 
immediately render its absence on other keyboards painful.

Unfortunately, Handalf is biased toward right-handed people. Let me know 
if you have a left-handed layout following the same principles.


## Symbol keys

![The symbol portion of the Handalf keyboard layout.](handalf-symbols.svg)

If you are currently using Colemak, Workman or good old Qwerty/Azerty, 
then all alpha keys can stay put. The major addition is that the 
**Level-3 symbols** on those keys (accessed through <kbd>AltGr</kbd>) 
have been crammed full with numbers and the other ASCII symbols.

> [!NOTE]
> The left-hand side of the keyboard now gives comfortable cross-hand 
> access to common symbols like parentheses, while the number pad can be 
> operated entirely with your right-hand.


## Action keys

![The action portion of the Handalf keyboard layout.](handalf-action.svg)

The key to the left of <kbd>Space</kbd>, what would have been your 
<kbd>Alt</kbd>, is now the <kbd>Fn</kbd> key. Here, the navigation 
cluster is placed so that you can control the directional keys with only 
your left hand. The F-keys are on the right-hand side.

> [!NOTE]
> Since the F-keys are not often used in modern applications, I use that 
> half for navigating the window manager. Should the F-keys be needed in 
> an application, there is a passthrough mode in my window manager.

In a multitude of operating systems and desktop environments, there 
exists a convention to assign global keybindings to the <kbd>Meta</kbd> 
key (also sometimes referred to as the *Super*, *Windows*, *Command* or 
*GUI*-key). Moreover, a tap on this key should bring up a global menu. 
This is achieved simply by pressing the remaining thumb key while in the 
**Fn** layer: <kbd>Space</kbd>.

The **Fn** layer also contains dedicated <kbd>Cut</kbd>, 
<kbd>Copy</kbd>, and <kbd>Paste</kbd> keys. These are convenient, not 
only because they keep the familiar keys in the same spot regardless of 
your underlying layout, but also because they can be used in terminal 
emulators (without throwing in a <kbd>Shft</kbd> to distinguish the `^C` 
signal from copying).

<!-- Add a compatibility mode that just uses C-c etc, for Windows? -->


### Media keys

![The media portion of the Handalf keyboard layout.](handalf-media.svg)

Numpad keys have been left out of the layout. Media control keys are 
obtained by combining the **Fn** layer with the <kbd>AltGr</kbd> 
modifier.


## Other tricks

### Backspace

<kbd>BkSp</kbd> takes the place of <kbd>CapsLk</kbd>, avoiding the huge 
move your pinky would have made.

### Sticky modifiers

<kbd>Shift</kbd> and <kbd>AltGr</kbd> are modifiers, but unlike 
<kbd>Ctrl</kbd> and <kbd>Alt</kbd>, they don't access shortcuts --- they 
simply provide more symbols. To make for a more comfortable typing 
experience, these keys are made *sticky* (or *oneshot*). Instead of 
holding and consciously releasing them *just* before pressing the next 
unmodified key, you can just tap once and forget about it. MUch better!

<!-- ### CapsLock and NumLock -->

<!-- Double tapping <kbd>Shift</kbd> on its own gets you <kbd>CapsLk</kbd> --> 
<!-- and double tapping <kbd>AltGr</kbd> gets you <kbd>NumLk</kbd>. -->

### Compose

The <kbd>Multi</kbd> key (also called *Compose*) allows you to type 
special characters by typing intuitive keys in succession. For example, 
<kbd>Multi</kbd><kbd>=</kbd><kbd>c</kbd> becomes `€`.

It is *virtual*, in the sense that there is no physical key that has 
this property by default. I have assigned it to the '102nd key', that 
is, the <kbd>\\</kbd> key that hangs out next to the left 
<kbd>Shift</kbd> on ISO keyboards.

It is accessible by tapping the <kbd>Fn</kbd> key while holding 
<kbd>Shift</kbd> or <kbd>AltGr</kbd>. This is convenient, because many 
subsequent symbols already require you to hold a modifier anyway.


### Left and right modifier variants

Modifiers are your thumbs' responsibility, because that makes it easy to 
combine them with other keys.

In general, it doesn't matter whether you press the right or left 
variant of a modifier, so we choose the left variant when the key occurs 
on the the left side of the thumb cluster (left <kbd>Alt</kbd> and left 
<kbd>Meta</kbd>) and the right variant when the key occurs on the right 
side (right <kbd>Shft</kbd>, right <kbd>AltGr</kbd>, and right 
<kbd>Ctrl<kbd>).

Left and right Alt are a special case, because they perform 
distinguishable functions. I refer to them by distinct names that 
minimize their handedness, and your thumbs are given direct access to 
both of them.

But we really do need both variants for all modifiers:

- Some tasks, like escaping a virtual machine, may involve tapping a 
  specific side.
- We want to accommodate typing inconvenient combinations in which one 
  of your thumbs is already occupied.
- We want to have a <kbd>Shift</kbd> on the left pinky still, because 
  sometimes it needs to be pressed while using the mouse.
- Left <kbd>Meta</kbd> is conveniently placed on a laptop keyboard, 
  because you can press <kbd>Fn</kbd> with your left thumb and 
  <kbd>Space</kbd> with your right one to generate <kbd>Meta</kbd>. But 
  saner keyboards where the right thumb can't reach <kbd>Space</kbd> 
  need a right <kbd>Meta</kbd> too.
- Most importantly, we want common shortcuts like 
  <kbd>Ctrl</kbd><kbd>c</kbd> and <kbd>Ctrl</kbd><kbd>f</kbd> to remain 
  easy to type, even if your right hand is on the mouse or if you're on 
  a laptop keyboard without a thumb key for <kbd>Ctrl</kbd>.

Therefore, in the **Fn** layer, your left and right pinkies access a 
sticky left <kbd>Ctrl</kbd> and right <kbd>Meta</kbd> respectively. The 
**Fn** layer itself is then temporarily disabled.

It does violate our design principles to hide a modifier behind another 
key. You can't combine these modifiers with other keys in **Fn**. And 
you may need to pause before typing complex combinations.

In this case, this an acceptable compromise, because these are 
second-class variants; their thumb cluster counterparts should be used 
for anything more complex.

<!-- You will often need a decimal point while typing numbers, but it is --> 
<!-- cumbersome to exit the symbol layer just to grab one and return. The --> 
<!-- same holds for the underscore when typing in all-caps. For this reason, --> 
<!-- double-tapping <kbd>Space</kbd> while holding <kbd>AltGr</kbd> will emit --> 
<!-- a decimal point (resulting in `.` or `,` depending on your locale), and --> 
<!-- doing so while holding <kbd>Shift</kbd> will emit an underscore `_`. --> 
<!-- **(TODO)** -->

<!-- You will usually use the arrows in the **Nav/Meta** layer while typing a --> 
<!-- sentence, but if you continue typing quickly, the **Meta** portion may --> 
<!-- still be active. For this reason, the right half will be disabled when --> 
<!-- pressing something in the **Nav/Meta** layer some milliseconds after --> 
<!-- using the arrow keys. **(TODO)** -->


## On overloading Escape

The <kbd>Fn</kbd> key occupies a very accessible location. Since it does 
not map to a conventional key anyway, you might be tempted, as I was, to 
give it double duty: emit another key when it is tapped in isolation. 
Particularly if you are a Vim user, <kbd>Esc</kbd> seems perfect for 
this. It is used frequently, and since it tends to punctuate a 
keystroke, the risk of accidentally triggering a <kbd>Fn</kbd>-hold is 
low.

Indeed, it is reasonable to take this approach. However, accidentally 
triggering <kbd>Esc</kbd> can be *really* annoying. Outside of Vim, it 
wreaks havoc by closing windows, losing focus on input fields, and 
erasing the spreadsheet formula you just typed.

That is why I have chosen to overload it with <kbd>Cancel</kbd> instead 
--- a key that is barely used and not even present on contemporary 
keyboards. Specific applications can then be explicitly configured to 
interpret this key in a useful way, so that the effect is limited to 
where it makes sense.[^1] In foot, you would put `\x1b = Cancel` in the 
`[text-bindings]` section, and in Alacritty, you would put `bindings = 
[{key = "Cancel", mods = "None", chars = "\u001b"}]` in the `[keyboard]` 
section.

[^1]: You could even directly configure (Neo)Vim itself to interpret 
    your special key (see 
    [key-notation](https://neovim.io/doc/user/intro.html#_keycodes)), 
    but since most terminal emulators do not support wacky keys (cf. 
    `terminfo`), you would need to use another key.


## On Alt-Tab

Many computer users will have muscle memory associated with 
<kbd>Alt</kbd><kbd>Tab</kbd>, so pressing <kbd>Tab</kbd> in the **Fn** 
layer will still emit exactly that. It will also keep the <kbd>Alt</kbd> 
modifier active until you either exit the **Fn** layer, or press another 
key in the **Fn** layer --- this keeps the overview of windows up, just 
as they would if you keep holding <kbd>Alt</kbd>.

<!-- ## Keysyms -->

<!-- When you press a key, your keyboard will send a *scancode* to the --> 
<!-- computer; the kernel maps that to a *keycode*; and finally, your --> 
<!-- keyboard layout considers that keycode (along with the active modifiers) --> 
<!-- and emits a *keysym*. -->

<!-- By default, Handalf remaps *symbols* at this keysym level, while other --> 
<!-- keys are mapped at the scan- or keycode-level. Teasing the two apart --> 
<!-- like this has several benefits: -->

<!-- - At the scan- and keycode-level, more tricks can be applied, like --> 
<!--   overloading. -->
<!-- - But at the keysym-level, your OS is aware of your active layout. You --> 
<!--   can switch between them in the standard way, with some visual --> 
<!--   indication. -->
<!-- - It becomes easier to reason about key composition. We don't have to --> 
<!--   explicitly write and remember rules for how layers and modifiers --> 
<!--   combine. Suppose, for example, you want to type --> 
<!--   <kbd>Meta</kbd><kbd>1</kbd>: the first key would be <kbd>&#9680;</kbd> --> 
<!--   and the second would be <kbd>AltGr</kbd><kbd>n</kbd>. -->
<!-- - For layout-independent keybindings in your window manager, it is --> 
<!--   important that emitted keycodes stay the same even as symbols change. -->

<!-- Holding <kbd>Shift</kbd> and <kbd>AltGr</kbd> together does not change --> 
<!-- the keysyms, but it does change the keycode. This is helpful in --> 
<!-- applications that read keycodes rather than keysyms, or when you use a --> 
<!-- system in which the layout is not installed. -->


## Usage and installation

Install [keyd](https://github.com/rvaiya/keyd) (version >=2.3) and run 
`sudo make install`. Activate the `handalf` layout in your environment.


## Notes on modifiers and layers

Modifiers are keys like <kbd>Shift</kbd>, <kbd>AltGr</kbd>, 
<kbd>Control</kbd>, <kbd>Alt</kbd>, and <kbd>Meta</kbd>. These keys are 
sent along with the key you press to modify their behaviour. A layer key 
like <kbd>Fn</kbd> is similar, but it modifies the key directly, before 
it even reaches your desktop environment.

You can rearrange the alphanumeric keys and action keys internally, and 
while some arrangements will be more comfortable than others, it will 
not lead to a fundamentally different typing experience. The same can 
not be said for modifier and layer keys. These keys can be *overloaded*, 
and it is to be expected that they are sometimes pressed in 
*conjunction*. I considered several permutations, landing on the 
following rules:

- The order in which you press modifiers and layers should not matter. 
  That is, holding <kbd>Fn</kbd> and then <kbd>Alt</kbd> should have the 
  same effect as the other way around.
- You should not have to press more than one key to activate a layer or 
  modifier.
- All modifier and layer keys should be on the thumb.
- It should be assumed that the fingers are in the home row position; 
  shifting your fingers a column or row is not always comfortable on 
  sculpted keyboards like the Kinesis Advantage, MoErgo Glove80, Dactyl, 
  or Keyboardio Model 100.
  <!-- (Dropping this requirement, along with the one preceding it, allows an --> 
  <!-- interesting variant where the pinky activates a layer in which the --> 
  <!-- arrow keys are on WASD. This works well on laptop keyboards, and frees --> 
  <!-- up a thumb key for <kbd>Ctrl</kbd>.) -->

<!--
## Notes on switching between alphanumeric layouts

I reckon it's a good idea to use Colemak-DH on ortholinear boards, while 
using Qwerty on anything else. This allows your brain to lock into the 
right layout based on what your fingers are feeling.

Perhaps encouraging the use of different layouts for different keyboards 
feels somewhat contradictory to Handalf's stated goal of universality, 
so here I will introduce some nuance: Handalf is a universal *base* that 
makes it easy to mentally compartmentalize the atomic changes that you 
*do* make.

When you switch between Qwerty and Colemak, everything except the alpha 
keys will stay the same. And because the remapping happens on the XKB 
level, you can have visual feedback, and your window manager's shortcuts 
can remain unaffected.
-->

<!--
- When overloading a modifier, take care of potential misfires: choose 
  'tap' actions that are not destructive, and make sure that the 'hold' 
  actions are also safe. This is easier to do when associating the 
  overloaded key with Window Manager actions.
-->

### Keyboard controls

Keystrokes for keyboard control, such as Bluetooth connectivity, should 
not obscure any keystroke meant for the connected device. For that 
reason, they are hidden away behind *combinations* of keys on the same 
column. To avoid incurring any lag, this is further limited to when all 
left thumb controls are simultaneously pressed (that is, when the 
<kbd>Alt</kbd> and <kbd>Meta</kbd> modifiers as well as the **Fn** layer 
are simultaneously activated).

<!--
## Other

[Seniply] and [Callum] have similar goals: limited keys and no home-row 
mods.

# Consideration for the thumb keys

-   All thumb keys except space are modifiers or layer keys, because you 
    have full range of motion with the rest of your fingers while 
    holding them.
-   Since we avoid crazy modifier combinations, `sym` and `shift` never 
    make sense to press together. Therefore, they should be on the same 
    finger.
-   `space` should be opposite from  `shift` and `sym`, so that you can 
    still use it while in their respective modes.

-->

<!-- Reading -->
[Preconditions-Guide]: https://precondition.github.io/home-row-mods
[Urob]: https://github.com/urob/zmk-config#timeless-homerow-mods
<!-- About visual latency -->
[pftwp]: https://pavelfatin.com/typing-with-pleasure/#human-side

<!-- Layouts -->
[Colemak-DH]: https://colemakmods.github.io/mod-dh/
[Workman]: https://workmanlayout.org/

<!-- More layouts -->
[Seniply]: https://stevep99.github.io/seniply/
[Callum]: https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum
[Miryoku]: https://github.com/manna-harbour/miryoku
