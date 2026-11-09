TARGET = bt_all_devices.prx
OBJS = src/bt_all_devices_main.o

PREFIX ?= $(PS4SDK)
include $(PREFIX)/make/ps4lib.mk
