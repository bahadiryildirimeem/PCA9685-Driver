# PCA9685 Driver
 PAC9685 Driver for embedded projects.
 
 This module helps you to use PCA9685 easily. It was written as object oriented C approximation programming. 
 So you can manage/create multiple PCA9685s. To creating a device, create PCA9685Handle type struct and call 
 PCA9685Init() function. There's no need extra configuration.
 
 NOTE: All PC9685s' configuration registers are same registers. If you want to configure every PCA9685 
 individually you need to change handle structure and init function. 
 
 You can use this library in projects that uses to drive servo motors. You can see below the output frequency
 of channel that set to 50Hz.
 
 ![freqSet](https://user-images.githubusercontent.com/45585791/132137216-6c2a9e8b-055b-403d-814e-ec98708dfb4c.jpeg)

 
 When you found a bug please inform me.
 
 You can find implementation videos below links.

 Knight Rider: https://youtu.be/QMra_3z97tY
 Fading Effect: https://youtu.be/ZSCXXIH56JU
