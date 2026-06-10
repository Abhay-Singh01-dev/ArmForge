#ifndef ARMFORGE_ATTENTION_H_
#define ARMFORGE_ATTENTION_H_

#include "armforge/config.h"
#include "armforge/types.h"

namespace armforge
{
ARMFORGE_API ArmForgeStatus armforge_flash_attn_fwd(const ArmForgeFlashAttentionParams* params);
}  // namespace armforge

#endif  // ARMFORGE_ATTENTION_H_

