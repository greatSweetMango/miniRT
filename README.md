
# MiniRT

Mlx기반 레이트레이싱 시뮬레이션

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Installation
### 1. clone
```bash
git clone git@github.com:greatSweetMango/miniRT.git
```
### 2. build

single thread version :
```bash
make
```

multi thread version :
```bash
make bonus
```

If you want faster rendering, we recommend using the multi-thread version.
Instructions on how to install the project.

For other operations, please refer to the Makefile.

### 3. excute

In your shell, run the following command
```bash
./minirt $(scenefile)
```

ex.
```bash
./minirt scenes/cylinder.rt
```

## Usage
Use the files in the scene folder or create your own scene file.

scenes/cylinder.rt
[실린더 이미지]

이외 다른 이미지들

