#查找当前目录下的所有的源文件，并将名称保存到DIR_LIB_SRCS变量
aux_source_directory(. DIR_LIB_SRCS)

#生成链接库
add_library(MathFunctions ${DIR_LIB_SRCS})
