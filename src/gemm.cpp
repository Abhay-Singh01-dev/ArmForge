#include "armforge/gemm.h"

#include "dispatch/dispatch_internal.h"
#include "validation/validation_internal.h"

namespace armforge
{
ArmForgeStatus armforge_gemm_i8mm(const ArmForgeGemmParams* params)
{
    if (!validate_gemm_params(params))
    {
        return ARMFORGE_ERR_INVALID_ARGUMENT;
    }

    const ArmForgeKernelId kernel_id = select_gemm_kernel_internal(params);
    if (kernel_id == ARMFORGE_KERNEL_ID_NONE)
    {
        return ARMFORGE_ERR_UNSUPPORTED;
    }

    // TODO(Phase 05): Implement i8mm GEMM dispatch and execution path.
    // Algorithm: packed int8 GEMM with architecture-specific microkernel
    // selection and accumulation into int32 outputs.
    // Dependencies: packing subsystem, runtime i8mm capability detection, and
    // reference validation harness.
    // Validation: dimension edge cases, reference GEMM comparison, and
    // performance sanity checks on c8g.2xlarge.
    static_cast<void>(kernel_id);
    return ARMFORGE_ERR_UNSUPPORTED;
}
}  // namespace armforge
