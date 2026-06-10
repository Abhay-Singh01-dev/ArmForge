#include "armforge/armforge.h"

#include <cstdlib>

int main()
{
    using namespace armforge;

    ArmForgeRuntimeInfo runtime_info{};
    if (armforge_query_runtime(&runtime_info) != ARMFORGE_STATUS_SUCCESS)
    {
        return EXIT_FAILURE;
    }

    ArmForgeTensorDesc desc{};
    desc.data = nullptr;
    desc.rows = 1;
    desc.cols = 1;
    desc.stride = 1;
    desc.dtype = ARMFORGE_DATA_TYPE_F16;
    desc.layout = ARMFORGE_LAYOUT_ROW_MAJOR;

    ArmForgeFlashAttentionParams attention_params{desc, desc, desc, desc, 1.0F, false};
    ArmForgeGemmParams gemm_params{desc, desc, desc, 1, 1, 1};

    if (armforge_flash_attn_fwd(&attention_params) != ARMFORGE_ERR_UNSUPPORTED)
    {
        return EXIT_FAILURE;
    }

    if (armforge_gemm_i8mm(&gemm_params) != ARMFORGE_ERR_UNSUPPORTED)
    {
        return EXIT_FAILURE;
    }

    ArmForgeKernelId kernel_id = ARMFORGE_KERNEL_ID_REFERENCE;
    if (armforge_select_flash_attention_kernel(&attention_params, &kernel_id) !=
        ARMFORGE_ERR_UNSUPPORTED)
    {
        return EXIT_FAILURE;
    }

    if (armforge_select_gemm_kernel(&gemm_params, &kernel_id) != ARMFORGE_ERR_UNSUPPORTED)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

