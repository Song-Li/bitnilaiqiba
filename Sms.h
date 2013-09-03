#ifndef SMS_H
#define SMS_H
#include<fstream>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


class Sms {
    //todo:
    //确定time成员的格式
private:
    string from;    //发件人
    string to;      //收件人
    string cont;    //非本地联系人
    string time;    //发送时间
    string text;    //短信内容，长度小于70
    bool unread;    //是否未读
    int status;     //发送状态，0表示成功，初始化为-1
    int id;         //编号，初始化为-1
    bool isend;     //是否为结尾
    string end_of_Sms;  //写入文件中的text结尾标识符

public:
    Sms() {
        from = "-1";
        to = "-1";
        time = "-1";
        text = "";
        unread = false;
        status = -1;
        id = -1;
        isend = true;
        end_of_Sms = "%+*-/%";
    };

    Sms(string _from, string _to, string _text, bool _isend): from(_from), to(_to), text(_text), isend(_isend) {
        time = "-1";
        unread = false;
        status = -1;
        id = -1;
        end_of_Sms = "%+*-/%";
    };

    void set_from(string _from) {
        from = _from;
    }

    void set_to(string _to) {
        to = _to;
    }

    void set_text(string _text) {
        text = _text;
    }

    void set_unread(bool _unread) {
        unread = _unread;
    }

    void set_status(int _status) {
        status = _status;
    }

    void set_id(int _id) {
        id = _id;
    }

    void set_isend(bool _isend) {
        isend = _isend;
    }

    void set_cont(string _cont) {
        cont = _cont;
    }

    string get_from() {
        return from;
    }

    string get_to() {
        return to;
    }

    string get_time() {
        return time;
    }

    string get_text() {
        return text;
    }

    string get_cont() {
        return cont;
    }

    bool is_unread() {
        return unread;
    }

    bool is_read() {
        return !unread;
    }

    int get_id() {
        return id;
    }

    int get_status() {
        return status;
    }

    bool is_end() {
        return isend;
    }

    friend ostream& operator << (ostream &o, const Sms &s) {
        o << s.from << " " << s.to << " " << s.time << " " << s.unread << " " << s.status << " " << s.id << " " << s.isend << " " << s.text;
        return o;
    }

    friend fstream& operator << (fstream &o, const Sms &s) {
        o << s.from << " " << s.to << " " << s.time << " " << s.unread << " " << s.status << " " << s.id << " " << s.isend << " " << s.text << " " << s.end_of_Sms << endl;
        return o;
    }

    friend istream& operator >> (istream &i, Sms &s) {
        i >> s.from >> s.to >> s.time >> s.unread >> s.status >> s.id >> s.isend >> s.text;
        string c;
        while(i >> c) {
            if(c == s.end_of_Sms) {
                break;
            }
            s.text += " " + c;
        }
        return i;
    }

    friend fstream& operator >> (fstream &i, Sms &s) {
        i >> s.from >> s.to >> s.time >> s.unread >> s.status >> s.id >> s.isend >> s.text;
        string c;
        while(i >> c) {
            if(c == s.end_of_Sms) {
                break;
            }
            s.text += " " + c;
        }
        return i;
    }
};

#endif // Sms_H
