
#set your project name
PRJ_NAME=

#设置项目的类型，是共享库、可执行程序还是静态库
#set your project type : choose one below
#PRJ_TYPE =g++ -shared
PRJ_TYPE = g++
#PRJ_TYPE = ar -r

#设置编译的类型，是Debug还是Release
#set Debug or Release
Compile_Flag = Debug
#Compile_Flag = Release

#设置编译后的文件的输出路径，这个文件夹一定要有才可以，否则会出错的。所以要事先建立好
#set your output path
Output:= bin

#这里是设置代码所在的文件夹
#set your source folder
SRC:=src

#如果引用了什么库，就在这里添加好了.
#add the lib you used here
#LIBS := -lLib1 -lLib2 -lLib3
LIBS := -lpthread
#LIBPATH := -Lpath1 -Lpath2 -Lpath3
LIBPATH :=
INCLUDEPATH :=
# INCLUDEPATH := -I/usr/lib/XXX/include
#符号，表示注释。makefile里面有它的那行，就不会起作用了。比如下面两行就是注释。
###################################
#DON"T MODIFY THE BELOWS

#combine output folder
FinalOutput := $(Output)/$(Compile_Flag)/
#上面的代码，定义了一个变量，名字是FinalOutput，给它赋值，可以用=或者:=，等一下说区别。
#@$(Output)表示取变量Output的值，在这里，Output是bin，所以$(Output)就是bin啦。同理，#(Compile_Flag)就是Debug，组合在一起，就是bin/Debug/,把它赋值给变量FinalOutput，现在FinalOutput就是bin/Debug/了。

#接下来说=和:=的区别。
#=就是把右边的值赋给左边。但是，比如下面的赋值就会出问题
#FinalOutput=$(FinalOutput)
#为什么呢？
#因为右边的$(FinalOutput)会取FinalOutput的值，这个取值的过程叫做“展开”，有点类似宏的意思。于是，这个展开就会陷入无穷的递归里面去了。虽然make很智能，遇到这类问题，它会抱错，但是我们怎么避免呢？于是就有了:=,它的意思就是只展开一次。这样就不会陷入无穷的递归里面去了。

#list all dirs
SUBDIRS := $(shell find $(SRC) -type d)
#这行的作用，是调用shell，执行find命令，然后把返回的结果放到变量SUBDIRS里面。在makefile里面调用shell执行命令的方法是：
#$(shell text)
#其中，text是要执行的命令，比如上面的find $(SRC) -type d（按照前面的设置，这个命令展开后，应该是find code -type d。这个是基本的find命令，意思是查找code文件夹里面的所有文件夹，包括code文件夹。），命令执行的结果，也就是$(shell text)的返回值。

#flags in makefile
DEBUG_FLAG = -O0 -g3 -Wall -c -fmessage-length=0
RELEASE_FLAG = -O3 -Wall -c -fmessage-length=0
#这里是设置编译器的编译参数，具体内容请参看g++的手册吧。如果有不满意的，可以在这里修改编译的参数。

RM := rm -rf
#这个是清除命令，用在clean里面的

#set compile flag
ifeq ($(Compile_Flag),Debug)
CFLAGS := $(DEBUG_FLAG)
else
CFLAGS := $(RELEASE_FLAG)
endif
#这里是一个条件判断。ifeq就是“如果等于”的意思。还有一个ifneq，当然就是“如果不等于”了。用法很简单，就是
#ifeq(要比较的内容,要比较的内容)
#else
#endif

#上面的代码，比较了Compile_Flag变量和Debug，如果Compile_Flag的值是Debug,就给变量CFLAGS设置为DEBUG_FLAG的值；如果不是，就设置为RELEASE_FLAG的值。

#prepare files
CPP_SRCS:=$(shell find ./$(SRC) -name *.cpp)
#这里又调用了一次shell，执行了find。这次是查找.cpp文件，然后把文件列表保存在CPP_SRCS里面。找到的文件是带着相对的路径名的，这个很有用。

OBJS:=$(CPP_SRCS:%.cpp=$(FinalOutput)%.o)

#这里是替换，$(CPP_SRCS:%.cpp=$(FinalOutput)%.o)
#的意思就是说，把CPP_SRCS里面，每个cpp部分结尾的字符串，.cpp部分都替换成.o，并且在前面加上$(FinalOutput)字符串。在这个例子里面，$(FinalOutput)就是bin/Debug/。

#举个例子吧。比如你在路径./code/test下面有个文件a.cpp，执行上面的操作后，CPP_SRCS里面就有了一个./code/test/a.cpp，然后经过替换，OBJS里面就有了一个bin/Debug/code/test/a.o了。

#all target

#	$(PRJ_TYPE) $(LIBPATH) -o"$@" $^ $(LIBS)
SRCS1=$(FinalOutput)$(SRC)/client.cpp
SRCS2=$(FinalOutput)$(SRC)/service.cpp	
OBJS1=$(SRCS1:.cpp=.o)
OBJS2=$(SRCS2:.cpp=.o)

EXE1=$(FinalOutput)client
EXE2=$(FinalOutput)service

all:dir $(FinalOutput)$(PRJ_NAME)
	$(PRJ_TYPE) $(LIBPATH) -o  $(EXE1) $(OBJS1)    $(LIBS)	
	$(PRJ_TYPE) $(LIBPATH) -o  $(EXE2) $(OBJS2)    $(LIBS)
	@echo '^_^ ^_^ ^_^ ^_^ ^_^ ^_^ OK ^_^ ^_^ ^_^ ^_^ ^_^ ^_^'

#all是我们要make的目标，冒号（：）后面的内容是这个目标的依赖项，依赖项可以没有，也可以有多个。
#这个all，就依赖于两个项目，一个是dir，一个是$(FinalOutput)和$(PRJ_NAME)一起组成的目标文件夹。其中dir是用来创建目录的，而$(FinalOutput)$(PRJ_NAME)是用来生成项目文件的。
#make执行的时候，遇到all，要生成它，就得先找到它依赖的这两个项目。

dir:
	mkdir -p $(FinalOutput);
	for val in $(SUBDIRS);do \
	mkdir -p $(FinalOutput)$${val}; \
done;
#这个dir，没有依赖的项目，它要做的事情，就是创建文件夹。每个目标要执行的操作，都要以tab开头，回车结束。如果一行太长，可以用\加回车在下一行继续。
#在这里，这两行的作用，都是建立文件夹。
#mkdir是shell里面建立文件夹的命令，-p参数表示如果文件夹存在，就忽略。

#tool invocations	
#$(FinalOutput)$(PRJ_NAME):$(OBJS) 	
#	$(PRJ_TYPE) $(LIBPATH) -o"$@" $^ $(LIBS)
#	$(PRJ_TYPE) $(LIBPATH) -o"$@" $^ $(LIBS)

$(FinalOutput)$(PRJ_NAME):$(OBJS) 
	
$(FinalOutput)%o:./%cpp
	g++ $(CFLAGS) $(INCLUDEPATH) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"

#在上面的规则里面，我来说下$(FinalOutput)%o:./%cpp的意思。我还是举例说吧，直接讲不容易搞明白。
#比如我有一个目标是bin/Debug/src/data/core.o，其中变量$(FinalOutput)的值是bin/Debug/
#应用规则后对应的依赖文件就是./src/data/core.cpp了。
#
#还不明白？那我说得再详细一些。
#比如我们建立了一个项目，在文件夹testMake下面，它下面有文件夹src，这里面是代码，还有文件夹bin，作为make的输出目录，另外就是还有这个makefile文件。
#在目录testMake下面执行make，会先在bin目录下面建立文件夹Debug(如果你配置为release，那么建立的就是Release)。然后会在bin/Debug下面创建最终目标，比如是testMake吧。而testMake需要当前目录下面的文件bin/Debug/src/data/core.o，这个.o文件又依赖于当前目录下的文件./src/data/core.cpp。于是make就会去编译相应的cpp文件，把生成的.o文件放到bin/Debug下面对应的位置，然后再link，就生成了最终目标。
#
#结合上面的讲解，在生成最终目标之前，遇到的每个.o文件，都会按照上面的规则，首先把需要的所有的.o文件都编译出来，然后再进行链接，生成最终的目标文件。

#other targets
clean:
	-$(RM) $(Output)/*
