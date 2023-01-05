cmake_minimum_required(VERSION 3.21)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

############################################
#              Basic_Grammar
############################################

#Basic_Grammar---stringstream
add_executable(stringstream Basic_Grammar/stringstream/stringstream.cpp)

############################################
#                   OOP
############################################

#深浅拷贝
add_executable(oop_deepshallow_copy OOP/deepshallow_copy/Teacher.cpp)

#浅拷贝函数
add_executable(oop_shallow_copy OOP/deepshallow_copy/Person.cpp)

#内存模型
add_executable(oop_memory Memory_Partition/memory/memory.cpp)

#引用
add_executable(oop_reference Reference/reference/reference.cpp)

#重载
add_executable(oop_overload OOP/overload/overload.cpp)

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

#继承----继承中的构造函数与析构函数
add_executable(oop_inherit_destructor_constructor OOP/inherit/inherit_destructor_constructor.cpp)

#多态
add_executable(oop_polymorphism OOP/polymorphism/polymorphism.cpp)

############################################
#            Generic_Program
############################################

#模板----函数模板
add_executable(template_func Generic_Program/template/func_template.cpp)

#模板----类模板
add_executable(template_class Generic_Program/template/class_template/class_template.cpp)

#模板----模板的局限性
add_executable(template_limit Generic_Program/template/template_limit.cpp)

#模板----模板对象做函数参数
add_executable(template_obj_as_param Generic_Program/template/class_template/template_obj_as_param.cpp)

#模板----模板类的继承
add_executable(template_inherit Generic_Program/template/class_template/template_inherit.cpp)

############################################
#                        STL
############################################

#STL----vector
add_executable(stl_vector STL/vector/vector.cpp)

#STL----nest_vector
add_executable(stl_vector_nest STL/vector/vector_nest.cpp)

#STL----map
add_executable(stl_map STL/map/map.cpp)

#STL----map_custom_sort
add_executable(stl_map_custom_sort STL/map/map_custom_sort.cpp)

#STL----unordered_map
add_executable(stl_unordered_map STL/map/unordered_map.cpp)

############################################
#              Processes&Threads
############################################

#pthread
add_executable(pthread Processes_Threads/Threads/pthread.cpp)

#pthread---连接与分离
add_executable(pthread_detach Processes_Threads/Threads/pthread_detach.cpp)

#thread
add_executable(thread Processes_Threads/Threads/thread.cpp)

#Synchronization---Threads
add_executable(Syn_thread Processes_Threads/Synchronization/Threads/Syn_Threads.cpp)

#Synchronization---TicketsSale
add_library(TicketsSale Processes_Threads/Synchronization/Threads/TicketsSale.cpp)

add_executable(TicketsSale_test Processes_Threads/Synchronization/Threads/TicketsSale_test.cpp)

target_link_libraries(TicketsSale_test TicketsSale)

############################################
#                 Lambda
############################################

#Lambda
add_executable(lambda Lambda/lambda.cpp)

############################################
#                 Draft
############################################

add_executable(test Draft/main.cpp)
