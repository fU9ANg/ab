
#ifndef _TKCREATUREBASE_H
#define _TKCREATUREBASE_H

class tkCreatureBase
{
public:
        // sets functions.
        // gets functions.
private:
        tkCreatureSerializeDB 		selfSerializeDB;

        int 			creatureid;								// ���л����ݿ�Ϳͷ���
        int 			hp;								// ���л����ݿ�Ϳͷ���

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

                selfSerializeDB.set_creatureid (creatureid);
                selfSerializeDB.set_hp (hp);
        }
};

#endif //_TKCREATUREBASE_H
