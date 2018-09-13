cmake_minimum_required(VERSION 2.8)

project(Test3)

# 查找目录下的所有源文件,并将名称保存到 DIR_SRCS变量
aux_source_directory(. DIR_SRCS)

#添加math子目录
add_subdirectory(math)

# 指定生成目标
add_executable(app main.cpp)

#添加链接库
target_link_libraries(app MathFunctions)
