#include <ExynosGraphicBufferCore.h>
#include <log/log.h>
#include <gralloc_priv.h>

using namespace vendor::graphics;

int ExynosGraphicBufferMeta::set_dataspace(buffer_handle_t, android_dataspace_t) {
    // Gralloc0 has no shared dataspace metadata region.
    return 0;
}

void *ExynosGraphicBufferMeta::get_video_metadata(buffer_handle_t handle) {
    const private_handle_t *hnd = static_cast<const private_handle_t *>(handle);
    if (hnd == nullptr)
        return nullptr;

    if (hnd->fd2 >= 0 && hnd->base2 != 0)
        return reinterpret_cast<void *>(hnd->base2);
    if (hnd->fd1 >= 0 && hnd->base1 != 0)
        return reinterpret_cast<void *>(hnd->base1);
    return nullptr;
}

void ExynosGraphicBufferMeta::init(const buffer_handle_t handle) {
    const private_handle_t *hnd = static_cast<const private_handle_t *>(handle);
    if (hnd == nullptr)
        return;

    fd = hnd->fd;
    fd1 = hnd->fd1;
    fd2 = hnd->fd2;
    size = hnd->size;
    size1 = hnd->size1;
    size2 = hnd->size2;
    internal_format = hnd->internal_format;
    frameworkFormat = hnd->frameworkFormat;
    width = hnd->width;
    height = hnd->height;
    stride = hnd->stride;
    vstride = hnd->vstride;
    flags = hnd->flags;
}

ExynosGraphicBufferMeta::ExynosGraphicBufferMeta(buffer_handle_t handle) {
    init(handle);
}
