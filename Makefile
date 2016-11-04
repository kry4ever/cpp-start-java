jvm_path:=/Library/Java/JavaVirtualMachines/jdk1.8.0_77.jdk/Contents/Home/include
jvm_md_path:=/Library/Java/JavaVirtualMachines/jdk1.8.0_77.jdk/Contents/Home/include/darwin
jvm_lib_path:=/Library/Java/JavaVirtualMachines/jdk1.8.0_77.jdk/Contents/Home/jre/lib/server

start:
	g++ -I$(jvm_path) -I$(jvm_md_path) -L$(jvm_lib_path) -ljvm start.cpp -o start

#start.cpp:
#	export LD_LIBRARY_PATH=/Library/Java/JavaVirtualMachines/jdk1.8.0_77.jdk/Contents/Home/jre/lib/server:$LD_LIBRARY_PATH
