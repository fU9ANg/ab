

class tkRoleBase
{
public:
        // sets functions.
        // gets functions.
        const std::vector<tkBuffer>& get_BufferList()const;	///< ��ɫ�б�
        std::vector<tkBuffer>& get_BufferList();						///< ��ɫ�б�
        bool set_PropList(const std::vector<tkBuffer>& value);	///< ��ɫ�б�

private:
        tkRoleSerializeDB 		selfRoleSerializeDB;
        tkCreatureSerializeDB   selfCreatureSerializeDB;

        int 			id;								// ���л����ݿ�Ϳͷ���
        int roleid;					// ���л����ݿ�Ϳͷ���

        std::vector<tkBuffer>	buffers;	// ���л����ݿ�
        tkCreature              creature;

        long long speed;

public:

        // ���л����ַ���Ϊ���
        std::string& SerializeToStringForDB (std::string& serializestring) {
                std::string tmpString;

                UpdateDataToSerializeDB ();

                tmpString.clear ();
                selfRoleSerializeDB.SerializeToString (tmpString);
                serializestring += tmpString;       // fixme: assign

                tmpString.clear ();
                creature.SerializeToStringForDB (tmpString);
                serializestring += tmpString;       // fixme: assign

                std::vector<tkBuffer*>::iterator it;
                for (it = buffers.begin(); it != buffers.end(); it++) {
                        tmpString.clear();
                        (*it).SerializeToStringForDB (tmpString);
                        serializestring += tmpString;   // fixme: assign
                }

                return (serializestring);
        }

private:
        bool UpdateDataToSerializeDB (void) {

                selfRoleSerializeDB.set_id (id);
                selfRoleSerializeDB.set_roleid (roleid);
                selfRoleSerializeDB.set_speed (speed);
        }
};
