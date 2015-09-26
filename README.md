# roverbot
2 motor arduino uno rover bot with L298 h-bridge and HC-SR04 ultra sonic range finder

verion 0.0.1 moves forward until the ping sensor indicates a blocking object is within 15cm, then stops.  When the object is more than 30cm, the bot goes forward again.  This version uses a simple finite state machine.
