#ifndef ARMFORGE_TYPES_H_
#define ARMFORGE_TYPES_H_

#include <cstddef>
#include <cstdint>

namespace armforge
{
enum ArmForgeStatus : std::int32_t
{
    ARMFORGE_STATUS_SUCCESS = 0,
    ARMFORGE_ERR_INVALID_ARGUMENT = 1,
    ARMFORGE_ERR_UNSUPPORTED = 2,
    ARMFORGE_ERR_NOT_INITIALIZED = 3,
    ARMFORGE_ERR_INTERNAL = 4
};

enum ArmForgeDataType : std::int32_t
{
    ARMFORGE_DATA_TYPE_UNKNOWN = 0,
    ARMFORGE_DATA_TYPE_F16 = 1,
    ARMFORGE_DATA_TYPE_F32 = 2,
    ARMFORGE_DATA_TYPE_I8 = 3,
    ARMFORGE_DATA_TYPE_I32 = 4
};

enum ArmForgeLayout : std::int32_t
{
    ARMFORGE_LAYOUT_UNSPECIFIED = 0,
    ARMFORGE_LAYOUT_ROW_MAJOR = 1,
    ARMFORGE_LAYOUT_COLUMN_MAJOR = 2
};

enum ArmForgeKernelId : std::int32_t
{
    ARMFORGE_KERNEL_ID_NONE = 0,
    ARMFORGE_KERNEL_ID_REFERENCE = 1,
    ARMFORGE_KERNEL_ID_SVE2_FLASH_ATTN_FWD = 2,
    ARMFORGE_KERNEL_ID_I8MM_GEMM = 3
};

enum ArmForgeCpuFeature : std::uint64_t
{
    ARMFORGE_CPU_FEATURE_NONE = 0ULL,
    ARMFORGE_CPU_FEATURE_SVE2 = 1ULL << 0U,
    ARMFORGE_CPU_FEATURE_I8MM = 1ULL << 1U
};

struct ArmForgeVersion
{
    std::int32_t major;
    std::int32_t minor;
    std::int32_t patch;
};

struct ArmForgeRuntimeInfo
{
    std::uint64_t detected_features;
    char cpu_name[64];
};

struct ArmForgeTensorDesc
{
    void* data;
    std::int64_t rows;
    std::int64_t cols;
    std::int64_t stride;
    ArmForgeDataType dtype;
    ArmForgeLayout layout;
};

struct ArmForgeFlashAttentionParams
{
    ArmForgeTensorDesc query;
    ArmForgeTensorDesc key;
    ArmForgeTensorDesc value;
    ArmForgeTensorDesc output;
    float scale;
    bool causal;
};

struct ArmForgeGemmParams
{
    ArmForgeTensorDesc lhs;
    ArmForgeTensorDesc rhs;
    ArmForgeTensorDesc dst;
    std::int64_t m;
    std::int64_t n;
    std::int64_t k;
};
}  // namespace armforge

#endif  // ARMFORGE_TYPES_H_

