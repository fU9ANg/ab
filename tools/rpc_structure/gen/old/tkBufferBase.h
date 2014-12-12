
#ifndef _TKBUFFERBASE_H
#define _TKBUFFERBASE_H

class tkBufferBase
{
public:
        // sets functions.
        // gets functions.
private:
        tkBufferSerializeDB 		selfSerializeDB;

        int 			bufferid;								// ���л����ݿ�Ϳͷ���
        int 			type;								// ���л����ݿ�Ϳͷ���
public:

        // ���л����ַ���Ϊ���
        std::string& SerializeToStringForDB (void) {
                std::string rltString;

                UpdateDataToSerializeDB ();

                selfSerializeDB.SerializeToString (&rltString);
                return (rltString);
        }

        // ���л���������Ϊ���
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
