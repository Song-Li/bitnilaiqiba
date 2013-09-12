#ifndef Sms_H
#define Sms_H
#include<fstream>
#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sstream>
#include<sys/time.h>
#include<queue>
using namespace std;

template<class T> string m_to_string(T tmp, int wide) {
    stringstream ss;
    ss << tmp;
    string ret;
    ss >> ret;
    while((int)ret.length() < wide) ret = "0" + ret;
    return ret;
}

class Sms {
private:
    string from;    //发件人
    string to;      //收件人
    string cont;    //非本机联系人
    string ttime;   //发送 | 接收时间
    string text;    //短信内容，长度小于等于70
    bool unread;    //是否未读
    int status;     //发送状态，0表示成功，初始化为-1
    int id;         //编号，初始化为-1
    int isend;     //是否为结尾
    int start;      //长短信起始id

    int format_length;

public:
    Sms() {
        from = "-1";
        to = "-1";
        cont = "-1";
        ttime = get_system_time();
        text = " ";
        unread = false;
        status = -1;
        id = -1;
        isend = -1;
        start = -1;
        format_length = 25;
    };

    Sms(string _from, string _to, string _cont, string _text, int _isend): from(_from), to(_to), cont(_cont), text(_text), isend(_isend) {
        ttime = get_system_time();
        unread = false;
        status = -1;
        id = -1;
        start = -1;
        format_length = 25;
    };

    void set_from(string _from) {
        from = _from;
    }

    void set_to(string _to) {
        to = _to;
    }

    void set_cont(string _cont) {
        cont = _cont;
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

    void set_start(int _start) {
        start = _start;
    }

    void set_isend(int _isend) {
        isend = _isend;
    }

    void add_text(string str){
        text.append(str);
    }

    void set_time(string year, string month, string day, string hour, string minute) {
        ttime = "";
        ttime += m_to_string(year, 4);
        ttime += m_to_string(month, 2);
        ttime += m_to_string(day, 2);
        ttime += m_to_string(hour, 2);
        ttime += m_to_string(minute, 2);
        ttime += "0000000000";
    }

    void set_time(int year, int month, int day, int hour, int minute) {
        ttime = "";
        ttime += m_to_string(year, 4);
        ttime += m_to_string(month, 2);
        ttime += m_to_string(day, 2);
        ttime += m_to_string(hour, 2);
        ttime += m_to_string(minute, 2);
        ttime += "0000000000";
    }

    string get_from() {
        return from;
    }

    string get_to() {
        return to;
    }

    string get_cont() {
        return cont;
    }

    string get_time() {
        return ttime;
    }

    string get_text() {
        return text;
    }

    string get_formated_text() {
        double cnt = 0;
        string ret = "";
        for(int i = 0; i < text.length(); i++) {
            if(text[i] & 0x80 && (unsigned)text[i] >= 0) {
                if(cnt + 5.0 / 3.0 > format_length) {
                    cnt = 5.0 / 3.0;
                    ret += "\n";
                } else {
                    cnt += 5.0 / 3.0;
                }
                ret += text.substr(i, 3);
                i += 2;
            } else {
                if(text[i] == '\n') {
                    cnt = 0;
                    ret += "\n";
                    continue;
                }
                if(cnt + 1.0 > format_length) {
                    cnt = 1.0;
                    ret += "\n";
                } else {
                    cnt += 1.0;
                }
                ret += text[i];
            }
        }
        return ret;
    }

    string get_formated_text(int given_length) {
        double cnt = 0;
        string ret = "";
        for(int i = 0; i < text.length(); i++) {
            if(text[i] & 0x80 && (unsigned)text[i] >= 0) {
                if(cnt + 5.0 / 3.0 > given_length) {
                    cnt = 5.0 / 3.0;
                    ret += "\n";
                } else {
                    cnt += 5.0 / 3.0;
                }
                ret += text.substr(i, 3);
                i += 2;
            } else {
                if(text[i] == '\n') {
                    cnt = 0;
                    ret += "\n";
                    continue;
                }
                if(cnt + 1.0 > given_length) {
                    cnt = 1.0;
                    ret += "\n";
                } else {
                    cnt += 1.0;
                }
                ret += text[i];
            }
        }
        return ret;
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

    int is_end() {
        return isend;
    }

    int get_start(){
        return start;
    }


    int get_text_length() {
        int ret = 0;
        for(int i = 0; i < (int)text.length(); i++) {
            if(text[i] & 0x80 && (unsigned)text[i] >= 0) {
                i += 2;
            }
            ret++;
        }
        return ret;
    }

    friend ostream& operator << (ostream &o, const Sms &s) {
        string ttext = s.text;
        for(int i = 0; i < s.text.length(); i++) {
            if(s.text[i] & 0x80 && (unsigned)s.text[i] >= 0) {
                i += 2;
            }
            if(s.text[i] == ' ') {
                ttext[i] = '&';
            } else if(s.text[i] == '\n') {
                ttext[i] = '`';
            }
        }
        o << s.from << " " << s.to << " " << s.cont << " " << s.ttime << " " << s.unread << " " << s.status << " " << s.id << " " << s.isend << " " << s.start << " " << ttext;
        return o;
    }

    friend fstream& operator << (fstream &o, const Sms &s) {
        string ttext = s.text;
        for(int i = 0; i < s.text.length(); i++) {
            if(s.text[i] & 0x80 && (unsigned)s.text[i] >= 0) {
                i += 2;
            } else if(s.text[i] == ' ') {
                ttext[i] = '&';
            } else if(s.text[i] == '\n') {
                ttext[i] = '`';
            }
        }
        stringstream ss;
        ss << s.from << " " << s.to << " " << s.cont << " " << s.ttime << " " << s.unread << " " << s.status << " " << s.id << " " << s.isend << " " << s.start << " " << ttext;
        o << s.from << " " << s.to << " " << s.cont << " " << s.ttime << " " << s.unread << " " << s.status << " " << s.id << " " << s.isend << " " << s.start << " " << ttext;
        int cnt = 290 - ss.str().length();
        while(cnt--) {
            o << " ";
        }
        return o;
    }

    friend istream& operator >> (istream &i, Sms &s) {
        string ttext;
        i >> s.from >> s.to >> s.cont >> s.ttime >> s.unread >> s.status >> s.id >> s.isend >> s.start >> ttext;
        for(int j = 0; j < ttext.length(); j++) {
            if(ttext[j] & 0x80 && (unsigned)ttext[j] >= 0) {
                j += 2;
            }
            if(ttext[j] == '&') {
                ttext[j] = ' ';
            } else if(ttext[j] == '`') {
                ttext[j] = '\n';
            }
        }
        s.set_text(ttext);
        return i;
    }

    friend fstream& operator >> (fstream &i, Sms &s) {
        string ttext;
        i >> s.from >> s.to >> s.cont >> s.ttime >> s.unread >> s.status >> s.id >> s.isend >> s.start >> ttext;
        for(int j = 0; j < ttext.length(); j++) {
            if(ttext[j] & 0x80 && (unsigned)ttext[j] >= 0) {
                j += 2;
            }
            if(ttext[j] == '&') {
                ttext[j] = ' ';
            } else if(ttext[j] == '`') {
                ttext[j] = '\n';
            }
        }
        s.set_text(ttext);
        return i;
    }

    friend bool operator < (Sms a, Sms b) {
        return a.ttime > b.ttime;
    }

    void sms_to_cstr(char* str) {
        stringstream ss;
        ss << *this;
        strcpy(str, ss.str().c_str());
    }

    void cstr_to_sms(char* str) {
        stringstream ss;
        ss << str;
        ss >> *this;
    }

private:
    string get_system_time() {
        string ret("");
        time_t timer;
        struct tm* t_tm;
        timeval tBegin;
        time(&timer);
        t_tm = localtime(&timer);
        gettimeofday(&tBegin, 0);
        ret += m_to_string((unsigned int)t_tm->tm_year + 1900, 4);
        ret += m_to_string((unsigned int)t_tm->tm_mon + 1, 2);
        ret += m_to_string((unsigned int)t_tm->tm_mday, 2);
        ret += m_to_string((unsigned int)t_tm->tm_hour, 2);
        ret += m_to_string((unsigned int)t_tm->tm_min, 2);
        ret += m_to_string((unsigned int)t_tm->tm_sec, 2);
        ret += m_to_string((unsigned int)tBegin.tv_usec, 8);
        return ret;
    }
};
#endif // Sms_H
