#ifndef DATABASE_H
#define DATABASE_H

#include<set>
#include<map>
#include"sms.h"
#include"constact.h"
#include"Sms_file.h"

using namespace std;

class Database
{
    private:
        set<int> free_space;
        map<string,Contact> ip_contact;//the map of Contacts map<ip,contact>
        map<string,string> contact_map;//map<time,ip>

/****************************************
Sms** search (str: Sc);
boolean delete (Contact: string);//~~
boolean delete (con: Sms*);
boolean delete (id: int);//~~
boolean add (dx: Sms);
Contact* getContactList();
Sms* getSmsList(con: Contact*);
Sms** getSearch(str: Sc);
boolean sending(dx: Sms);
boolean setIp(Ip: String);
*****************************************/
    public:

        void update_ip(string ip,Contact cont){
            ip_contact.erase(ip);
            ip_contact.insert(pair<string,Contact>(ip,cont));
        }



        bool Delete(int id){//删除单个短信
            if(free_space.find(id) == free_space.end()) return false;//不存在该短信
            free_space.insert(id);//插入空闲区域
            Sms tem_sms = Sms_file.find(id);//没写呢


            string tem_ip = tem_sms.get_cont();//找到了该短信联系人的ip->tem_ip
            contact_map.erase(tem_ip);//删除该联系人节点
            Contact tem_con = ip_contact.find(tem_ip)->second;//获取该联系人


            map<string,int> tem_sms_map = tem_con.Sms_self;//获得该联系人中的短信树
            tem_con.set_time(tem_sms_map.begin()->first);//获取联系人短信树中最新短信时间赋值


            update_ip(tem_ip,tem_con);//更新ip-联系人对
            contact_map.insert(pair<string,string>(tem_con.get_time(),tem_ip));//更新联系人树
        }



        bool Delete(string ip){
            map<string,Contact>::iterator its = ip_contact.find(ip);
            if(its == ip_contact.end()) return false;
            Contact tem_con = its->second;
            map<string,int> sms_map = tem_con.Sms_self;//获得该联系人中的短信树

            map<string,int>::iterator it;
            for(it = sms_map.begin();it != sms_map.end();++ it) free_space.insert(it->second);
            //挨个标记短信空间空余

            contact_map.erase(ip);//删除该联系人的短信树中的信息
            return true;
        }



        bool Add(Sms ins){
            set<int>::iterator it = free_space.begin();
            int id = *it;
            if(!Sms_file.insert(ins,id)) return false;
            free_space.erase(it);
            //插入短信并且删除空闲标记

            string ip = ins.get_cont();
            Contact contact = ip_contact.find(ip) -> second;
            contact_map.erase(contact.get_time());//删除旧的记录
            contact.Sms_self.insert(pair<string,int>(ins.get_time(),id));//更新联系人短信map
            contact.set_time(contact.Sms_self.begin()->first);//更新联系人时间


            update_ip(ip,contact);//更新ip索引
            contact_map.insert(pair<string,string>(contact.get_time(),ip));//更新联系人树

        }
};

#endif // DATABASE_H
