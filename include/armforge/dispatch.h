#ifndef ARMFORGE_DISPATCH_H_
#define ARMFORGE_DISPATCH_H_

#include "armforge/config.h"
#include "armforge/types.h"

namespace armforge
{
ARMFORGE_API ArmForgeStatus armforge_query_runtime(ArmForgeRuntimeInfo* runtime_info);

ARMFORGE_API ArmForgeStatus armforge_select_flash_attention_kernel(
    const ArmForgeFlashAttentionParams* params,
    ArmForgeKernelId* kernel_id);

ARMFORGE_API ArmForgeStatus armforge_select_gemm_kernel(
    const ArmForgeGemmParams* params,
    ArmForgeKernelId* kernel_id);
}  // namespace armforge

#endif  // ARMFORGE_DISPATCH_H_

