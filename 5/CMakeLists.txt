cmake_minimum_required(VERSION 2.8)
#项目信息
project(Test4)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file(
		"${PROJECT_SOURCE_DIR}/config.h.in"
		"${PROJECT_BINARY_DIR}/config.h"
	)

#是否使用自己的 MathFunctions库
option (USE_MYMATH
		"Use provided math implementation" ON)

#是否加入MathFunctions库
if (USE_MYMATH)
		include_directories ("${PROJECT_SOURCE_DIR}/math")
		add_subdirectory (math)
		set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)


# 查找目录下的所有源文件,并将名称保存到 DIR_SRCS变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(app ${DIR_SRCS})

#添加链接库
target_link_libraries(app ${EXTRA_LIBS})


#指定安装路径 
install (TARGETS app DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include) 

#启用测试
enable_testing()

#测试程序是否成功运行
add_test(test_run app 5 2)

#测试帮助信息是否可以正常显示
add_test(test_usage app)
set_tests_properties(test_usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* num1 num2")

#定义一个宏，用来简化测试工作
macro (do_test arg1 arg2 result)
	add_test(test_${arg1}_${arg2} app ${arg1} ${arg2})
	set_tests_properties (test_${arg1}_${arg2}
			PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

#利用do_test宏，测试一系列数据
do_test(5 2 "=7")
