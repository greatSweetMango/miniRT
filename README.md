
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
<img width="1099" alt="스크린샷 2024-03-17 오전 12 33 31" src="https://github.com/greatSweetMango/miniRT/assets/93255519/936da060-73ee-45b9-947d-1c96f8a51800">


and other scenes...

<img width="1103" alt="스크린샷 2024-03-17 오전 12 36 29" src="https://github.com/greatSweetMango/miniRT/assets/93255519/60b10cab-74de-48e8-986e-bb872698a44c">
<img width="1098" alt="스크린샷 2024-03-17 오전 12 31 53" src="https://github.com/greatSweetMango/miniRT/assets/93255519/c7f74725-05ce-46f9-89c7-083fda61497e">
<img width="1099" alt="스크린샷 2024-03-17 오전 12 27 35" src="https://github.com/greatSweetMango/miniRT/assets/93255519/e8e2d618-8566-4975-aed6-002931747edd">
<img width="1103" alt="스크린샷 2024-03-17 오전 12 27 00" src="https://github.com/greatSweetMango/miniRT/assets/93255519/d89e39bb-dd73-4d1b-9f8e-70a2a22488ed">
<img width="1094" alt="스크린샷 2024-03-17 오전 12 25 51" src="https://github.com/greatSweetMango/miniRT/assets/93255519/3c3e592c-8f0c-4c00-bcf0-cd25b8dab35d">

