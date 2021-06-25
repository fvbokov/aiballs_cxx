rm -rf "build" &&
cmake -S . -B "build" \
    -G "Ninja Multi-Config" \
    -D CMAKE_CONFIGURATION_TYPES="Debug;Release" \
    -D CMAKE_EXPORT_COMPILE_COMMANDS=1 \
    -D CMAKE_TOOLCHAIN_FILE="~/vcpkg/scripts/buildsystems/vcpkg.cmake" \
    -D VCPKG_TARGET_TRIPLET="x64-windows-static"