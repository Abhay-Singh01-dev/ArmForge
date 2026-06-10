#include "armforge/attention.h"

#include "dispatch/dispatch_internal.h"
#include "validation/validation_internal.h"

namespace armforge
{
ArmForgeStatus armforge_flash_attn_fwd(const ArmForgeFlashAttentionParams* params)
{
    if (!validate_flash_attention_params(params))
    {
        return ARMFORGE_ERR_INVALID_ARGUMENT;
    }

    const ArmForgeKernelId kernel_id = select_flash_attention_kernel_internal(params);
    if (kernel_id == ARMFORGE_KERNEL_ID_NONE)
    {
        return ARMFORGE_ERR_UNSUPPORTED;
    }

    // TODO(Phase 03): Implement SVE2 Flash Attention forward path selection and
    // kernel execution for Neoverse V2.
    // Algorithm: tiled scaled dot-product attention with architecture-aware
    // packing and softmax reduction.
    // Dependencies: runtime feature detection, validated tensor descriptors, and
    // kernel registry plumbing.
    // Validation: unit coverage for shape checks, numerical reference parity,
    // and benchmark-backed integration tests on Graviton4.
    static_cast<void>(kernel_id);
    return ARMFORGE_ERR_UNSUPPORTED;
}
}  // namespace armforge
