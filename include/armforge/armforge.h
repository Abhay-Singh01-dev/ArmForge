#ifndef ARMFORGE_ARMFORGE_H_
#define ARMFORGE_ARMFORGE_H_

#include "armforge/attention.h"
#include "armforge/config.h"
#include "armforge/dispatch.h"
#include "armforge/gemm.h"
#include "armforge/types.h"

namespace armforge
{
ARMFORGE_API ArmForgeStatus armforge_initialize();
ARMFORGE_API void armforge_shutdown();
ARMFORGE_API ArmForgeVersion armforge_get_version();
ARMFORGE_API const char* armforge_status_string(ArmForgeStatus status);
}  // namespace armforge

#endif  // ARMFORGE_ARMFORGE_H_

