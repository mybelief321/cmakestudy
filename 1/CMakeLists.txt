# CMake最低版本号要求
cmake_minimum_required (VERSION 2.8)

#项目信息，如果是在Windows下的VS，生成的解决方案名称就是test1.sln
project (test1)

#制定生成的目标以及所需要的源码文件，这里填的app，也就是说如果是生成VS工程，那么工程中的项目名字就是app.vcxproj  以及 应用程序名字就是app.exe
add_executable(app main.cpp)
