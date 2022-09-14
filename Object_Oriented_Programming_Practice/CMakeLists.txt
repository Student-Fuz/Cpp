cmake_minimum_required(VERSION 3.21)
project(Object_Oriented_Programming_Practice)

set(CMAKE_CXX_STANDARD 14)

#深浅拷贝
add_executable(deepshallow_copy deepshallow_copy/Teacher.cpp)

#浅拷贝函数
add_executable(shallow_copy deepshallow_copy/Person.cpp)

#内存模型
add_executable(memory memory/memory.cpp)

#引用
add_executable(reference reference/reference.cpp)

#重载
add_executable(overload overload/overload.cpp overload/Operator_overload.cpp)

#运算符重载
add_executable(operator_overload overload/Operator_overload.cpp)

#运算符++重载
add_executable(operator_plusplus_overload overload/Operator_plusplus_overload.cpp)

#友元
add_executable(friend access_authority/Friend.cpp)

#测试
add_executable(test test/test.cpp test/test.h)

#继承
add_executable(inherit inherit/inherit.cpp)

#继承访问权限
add_executable(inherit_acc_auth inherit/inherit_acc_auth.cpp)

#模板----函数模板
add_executable(template_func template/func_template.cpp)

#模板----类模板
add_executable(template_class template/class_template/class_template.cpp)

#模板----模板的局限性
add_executable(template_limit template/template_limit.cpp)

#模板----模板对象做函数参数
add_executable(template_obj_as_param template/class_template/template_obj_as_param.cpp)

#模板----模板类的继承
add_executable(template_inherit template/class_template/template_inherit.cpp)

#STL----vector
add_executable(vector STL/vector.cpp)

#STL----nest_vector
add_executable(vector_nest STL/vector_nest.cpp)