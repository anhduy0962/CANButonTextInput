

sudo apt-get install libmysqlcppconn-dev 

sudo apt-get install libgtkmm-3.0-dev 

sudo apt-get install libgtkmm-3.0

g++ `pkg-config gtkmm-3.0 --cflags --libs` GTKInputText.cpp lib.cpp -o click

Client side: sudo /bin/ip link set can0 up type can bitrate 500000 ./click

Server side: ./candump can0

PS: Code above is only client side. Server side source code is too big to add to github. 
    Please download at:
    
    git clone https://github.com/linux-can/can-utils.git
    
    http://skpang.co.uk/catalog/pican2-canbus-board-for-raspberry-pi-2-p-1475.html
    
    https://www.skptechnology.co.uk/pican2-software-installation/
