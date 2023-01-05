#运行方法

以管理员身份运行每个项目的MemorySharing.exe
其余两个exe无须运行，因为其余两个exe会被MemorySharing.exe自动命令运行

#修改代码并编译运行
项目二为例：
编译：
cd Proj_2

g++ Wprocess.cpp -o Wprocess.exe

g++ Rprocess.cpp -o Rprocess.exe

g++ MemorySharing.cpp -o MemorySharing.exe

运行：

MemorySharing.exe

# 代码建议

再Rprocess开始运行前加入Sleep(1000);，防止Wprocess未创建共享内存时被Rprocess访问


