#ifndef ARMFORGE_VALIDATION_INTERNAL_H_
#define ARMFORGE_VALIDATION_INTERNAL_H_

#include "armforge/types.h"

namespace armforge
{
bool validate_flash_attention_params(const ArmForgeFlashAttentionParams* params);
bool validate_gemm_params(const ArmForgeGemmParams* params);
}  // namespace armforge

#endif  // ARMFORGE_VALIDATION_INTERNAL_H_

