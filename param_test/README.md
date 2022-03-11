# Param test

## param_test

### About
This executable shows how to load parameters from yaml in cpp.

### How to Run
```bash
ros2 launch param_test param_test.launch.py
```

### Target parameters
```bash
/**: # This will put all the parameters in every node
  ros__parameters:
    names:
      - bob
      - jon
    colors:
      bob: [0.1, 0.2, 0.3]
      jon: [0.1, 1.2, 1.3]
```

### Expected Result
```bash
[param_test]: Name: bob, Color R: 0.100 G: 0.200 B: 0.300
[param_test]: Name: jon, Color R: 0.100 G: 1.200 B: 1.300
```
