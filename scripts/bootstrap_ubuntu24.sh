#!/usr/bin/env bash
set -euo pipefail

sudo apt-get update
sudo apt-get install -y --no-install-recommends \
  build-essential \
  cmake \
  g++-13 \
  gcc-13 \
  ninja-build \
  python3 \
  python3-pip

echo "ArmForge bootstrap complete."

