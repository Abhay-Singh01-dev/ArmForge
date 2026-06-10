#include "armforge/types.h"

namespace armforge
{
namespace kernels
{
ArmForgeStatus register_builtin_kernels_stub()
{
    // TODO(Phase 02): Introduce a kernel registry for reference, SVE2, and i8mm
    // implementations without coupling public headers to internal kernel types.
    // Algorithm: static registration table with feature tags and validation
    // requirements.
    // Dependencies: dispatch subsystem and kernel metadata definitions.
    // Validation: registry enumeration tests and unsupported-path coverage.
    return ARMFORGE_ERR_UNSUPPORTED;
}
}  // namespace kernels
}  // namespace armforge

