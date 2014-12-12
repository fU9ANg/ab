
#ifndef _TKBUFFERBASE_H
#define _TKBUFFERBASE_H

class tkBufferBase
{
public:
        // sets functions.
        // gets functions.
private:
        tkBufferSerializeDB 		selfSerializeDB;

        int 			bufferid;								// 序列化数据库和客服端
        int 			type;								// 序列化数据库和客服端
public:

        // 序列化到字符串为存库
        std::string& SerializeToStringForDB (void) {
                std::string rltString;

                UpdateDataToSerializeDB ();

                selfSerializeDB.SerializeToString (&rltString);
                return (rltString);
        }

        // 序列化到数据流为存库
        std::stream& SerializeToStreamForDB (void) {
                std::stream	rltStream;

                UpdateDataToSerializeDB ();

                selfSerializeDB.SerializeToStream (&rltStream);
                return (rltStream);
        }

private:
        bool UpdateDataToSerializeDB (void) {

                selfSerializeDB.set_bufferid (bufferid);
                selfSerializeDB.set_type (type);
        }
};

#endif  //_TKBUFFERBASE_H
