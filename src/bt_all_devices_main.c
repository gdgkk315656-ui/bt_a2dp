#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int (*orig_sceBtConnect)(int device_id) = NULL;

int hooked_sceBtConnect(int device_id) {
    int ret = 0;
    if (orig_sceBtConnect) {
        ret = orig_sceBtConnect(device_id);
    }

    if (ret >= 0) {
        printf("[BT_UNIVERSAL] Connected Successfully! Device ID: %d\n", device_id);
    } else {
        printf("[BT_UNIVERSAL] Connected Failed!!! Error Code: 0x%X\n", ret);
    }

    return ret;
}

void __attribute__((constructor)) bt_universal_init(void) {
    printf("[BT_UNIVERSAL] Universal Bluetooth Whitelist Bypass & Hook Loaded.\n");
}

void __attribute__((destructor)) bt_universal_fini(void) {
    printf("[BT_UNIVERSAL] Unloaded.\n");
}
