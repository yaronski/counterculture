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


### video
[![counterculture](https://github.com/yaronzimmermann/counterculture/blob/master/images/screenshot.png)](https://vimeo.com/322227320 "counterculture - click to watch!")


### quality control
![xenia](https://github.com/yaronzimmermann/counterculture/blob/master/images/ntut_counterculture_xenia_01_small.png "Xenia")


### complicatedly drawn circuit diagram
![fritzing](https://github.com/yaronzimmermann/counterculture/blob/master/fritzing/ntut_counterculture_04_bb.png)


### construction notes
- For lasercutting the box with teeth and slots I used 5mm MDF. Takeing into account the kerf of the laser, the vector path's generated from Sketchup must be offset by around .19mm. However the exact value might vary depending on the speed used for cutting.
- WAV Audio files must be a 16000 Hz Mono track in unsigned 8-bit PCM format to work with the [TMRpcm](https://github.com/TMRh20/TMRpcm/wiki) library
- I used an Arduino Mega since I had one laying around and a very limited time-frame.\
With regard to audio quality I'd recommend using a Teensy with built-in DAC instead.
