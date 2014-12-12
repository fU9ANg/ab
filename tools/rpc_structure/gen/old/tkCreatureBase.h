
#ifndef _TKCREATUREBASE_H
#define _TKCREATUREBASE_H

class tkCreatureBase
{
public:
        // sets functions.
        // gets functions.
private:
        tkCreatureSerializeDB 		selfSerializeDB;

        int 			creatureid;								// 序列化数据库和客服端
        int 			hp;								// 序列化数据库和客服端

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

                selfSerializeDB.set_creatureid (creatureid);
                selfSerializeDB.set_hp (hp);
        }
};

#endif //_TKCREATUREBASE_H
