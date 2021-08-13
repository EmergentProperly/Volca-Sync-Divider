# Volca-Sync-Divider

An Arduino driven Korg Volca sync divider. It's basically a simple "hack" to add some versatility to the Volcas.
The arduino recieves a sync pulse from a volca, and outputs 2 or more pulses at a lower BPM while remaining in time with the source sync. 

Two LEDs provide a visual aid for timing. 
NOTE: it is important to trigger the master Volca when both LEDs are ON. The default code has both LEDs ON every 8 pulses.

This was put together and tested with an Arduino Nano, Arduino Pro Micro, Volca Beats, Volca Keys and Volca Bass. The Volca Beats was the main sync out. 
  
DISCLAIMER: Also, due to the quirkiness of Volcas, your mileage may vary.

##Schematic

![alt text](https://github.com/EmergentProperly/Volca-Sync-Divider/blob/main/Volca-Sync-Divider-Schematic.png)


## Troubleshooting

The Volca Keys has a touchy Sync-In. Setting the volume low helps to resolve the problem. A ground loop isolator added to the audio-out eliminates the problem entirely. 

Syncing the Volcas at very low BPM (i.e. source sync <50BPM with sync outs set to 1/16) can produce unexpected syncopation. Although initially this may be undesirable, it can actually produce pleasing results with a bit of experimenting and tweaking.
