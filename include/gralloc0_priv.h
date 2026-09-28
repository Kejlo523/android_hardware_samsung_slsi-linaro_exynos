#pragma once

// The legacy Exynos 7870 HWC1 and gralloc0 share this private handle ABI.
// Give HWC1 an unambiguous include name so a gralloc3 include directory
// earlier on the compiler command line cannot select the wrong handle.
#include "gralloc_priv.h"
