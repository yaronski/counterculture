# counterculture

```
»Do you speak Chinese?«
```
```
»No, but I can count to 10 in Chinese!«
```

Being able to quantify things is essential while learning any new language → and generally quite cool, too.\
Combining visual and auditory — spoken by a mother-tongue speaker — sensory input at the push of an arcade style button, learning to count from 0 to 10 in Korean, Japanese, Chinese, Hindi, German and Polish is now easy and fun.

_counterculture_ is a device I built with the help of many others during my time at the National Taiwan University of Technology (NTUT) in Taipei. → Digital Fabrication class by Prof. N. Tai. → 2018/19.


![device](https://github.com/yaronzimmermann/counterculture/blob/master/fritzing/device_closeup.png)


### video
[![counterculture](https://github.com/yaronzimmermann/counterculture/blob/master/images/screenshot.png)](https://vimeo.com/322227320 "counterculture - click to watch!")


### complicatedly drawn circuit diagram
![fritzing](https://github.com/yaronzimmermann/counterculture/blob/master/fritzing/ntut_counterculture_04_bb.png)


### construction notes
- For lasercutting the box with teeth and slots, MDF sheets of 5mm thickness were used. Takeing into account the kerf of the laser, the vector path's generated from Sketchup must be offset by around .19mm. However the exact value might vary depending on the speed used for cutting.
- Each audio file must be a in a 16000 Hz mono, unsigned 8-bit PCM WAV format to work with the [TMRpcm](https://github.com/TMRh20/TMRpcm/wiki) library. For me, this was the only format that worked perfectly fine.
- An Arduino Mega board was used, since I had one laying around and a very limited time-frame.\
With regard to audio quality, using a Teensy with built-in DAC would be an improvement.
- While you're at it, add a repeat functionality for the most recent number played.
- files in the _rdworks_ folder contain files for the laser cutter controlling software »RDWorks«. If you use a different software and a different laser cutter, the settings will vary most likely anyway. Text shapes are being engraved at high speed and low power, while the edges of the box are cut at low speed and high power. For the pieces to come off easily, it might help programming the laser to continue moving a tiny bit beyond the actual end of the line. 
- Adobe Illustrator artboards are in A3 size, since A3 sheets of 5mm MDF were used.
- The folder »audio« found in _sdcard_ needs to be placed in the root directory of the FAT32 sd card plugged into the slot of the sd card reader module.

![ai](https://github.com/yaronzimmermann/counterculture/blob/master/illustrator/preview_artboard_example.png)

### quality controle
![xenia](https://github.com/yaronzimmermann/counterculture/blob/master/images/ntut_counterculture_xenia_01_small.png "Xenia")
