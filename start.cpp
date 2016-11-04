#include<iostream>
#include<jni.h>

using namespace std;

int main(){
    JavaVM* mJavaVM;
    JNIEnv* env;
    const int size = 1;
    JavaVMOption options[size];
    char path[] = {"-Djava.class.path=."};
    options[0].optionString = path;

    JavaVMInitArgs initArgs;
    initArgs.version = JNI_VERSION_1_6;
    initArgs.options = options;
    initArgs.nOptions = size;
    initArgs.ignoreUnrecognized = false;

    if (JNI_CreateJavaVM(&mJavaVM, (void **)&env, &initArgs) != 0) {
        cout<<"create VM failed"<<endl;
    }else{
        jclass startClass =env->FindClass("com/test/HelloWorld");
        jmethodID mainId;
        if(startClass){
            mainId = env->GetStaticMethodID(startClass, "main","([Ljava/lang/String;)V");
            env->CallStaticVoidMethod(startClass, mainId, NULL);
        }else{
            cout<<"can't find class"<<endl;
        }

    }

    mJavaVM->DestroyJavaVM();
    return 0;
}
