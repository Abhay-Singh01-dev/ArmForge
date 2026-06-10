# Architecture Overview

## Design Intent

ArmForge is organized around stable public contracts and isolated internal
subsystems so that architecture-specific optimizations can be introduced
incrementally without repeated repository restructuring.

## Public Surface

- `include/armforge/config.h`: versioning and export controls
- `include/armforge/types.h`: ABI-level value and descriptor types
- `include/armforge/dispatch.h`: runtime inspection and kernel selection
- `include/armforge/attention.h`: Flash Attention API
- `include/armforge/gemm.h`: GEMM API
- `include/armforge/armforge.h`: umbrella include and lifecycle helpers

## Internal Subsystems

- `src/dispatch/`: capability probes and kernel selection policy
- `src/kernels/`: future registration and optimized implementations
- `src/packing/`: operand transforms for kernels
- `src/validation/`: precondition enforcement and reference checks

## Scaling Rationale

- Public headers stay minimal and stable.
- Internal helpers remain private to avoid ABI debt.
- Benchmarks and integrations are decoupled from the core library target.
- Tests cover contract behavior even before optimized implementations exist.

