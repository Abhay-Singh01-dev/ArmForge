# Docker

`Dockerfile.dev` provides a minimal Ubuntu 24.04 environment aligned with the
Phase-00 build contract. It is intended for local reproduction and CI debugging,
not as a deployment image.

Example:

```bash
docker build -f docker/Dockerfile.dev -t armforge-dev .
docker run --rm -it -v "$PWD:/workspace" armforge-dev
```

