#ifndef ARMFORGE_GEMM_H_
#define ARMFORGE_GEMM_H_

#include "armforge/config.h"
#include "armforge/types.h"

namespace armforge
{
ARMFORGE_API ArmForgeStatus armforge_gemm_i8mm(const ArmForgeGemmParams* params);
}  // namespace armforge

#endif  // ARMFORGE_GEMM_H_

