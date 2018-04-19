# TI TIVA: development platform for [PlatformIO](http://platformio.org)
[![Build Status](https://travis-ci.org/platformio/platform-titiva.svg?branch=develop)](https://travis-ci.org/platformio/platform-titiva)
[![Build status](https://ci.appveyor.com/api/projects/status/x7y7i3tqylwpgn98/branch/develop?svg=true)](https://ci.appveyor.com/project/ivankravets/platform-titiva/branch/develop)

Texas Instruments TM4C12x MCUs offer the industrys most popular ARM Cortex-M4 core with scalable memory and package options, unparalleled connectivity peripherals, advanced application functions, industry-leading analog integration, and extensive software solutions.

* [Home](http://platformio.org/platforms/titiva) (home page in PlatformIO Platform Registry)
* [Documentation](http://docs.platformio.org/page/platforms/titiva.html) (advanced usage, packages, boards, frameworks, etc.)

# Usage

1. [Install PlatformIO](http://platformio.org)
2. Create PlatformIO project and configure a platform option in [platformio.ini](http://docs.platformio.org/page/projectconf.html) file:

## Stable version

```ini
[env:stable]
platform = titiva
board = ...
...
```

## Development version

```ini
[env:development]
platform = https://github.com/platformio/platform-titiva.git
board = ...
...
```

# Configuration

Please navigate to [documentation](http://docs.platformio.org/page/platforms/titiva.html).

