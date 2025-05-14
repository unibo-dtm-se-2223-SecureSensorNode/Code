#!/bin/bash

BUILD_DIR=client/firmware/Debug
PROJECT_NAME=BlinkHAL

echo "[1] Building the project..."
make -C $BUILD_DIR all

if [ ! -f $BUILD_DIR/${PROJECT_NAME}.elf ]; then
  echo "[!] Build failed or ELF file not found!"
  exit 1
fi

echo "[2] Creating binary image..."
arm-none-eabi-objcopy -O binary $BUILD_DIR/${PROJECT_NAME}.elf $BUILD_DIR/${PROJECT_NAME}.bin

echo "[3] Flashing firmware via st-flash..."
st-flash write $BUILD_DIR/${PROJECT_NAME}.bin 0x08000000

echo "[✓] Flash completed successfully!"
