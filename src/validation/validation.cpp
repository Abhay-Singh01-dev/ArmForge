#include "validation/validation_internal.h"

namespace armforge
{
namespace
{
bool validate_tensor_desc(const ArmForgeTensorDesc& desc)
{
    if (desc.rows <= 0 || desc.cols <= 0 || desc.stride <= 0)
    {
        return false;
    }

    return desc.dtype != ARMFORGE_DATA_TYPE_UNKNOWN &&
           desc.layout != ARMFORGE_LAYOUT_UNSPECIFIED;
}
}  // namespace

bool validate_flash_attention_params(const ArmForgeFlashAttentionParams* params)
{
    if (params == nullptr)
    {
        return false;
    }

    if (!validate_tensor_desc(params->query) || !validate_tensor_desc(params->key) ||
        !validate_tensor_desc(params->value) || !validate_tensor_desc(params->output))
    {
        return false;
    }

    return params->scale > 0.0F;
}

bool validate_gemm_params(const ArmForgeGemmParams* params)
{
    if (params == nullptr)
    {
        return false;
    }

    if (!validate_tensor_desc(params->lhs) || !validate_tensor_desc(params->rhs) ||
        !validate_tensor_desc(params->dst))
    {
        return false;
    }

    return params->m > 0 && params->n > 0 && params->k > 0;
}
}  // namespace armforge
