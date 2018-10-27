#include <iostream>
#include <unordered_map>
#include <vector>
//#include "GlobalHead.h"
#include <vector>
#include <string>
//#include <lcms.h>
typedef unsigned long DWORD;

using namespace std;


int IsTextUTF8(unsigned char * str,long length)
{
    int i;
    DWORD nBytes=0;             // UFT8可用1-6个字节编码,ASCII用一个字节
    unsigned char chr;
    bool bAllAscii= true;       // 如果全部都是ASCII, 说明不是UTF-8
    for(i=0;i<length;i++)
    {
        chr= *(str+i);
        if( (chr&0x80) != 0 )   // 判断是否ASCII编码,如果不是,说明有可能是UTF-8,ASCII用7位编码,但用一个字节存,最高位标记为0,o0xxxxxxx
            bAllAscii= false;
        if(nBytes==0){          // 如果不是ASCII码,应该是多字节符,计算字节数
            if(chr>=0x80){
                if(chr>=0xFC&&chr<=0xFD)
                    nBytes=6;
                else if(chr>=0xF8)
                    nBytes=5;
                else if(chr>=0xF0)
                    nBytes=4;
                else if(chr>=0xE0)
                    nBytes=3;
                else if(chr>=0xC0)
                    nBytes=2;
                else{
                    return false;
                }
                nBytes--;
            }
        }
        else{                   //多字节符的非首字节,应为 10xxxxxx
            if( (chr&0xC0) != 0x80 )
                return false;

            nBytes--;
        }
    }

    if( nBytes > 0 )            //违返规则
        return false;

    if( bAllAscii )             //如果全部都是ASCII, 说明不是UTF-8
        return false;

    return true;
}



int main() {
    int M;
    cin >> M;
    unsigned char str[M];
    for( int i=0; i< M ; i++ ){
        int tmp;
        cin >> tmp;
        str[i] = (unsigned char)tmp;
    }

    cout << IsTextUTF8(str, M) << endl;

    return 0;
}
/*output:
3
235 140 44
 
0
*/