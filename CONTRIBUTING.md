# Contributing to ArmForge

## Objectives

ArmForge is being built in phases. Contributions must preserve:

- clean builds on Ubuntu 24.04
- reviewable architecture boundaries
- reproducible validation paths
- explicit ownership of performance claims

## Ground Rules

1. Keep Phase-00 constraints intact until the corresponding implementation phase
   explicitly authorizes a new subsystem.
2. Do not land architecture-specific kernel code without:
   - validation coverage
   - fallback behavior
   - benchmark methodology
   - documentation updates
3. Keep public headers stable and versioned with care.
4. Prefer additive changes over structural churn.

## Development Workflow

1. Create a topic branch.
2. Configure and build locally.
3. Run tests.
4. Update documentation for any public-facing or workflow change.
5. Submit a pull request with rationale, risks, and validation notes.

## Commit Guidance

- Use clear, imperative commit messages.
- Separate refactors from behavior changes when possible.
- Avoid bundling generated artifacts unless explicitly required.

## Code Style

- C++17
- `clang-format` using the repository configuration
- CMake with explicit target properties and options
- Python 3.11+ for scripts and package scaffolding

## Validation Expectations

At minimum, changes touching compiled code should run:

```bash
cmake -B build -S .
cmake --build build
ctest --test-dir build --output-on-failure
```

## Reporting Performance

Do not claim performance gains without:

- hardware details
- compiler version and flags
- benchmark configuration
- baseline reference
- reproducible command lines

## Communication

Open an issue for architectural changes before starting large implementation
work. This is especially important for dispatch policy, API changes, and
llama.cpp integration strategy.

