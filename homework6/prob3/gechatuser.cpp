#include "gechatuser.h"

GechatUser::GechatUser() {}
GechatUser::GechatUser(string username) {
    m_username = username;
}
GechatUser::GechatUser(const GechatUser& other) {
    m_username = other.m_username;
    m_friendList = other.m_friendList;
}
GechatUser::~GechatUser() {}

string GechatUser::getUsername() const{
   return m_username;
}
vector<shared_ptr<GechatUser>> GechatUser::getFriendList() const{
    return m_friendList;
}

int GechatUser::numFriends() const {
    return m_friendList.size();
}
void GechatUser::setUsername(string username) {
    m_username = username;
}
bool GechatUser::haveFriend(shared_ptr<GechatUser> user) {
    for(int i = 0; i < m_friendList.size(); i++) {
        if( user->getUsername() == m_friendList[i]->m_username)
            return true;
    }
    return false;
}
bool GechatUser::addFriend(shared_ptr<GechatUser> user) {
    if (haveFriend(user) == true || !user)
        return false;
    m_friendList.push_back(user);
    return true;
}
bool GechatUser::singleDelete(shared_ptr<GechatUser> user) {
    for(int i = 0; i < m_friendList.size(); i++) {
        if( user->getUsername() == m_friendList[i]->m_username) {
            //clog << "singleDelete by sp about to exicute\n";
            m_friendList[i] = nullptr;
            m_friendList.erase(m_friendList.begin()+i);
            return true;
        }
    }
    return false;
}
bool GechatUser::singleDelete(string username) {
    for(int i = 0; i < m_friendList.size(); i++) {
        if( username == m_friendList[i]->m_username) {
            //clog << "singleDelete by str about to exicute\n";
            m_friendList[i] = nullptr;
            m_friendList.erase(m_friendList.begin()+i);
            return true;
        }
    }
    return false;
}
bool GechatUser::doubleDelete(shared_ptr<GechatUser> user) {
    if (haveFriend(user)) {
        //clog << "mark1\n";
        for(int i = 0; i < user->m_friendList.size(); i++) {
            if( user->getUsername() == m_friendList[i]->m_username) {
                //clog << "doubleDelete about to exicute delete1 by ptr\n";
                user->singleDelete(this->m_username);
                //clog << "doubleDelete about to exicute delete2 by ptr\n";
                m_friendList[i] = nullptr;
                m_friendList.erase(m_friendList.begin()+i);
                return true;
            }
        }
    }
    else {
        //clog << "about to return false\n";
        return false;
    }
}
bool GechatUser::doubleDelete(string username) {
    for(int i = 0; i < m_friendList.size(); i++) {
        if( username == m_friendList[i]->m_username) {
            //clog << "doubleDelete about to exicute delete1 by str\n";
            m_friendList[i]->singleDelete(this->m_username);
            //clog << "doubleDelete about to exicute delete1 by str\n";
            m_friendList[i] = nullptr;
            m_friendList.erase(m_friendList.begin()+i);
            return true;
        }
    }
    return false;
}
bool GechatUser::operator== (const GechatUser &comp) const {
    if(this->getUsername() == comp.getUsername())
        return true;
    else return false;
}
bool GechatUser::operator< (const GechatUser &comp) const {
    if (this->getUsername() < comp.getUsername())
        return true;
    return false;
}


ostream& operator<< (ostream& os, GechatUser &user) {
    os << user.getUsername() << " (friends: " << user.numFriends() << ')';
    return os;
}