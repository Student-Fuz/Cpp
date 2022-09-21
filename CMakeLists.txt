cmake_minimum_required(VERSION 3.21)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

#深浅拷贝
add_executable(oop_deepshallow_copy OOP/deepshallow_copy/Teacher.cpp)

#浅拷贝函数
add_executable(oop_shallow_copy OOP/deepshallow_copy/Person.cpp)

#内存模型
add_executable(oop_memory OOP/memory/memory.cpp)

#引用
add_executable(oop_reference OOP/reference/reference.cpp)

#重载
add_executable(oop_overload OOP/overload/overload.cpp OOP/overload/Operator_overload.cpp)

#运算符重载
add_executable(oop_operator_overload OOP/overload/Operator_overload.cpp)

#等号运算符重载 (赋值函数)
add_executable(oop_assign OOP/overload/assign.cpp)

#运算符++重载
add_executable(oop_operator_plusplus_overload OOP/overload/Operator_plusplus_overload.cpp)

#友元
add_executable(oop_friend OOP/access_authority/Friend.cpp)

#测试
add_executable(oop_test OOP/test/test.cpp OOP/test/test.h)

#继承
add_executable(oop_inherit OOP/inherit/inherit.cpp)

#继承访问权限
add_executable(oop_inherit_acc_auth OOP/inherit/inherit_acc_auth.cpp)

#模板----函数模板
add_executable(oop_template_func OOP/template/func_template.cpp)

#模板----类模板
add_executable(oop_template_class OOP/template/class_template/class_template.cpp)

#模板----模板的局限性
add_executable(oop_template_limit OOP/template/template_limit.cpp)

#模板----模板对象做函数参数
add_executable(oop_template_obj_as_param OOP/template/class_template/template_obj_as_param.cpp)

#模板----模板类的继承
add_executable(oop_template_inherit OOP/template/class_template/template_inherit.cpp)

#STL----vector
add_executable(stl_vector STL/vector/vector.cpp)

#STL----nest_vector
add_executable(stl_vector_nest STL/vector/vector_nest.cpp)

#STL----map
add_executable(stl_map STL/map/map.cpp STL/map/unordered_map.cpp)

#STL----map_custom_sort
add_executable(stl_map_custom_sort STL/map/map_custom_sort.cpp)

#STL----unordered_map
add_executable(stl_unordered_map STL/map/unordered_map.cpp)