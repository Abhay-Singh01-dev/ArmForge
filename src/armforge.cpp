#include "armforge/armforge.h"

#include "armforge/config.h"

namespace armforge
{
namespace
{
bool g_initialized = false;
}  // namespace

ArmForgeStatus armforge_initialize()
{
    g_initialized = true;
    return ARMFORGE_STATUS_SUCCESS;
}

void armforge_shutdown()
{
    g_initialized = false;
}

ArmForgeVersion armforge_get_version()
{
    return ArmForgeVersion{
        ARMFORGE_VERSION_MAJOR,
        ARMFORGE_VERSION_MINOR,
        ARMFORGE_VERSION_PATCH};
}

const char* armforge_status_string(const ArmForgeStatus status)
{
    switch (status)
    {
    case ARMFORGE_STATUS_SUCCESS:
        return "success";
    case ARMFORGE_ERR_INVALID_ARGUMENT:
        return "invalid argument";
    case ARMFORGE_ERR_UNSUPPORTED:
        return "unsupported";
    case ARMFORGE_ERR_NOT_INITIALIZED:
        return "not initialized";
    case ARMFORGE_ERR_INTERNAL:
        return "internal error";
    default:
        return "unknown status";
    }
}
}  // namespace armforge

