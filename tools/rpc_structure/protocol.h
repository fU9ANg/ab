
#ifndef __PROTOCOL_H_
#define __PROTOCOL_H_


#pragma pack(1)
enum CommandType {
};

typedef struct sTransferMessage {
        unsigned int cLen;          // 数据长度
        unsigned int cFuncId;
        //enum CommandType cType;     // 数据编号
        void* cData() {             // 指向数据的指针
                return this + 1;
        }
} MSG_HEAD;

#define MSG_HEAD_LEN    sizeof(struct sTransferMessage)

#pragma pack()

#endif // __PROTOCOL_H_
