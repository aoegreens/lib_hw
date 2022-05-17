# AOE Greens Hardware Library

This library provides a consistent interface to common hardware-related routines across various micro-controllers.

We have provided this code to you in the hopes of making sustainable food production a world-wide reality. For more information on our open source software and how to reach us, please visit [https://aoegreens.com/about/](https://aoegreens.com/about/).

## Design

This library is [Developed With Biology](https://develop.bio). This means we follow all [eons conventions](https://eons.llc/convention/) and [Biology styles](https://github.com/develop-biology/lib_bio#style). 

The primary entry point to this code is the `PinController`. The PinController dynamically provisions the necessary hardware, whether the request be for GPIO, SPI, I2C, etc. 

## Building

This project depends on the [eons Basic Build System](https://github.com/eons-dev/bin_ebbs), which can be installed with `pip install ebbs`.  
With that said, this is just c++ code. Build it however you want.

Build using ebbs:
```
cd build
ebbs -c build_local.json
```

installation instructions coming soon (need package manager / repository semantics for module delivery)

## Docs

Documentation is on our TODO list and will be coming soon.
