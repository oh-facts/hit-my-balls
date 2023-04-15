# hit-my-balls

Built on a new engine - The BS Engine (Ball Square Engine)

Everything is either a ball or a square.

Dev environment to use this engine will be released soon. 

Feel free to contribute.

## Controls

1. W/S or arrow keys to move.

2. R to restart

3. Esc / cross button / alt + f4 / power off button to quit

## System Requirments

**Required**
1. linux or Win32
2. GCC or MinGW  *
3. Cmake *
4. Make *

*If you want to build from source code. Check releases for the exe.

## Build Instructions
**Win32**

Open powershell and enter the following commands
``` 
git clone https://github.com/oh-facts/hit-my-balls.git
```

Navigate inside the folder to the root directory (the one with the src files/vendor/res) and open powershell there

Now do
```
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
make all
./Game
```

**Linux**

Open Console and enter the following commands
``` 
git clone https://github.com/oh-facts/hit-my-balls.git
cd eat-my-balls-in-cpp
mkdir build
cd build
cmake .. -G "Unix Makefiles"
make all
./Game
```

and you should be hitting balls.



If there are any errors, please stop making them.


cheers,

facts

