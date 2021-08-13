# Volca-Sync-Divider

An Arduino driven Korg Volca sync divider. A simple project to add some versatility to the Volcas. This was put together and tested with an Arduino Nano, Arduino Pro Micro, Volca Beats, Volca Keys and Volca Bass. The Volca Beats was the master sync in this project, although any Volca should work. 

The arduino sends SYNC OUT signals every X-amount of SYNC IN signals. The default setting is both outputs are 1/16th speed of the original time (not to be confused with 16th steps). The numbers can be adjusted in the code. 

To expand on the project, an extra toggle switch or momentary switch/button could be added for switching between different pulse frequencies.

Two LEDs provide a visual aid for timing. Triggering play on the Volca(s), when both LEDs flash together, ensures all volcas will sync. The default code has both LEDs ON every 8 pulses. Slave Volcas will trigger on the slower, divided steps. 

See troubleshooting section below if your Volcas are syncing unpredictably.

## Schematic

This example uses the Arduino Nano. It was also tested on the Pro Micro, and should work with any Arduino.

![alt text](https://github.com/EmergentProperly/Volca-Sync-Divider/blob/main/Volca-Sync-Divider-Schematic.png)


## Troubleshooting

The Volca Keys has a touchy Sync-In. Setting the volume low helps to resolve the problem. A ground loop isolator added to the audio-out eliminates the problem entirely. 

Syncing the Volcas at very low BPM (i.e. master sync <50BPM-100BPM with sync outs set to 1/16) can produce unexpected syncopation. Although initially this may be undesirable, it can actually produce pleasing results with a bit of experimenting and tweaking.

DISCLAIMER: 
1) Due to the quirkiness of individual Volcas, your mileage may vary. 
2) Although this project is mostly harmless, it needs to be mentioned: you do this at your own risk. I am not responsible for any damage you do to yourself or your Volcas.
