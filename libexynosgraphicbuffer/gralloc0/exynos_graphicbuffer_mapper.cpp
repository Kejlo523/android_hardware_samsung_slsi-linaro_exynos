#include <ExynosGraphicBuffer.h>
#include <ui/Gralloc.h>

using namespace android;
using namespace vendor::graphics;

status_t ExynosGraphicBufferMapper::lock64(buffer_handle_t handle, uint64_t usage, const Rect &bounds, void **vaddr,
                                           int32_t *outBytesPerPixel, int32_t *outBytesPerStride) {
    if (outBytesPerPixel != nullptr)
        *outBytesPerPixel = -1;
    if (outBytesPerStride != nullptr)
        *outBytesPerStride = -1;
    return lockAsync(handle, usage, usage, bounds, vaddr, -1);
}

status_t ExynosGraphicBufferMapper::lockYCbCr64(buffer_handle_t handle, uint64_t usage, const Rect &bounds,
                                                android_ycbcr *ycbcr) {
    return getGrallocMapper().lock(handle, usage, bounds, -1, ycbcr);
}
