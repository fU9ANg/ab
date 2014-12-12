

class tkPlayerBase
{
public:
        // sets functions.
        // gets functions.
        const std::vector<tkRole>& get_RoleList()const;	///< 角色列表
        std::vector<tkRole>& get_RoleList();						///< 角色列表
        bool set_PropList(const std::vector<tkRole>& value);	///< 角色列表

private:
        tkPlayerSerializeDB 		selfSerializeDB;
        tkPlayerSerializeClient	selfSerializeClient;

        int 			id;								// 序列化数据库和客服端
        int 			fd;								// 序列化数据库和客服端
        long long lasttime;					// 序列化数据库和客服端
        string		account;					// 序列化数据库和客服端

        std::vector<tkRole>	roles;	// 序列化数据库

        int	LastSceneId 		//最后一次场景Id
        int Gold;						//元宝
        int Power;					//体力
        int PowerUpdateTime;//体力更新时间
        int ExpItem;				//伙伴经验
        int MountLevel;			//坐骑等级
        int MountLuck;			//坐骑幸运值
        int Exp;						//经验

public:
        // 序列化到字符串为DB
        std::string& SerializeToStringForDB (std::string& serializestring) {
                std::string tmpString;

                UpdateDataToSerializeDB ();

                selfSerializeDB.SerializeToString (&tmpString);
                serializestring += tmpString;       // fixme: assign

                std::verctor<tkRole>::iterator it;
                for (it = roles.begin(); it != roles.end(); it++) {
                    tmpString.clear();
                    (*it).SerializeToStringForDB (tmpString);
                    serializestring += tmpString;   // fixme: assign
                }

                return (serializestring);
        }

        ParseFromStringForDB (std::string& serializestring) {
                std::string tmpString;
                size_t      sizeString = 0;

                // part1 - self data
                sizeString = * (size_t*) serializestring.c_str();
                assert (sizeString > 0);
                tmpString = serializestring.substr (sizeof(size_t), sizeString);
                selfSerializeDB.ParserFromString (tmpString);

                // part2 - user define type
                serializestring = serializestring.substr (sizeof(size_t) + sizeString);
                std::verctor<tkRole>::iterator it;
                for (it = roles.begin(); it != roles.end(); it++) {
                    tmpString.clear();
                    (*it).ParserFromString (tmpString);
                    serializestring += tmpString;   // fixme: assign
                }
        }

private:
        bool UpdateDataToSerializeDB (void) {
                selfSerializeDB.set_id (id);
                selfSerializeDB.set_fd (fd);
                selfSerializeDB.set_lasttime (lasttime);
                selfSerializeDB.set_account (account);
        }

        bool UpdateSerializeToDataDB (void) {
                //
        }
};
