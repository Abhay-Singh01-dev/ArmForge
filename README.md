# ArmForge

ArmForge is a production-oriented optimization repository for AWS Graviton4
focused on four long-horizon workstreams:

- SVE2 Flash Attention
- i8mm GEMM
- runtime dispatch and capability detection
- llama.cpp and Arm Performix integration

Phase-00 establishes the repository contract, public APIs, build graph,
validation scaffolding, CI, packaging metadata, and operating conventions.
It intentionally does not ship optimized kernels or benchmark execution logic.

## Scope

This repository targets the Arm AI Optimization Challenge 2026 Cloud AI track
on `c8g.2xlarge` instances powered by Neoverse V2. The reference toolchain is:

- Ubuntu 24.04
- GCC 13
- CMake
- C++17
- Python 3.11+

## Phase-00 Guarantees

- Clean configure and build with `cmake -B build` and `cmake --build build`
- Stable public header surface for future phases
- Compilable stub implementations with explicit phase ownership
- Directory layout that scales across kernels, packing, validation, dispatch,
  benchmarking, and external integrations
- Baseline CI, Docker, contributor, and citation metadata

## Repository Layout

```text
.
├── .github/                  GitHub automation and issue templates
├── benchmarks/               Benchmark configs and orchestration scaffolding
├── cmake/                    Reusable CMake modules
├── docker/                   Reproducible development container definitions
├── docs/                     Architecture, build, and phase planning docs
├── include/armforge/         Stable public C and C++ compatible API headers
├── llama.cpp-integration/    Upstream integration planning and patch staging
├── models/                   Model metadata and local model placement guidance
├── python/armforge/          Python package skeleton and metadata surface
├── research/                 Design notes and experiment intake point
├── results/                  Benchmark and validation artifact landing area
├── scripts/                  Project automation scripts
├── src/                      Library sources and internal subsystem seams
└── tests/                    Unit and integration smoke coverage
```

## Build

```bash
cmake -B build -S .
cmake --build build
ctest --test-dir build --output-on-failure
```

## Non-Goals in Phase-00

- No SVE2 kernel implementation
- No i8mm microkernel implementation
- No Flash Attention algorithm implementation
- No llama.cpp patch payloads
- No benchmark runner that claims performance numbers

## API Direction

The exported C API is intentionally narrow:

- lifecycle and versioning
- runtime capability queries
- flash attention entry points
- GEMM entry points
- dispatch introspection

This keeps future kernel work isolated behind stable contracts while preserving
room for internal ABI changes.

## Development Principles

- Keep architecture-specific code behind validated dispatch boundaries
- Add implementation only when tests and validation strategy are defined
- Prefer incremental, reviewable changes over bulk feature drops
- Preserve buildability at every phase

## Documentation Map

- [Build Guide](docs/build.md)
- [Architecture Overview](docs/architecture.md)
- [Phase Plan](docs/phase-plan.md)
- [Benchmark Strategy](benchmarks/README.md)

## License

ArmForge is released under the MIT License. See [LICENSE](LICENSE).

