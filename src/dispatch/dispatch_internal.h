#ifndef ARMFORGE_DISPATCH_INTERNAL_H_
#define ARMFORGE_DISPATCH_INTERNAL_H_

#include "armforge/types.h"

namespace armforge
{
ArmForgeKernelId select_flash_attention_kernel_internal(const ArmForgeFlashAttentionParams* params);
ArmForgeKernelId select_gemm_kernel_internal(const ArmForgeGemmParams* params);
}  // namespace armforge

#endif  // ARMFORGE_DISPATCH_INTERNAL_H_

