#include "armforge/armforge.h"

#include <cstdlib>

int main()
{
    using namespace armforge;

    const ArmForgeVersion version = armforge_get_version();
    if (version.major != 0 || version.minor != 1 || version.patch != 0)
    {
        return EXIT_FAILURE;
    }

    return armforge_initialize() == ARMFORGE_STATUS_SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE;
}

