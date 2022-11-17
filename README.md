
[![GitHub license](https://img.shields.io/github/license/berrak/SolderFumeFanExtractor.svg?logo=gnu&logoColor=ffffff)](https://github.com/berrak/SolderFumeFanExtractor/blob/master/LICENSE)
[![Installation instructions](https://www.ardu-badge.com/badge/SolderFumeFanExtractor.svg?)](https://www.ardu-badge.com/SolderFumeFanExtractor)
[![GitHub version](https://img.shields.io/github/release/berrak/SolderFumeFanExtractor.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/SolderFumeFanExtractor/releases/latest)
[![GitHub Release Date](https://img.shields.io/github/release-date/berrak/SolderFumeFanExtractor.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/SolderFumeFanExtractor/releases/latest)
[![GitHub stars](https://img.shields.io/github/stars/berrak/SolderFumeFanExtractor.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/SolderFumeFanExtractor/stargazers)
[![GitHub issues](https://img.shields.io/github/issues/berrak/SolderFumeFanExtractor.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/SolderFumeFanExtractor/issues)
[![Documentation](https://img.shields.io/badge/documentation-doxygen-green.svg)](http://berrak.github.io/SolderFumeFanExtractor/)
![Badge Hit Counter](https://visitor-badge.laobi.icu/badge?page_id=berrak_SolderFumeFanExtractor)

# Arduino library SolderFumeFanExtractor

Download or install the `SolderFumeFanExtractor` library to easily interact with the build described by the [Hackaday](https://hackaday.io/project/187925-solder-fume-extraction-station-deluxe-from-scrap) project. There are many projects with this intent, but without proper filtering, blowing around the fumes/particles in the room is only a minor improvement. Furthermore, with the increased popularity of DIY reflow solutions from a `toaster oven` or a `hotplate`, vast amounts of unhealthy fumes and particles are released close to the user. The project uses HEPA and active carbon filters to improve air quality.

The code is tested on ESP8266 and ESP32 microcontrollers.

Find all created circuit boards for the `fume extractor` in the `KiCad` [repository](https://github.com/berrak/solder-fume-extractor-hw).

## What is the content of this repository?

- The `examples` folder is for the final released code.
- The `src` folder is the library source for the `final code`.
- The `extras` folder contains small Arduino samples of code which have been used for the development of the main software.

The last folder may also contain other useful information.

## Run the example

TBD

## Documentation (GitHub Pages - Doxygen) - TBD

[Library documentation](https://berrak.github.io/SolderFumeFanExtractor/classSolderFumeFanExtractor.html).

## How to Install

Click on the green `Library Manager` badge above for instructions,
or use the alternative manual installation procedure.

1. Navigate to the [Releases page](https://github.com/berrak/SolderFumeFanExtractor/releases).
1. Download the latest released ZIP archive in `~/Arduino/libraries.
1. Unzip the archive.
1. Rename the new directory. Remove _version-code_ or _master_* in the name like this for `SolderFumeFanExtractor`.
1. Restart Arduino IDE.
1. In Arduino IDE scroll down the long list below `Sketch->Include Library` and find `SolderFumeFanExtractor`.

## References

- [Controlling health risks from rosin-based solder flux fume](https://www.hse.gov.uk/pubns/indg249.pdf)
