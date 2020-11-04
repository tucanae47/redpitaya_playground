

# Control redpitaya from cpp 


## compile and play Led blinker

```cpp
 g++ -g  -std=c++14 i2c_dev.cpp spi_dev.cpp led_blinker.cpp -o blink
 ```



 ## Notes
 Code is heavily based on [Koheron](https://www.koheron.com/) but without the need of websocket remote load server, i removed all the code related to the server and keep it simple to play directly with the fpga
