

class tkRoleBase
{
public:
        // sets functions.
        // gets functions.
        const std::vector<tkBuffer>& get_BufferList()const;	///< 角色列表
        std::vector<tkBuffer>& get_BufferList();						///< 角色列表
        bool set_PropList(const std::vector<tkBuffer>& value);	///< 角色列表

private:
        tkRoleSerializeDB 		selfRoleSerializeDB;
        tkCreatureSerializeDB   selfCreatureSerializeDB;

        int 			id;								// 序列化数据库和客服端
        int roleid;					// 序列化数据库和客服端

        std::vector<tkBuffer>	buffers;	// 序列化数据库
        tkCreature              creature;

        long long speed;

public:

        // 序列化到字符串为存库
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
