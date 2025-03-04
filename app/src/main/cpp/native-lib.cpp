#include <jni.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <memory>

std::string list()
{
    std::string total_txt;
    char buffer[121] = {0};  // ইনিশিয়ালাইজ করা হলো
    FILE *fp = popen("ls ", "r");
    while (fgets(buffer, sizeof(buffer), fp) != nullptr)
    {
        total_txt +=  buffer;
    }
    return total_txt;
}



extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string final = list();
    return env->NewStringUTF(final.c_str());
}

int main()
{


    return 0;
}