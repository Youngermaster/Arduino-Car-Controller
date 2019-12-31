# Arduino Car Controller

This project is about control a car made with arduino through an android app using bluetooth.

This repo contains two folders:

### - `android_code/`.

  - Contains all the android code, it means contains all the `layouts` and `Java` code.

### - `arduino_code/`.

  - Contains all the arduino code, it contains a `.ino` file, it's function is give control the car and receive the bluetooth signal.

  - Has 5 states:

    - State 0: `stopCar`.

    - State 1: `accelerate`.

    - State 2: `reverse`.

    - State 3: `turnRight`.

    - State 4: `turnLeft`.

