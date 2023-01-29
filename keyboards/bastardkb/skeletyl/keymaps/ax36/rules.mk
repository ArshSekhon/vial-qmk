VIA_ENABLE = yes
VIAL_ENABLE = yes
VIAL_INSECURE = yes

MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
AUTO_SHIFT_ENABLE = yes # Auto Shift
DYNAMIC_MACRO_ENABLE = yes

SRC += oneshot/oneshot.c
SRC += os_specific/os_specific.c
SRC += rgb/rgb.c
