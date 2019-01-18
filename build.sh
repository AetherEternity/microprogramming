JDK_INCLUDE_PLAT="/usr/lib/jvm/java-8-openjdk-amd64/include/linux"
JDK_INCLUDE="/usr/lib/jvm/java-8-openjdk-amd64/include"

javac -d classes src/secondlab/SecondLab.java
javapackager -createjar -appclass secondlab.SecondLab -srcdir classes -outdir dist -outfile hello.jar -v
javah -cp classes secondlab.SecondLab
gcc -shared -I$JDK_INCLUDE_PLAT -I$JDK_INCLUDE -fPIC secondlab_SecondLab.c -o libABC.so
