#include "armforge/dispatch.h"

#include <cstring>

#include "dispatch/dispatch_internal.h"
#include "validation/validation_internal.h"

namespace armforge
{
ArmForgeStatus armforge_query_runtime(ArmForgeRuntimeInfo* runtime_info)
{
    if (runtime_info == nullptr)
    {
        return ARMFORGE_ERR_INVALID_ARGUMENT;
    }

    runtime_info->detected_features = ARMFORGE_CPU_FEATURE_NONE;
    std::strncpy(runtime_info->cpu_name, "generic-aarch64", sizeof(runtime_info->cpu_name) - 1U);
    runtime_info->cpu_name[sizeof(runtime_info->cpu_name) - 1U] = '\0';

    // TODO(Phase 02): Replace the generic runtime descriptor with Linux-based
    // feature probing for SVE2 and i8mm on Neoverse V2.
    // Algorithm: inspect hwcaps and normalized CPU identification metadata.
    // Dependencies: platform capability helpers and portable fallback paths.
    // Validation: deterministic unit tests plus on-host verification on
    // Graviton4.
    return ARMFORGE_STATUS_SUCCESS;
}

ArmForgeStatus armforge_select_flash_attention_kernel(
    const ArmForgeFlashAttentionParams* params,
    ArmForgeKernelId* kernel_id)
{
    if (!validate_flash_attention_params(params) || kernel_id == nullptr)
    {
        return ARMFORGE_ERR_INVALID_ARGUMENT;
    }

    *kernel_id = select_flash_attention_kernel_internal(params);
    return (*kernel_id == ARMFORGE_KERNEL_ID_NONE) ? ARMFORGE_ERR_UNSUPPORTED
                                                   : ARMFORGE_STATUS_SUCCESS;
}

ArmForgeStatus armforge_select_gemm_kernel(
    const ArmForgeGemmParams* params,
    ArmForgeKernelId* kernel_id)
{
    if (!validate_gemm_params(params) || kernel_id == nullptr)
    {
        return ARMFORGE_ERR_INVALID_ARGUMENT;
    }

    *kernel_id = select_gemm_kernel_internal(params);
    return (*kernel_id == ARMFORGE_KERNEL_ID_NONE) ? ARMFORGE_ERR_UNSUPPORTED
                                                   : ARMFORGE_STATUS_SUCCESS;
}

ArmForgeKernelId select_flash_attention_kernel_internal(const ArmForgeFlashAttentionParams* params)
{
    static_cast<void>(params);

    // TODO(Phase 02): Implement feature-aware kernel registry lookup for flash
    // attention forward kernels.
    // Algorithm: dispatch table keyed by datatype, sequence geometry, and CPU
    // capabilities.
    // Dependencies: runtime probing, kernel registration metadata, and
    // validation policies.
    // Validation: dispatch matrix tests covering supported and unsupported
    // combinations.
    return ARMFORGE_KERNEL_ID_NONE;
}

ArmForgeKernelId select_gemm_kernel_internal(const ArmForgeGemmParams* params)
{
    static_cast<void>(params);

    // TODO(Phase 02): Implement feature-aware kernel registry lookup for i8mm
    // GEMM kernels.
    // Algorithm: dispatch table keyed by operand layout, shape classes, and CPU
    // capabilities.
    // Dependencies: runtime probing, packing metadata, and kernel registry.
    // Validation: dispatch unit tests plus integration coverage with the future
    // reference GEMM path.
    return ARMFORGE_KERNEL_ID_NONE;
}
}  // namespace armforge
