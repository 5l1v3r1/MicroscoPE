# 🔬 MicroscoPE
[![Build Status](https://github.com/twbs/bootstrap/workflows/Tests/badge.svg)](https://github.com/backslash/MicroscoPE)
  
  As part of wanting to improve my understanding of the portable executable I created MicroscoPE, a minimalistic tool designed to give you easy and quick information about any portable executable. While tools like CFF explorer exist to give a user interface for this stuff. I figured it might be nice to have a command line version, just so one can get quick information.
  
  ## Table of Contents
- [Setup & Usage](###setup&usage)
- [ToDoList](###to-do-list)
- [Contributing](###contributing)
- [Copyright and license](###copyright-and-license)

### setup&usage
  Make sure you have visual studio installed, this is required for installation. Once you have it installed just hit:
  ```
  ctrl-b
  ```
  Once MircoscoPE is finished building open up command prompt and type something on the lines of:
  ```
  microscope.exe target.exe/target.dll
  ```
  Hit enter, and you will be given a list of information from your executable.
  
### to-do-list
- [ ] FileSize - Show filesize of given executable.
- [ ] FileHash - Return an MD5 hash of given executable
- [ ] Data  Directories - Return Data Directories with MicroscoPE
- [ ] Descriptions - I'd like to give information next to each returned value just to help with the barrage of information thrown at you.

### contributing
  I'll continue to work on publishing new releases and updates, if you would like to help publish releases please check out the to-do-list, there is always something to do.

  
### copyright-and-license
  Feel free to use this how you would like, this is provided under an MIT license, if you enjoy this project please give credit and show some support. 😄 
