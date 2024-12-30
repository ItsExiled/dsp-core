#include <libusb-1.0/libusb.h>
#include <iostream>

int main () {
    libusb_context *ctx;
    libusb_device **list;
    ssize_t count;

    libusb_init(&ctx);
    count = libusb_get_device_list(ctx, &list);

    if (count < 0) {
        std::cerr << "Error getting device list" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < count; i++) {
        libusb_device *device = list[i];
        libusb_device_descriptor desc;
        libusb_get_device_descriptor(device, &desc);

        std::cout << "Device " << i << ":" << std::endl;
        std::cout << "  Vendor ID:  " << std::hex << desc.idVendor << std::endl;
        std::cout << "  Product ID: " << std::hex << desc.idProduct << std::endl;
        // ... get more device information ...
    }

    libusb_free_device_list(list, 1);
    libusb_exit(ctx);
    return 0;
}