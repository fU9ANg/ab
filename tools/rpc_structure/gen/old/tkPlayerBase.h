

class tkPlayerBase
{
public:
        // sets functions.
        // gets functions.
        const std::vector<tkRole>& get_RoleList()const;	///< ��ɫ�б�
        std::vector<tkRole>& get_RoleList();						///< ��ɫ�б�
        bool set_PropList(const std::vector<tkRole>& value);	///< ��ɫ�б�

private:
        tkPlayerSerializeDB 		selfSerializeDB;
        tkPlayerSerializeClient	selfSerializeClient;

        int 			id;								// ���л����ݿ�Ϳͷ���
        int 			fd;								// ���л����ݿ�Ϳͷ���
        long long lasttime;					// ���л����ݿ�Ϳͷ���
        string		account;					// ���л����ݿ�Ϳͷ���

        std::vector<tkRole>	roles;	// ���л����ݿ�

        int	LastSceneId 		//���һ�γ���Id
        int Gold;						//Ԫ��
        int Power;					//����
        int PowerUpdateTime;//��������ʱ��
        int ExpItem;				//��龭��
        int MountLevel;			//����ȼ�
        int MountLuck;			//��������ֵ
        int Exp;						//����

public:
        // ���л����ַ���ΪDB
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
