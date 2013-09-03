#ifndef CONSTACT_H
#define CONSTACT_H
#include<map>
#include<cstring>
#include<iostream>
using namespace std;

class Contact {
    //
private:
    string ip;//该联系人的绑定ip
    string name;//昵称
    string time;//联系人最近一条信息的时间
    int id;//系统给该联系人具体id


public:

    map<string,int> Sms_self;//联系人的map<time,id>

    Contact () {
        ip = "127.0.0.1";
        Sms_self.clear();
        id = -1;
    };

    Contact (string _ip,string _name,string _time ,int _id): ip(_ip), name(_name), time(_time), id(_id){
    };

    string get_ip() {
        return ip;
    }


    int get_id() {
        return id;
    }

    string get_time(){
        return time;
    }

    string get_name(){
        return name;
    }


    void set_name(string _name){
        name = _name;
    }

    void set_time(string _time){
        time = _time;
    }


    friend ostream& operator << (ostream &o, const Contact &s) {
        o << s.ip << " " << s.name << " " << s.time << " " << s.id << " " << endl;
        return o;
    }

    friend fstream& operator << (fstream &o, const Contact &s) {
        o << s.ip << " " << s.name << " " << s.time << " " << s.id << " " << endl;
        return o;
    }

    friend istream& operator >> (istream &i, Contact &s) {
        i >> s.ip >> s.name >> s.time >> s.id;
        return i;
    }

    friend fstream& operator >> (fstream &i, Contact &s) {
        i >> s.ip >> s.name >> s.time >> s.id;
        return i;
    }
};

#endif // Contact_H
