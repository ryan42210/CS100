#include "customset.h"

#ifndef _GECHATUSER_HPP_
#define _GECHATUSER_HPP_

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <memory>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

class GechatUser {
friend ostream& operator<< (ostream& os, GechatUser &user);
public:
	GechatUser();
	GechatUser(string username);
	GechatUser(const GechatUser& other);
	~GechatUser();

	string getUsername() const;
	vector<shared_ptr<GechatUser>> getFriendList() const;
	int numFriends() const;
	void setUsername(string username);
	bool haveFriend(shared_ptr<GechatUser> user); // return true if user is a friend to *this.
	bool addFriend(shared_ptr<GechatUser> user); // return false only if user is invalid or already a friend.
	bool singleDelete(shared_ptr<GechatUser> user); // return false only if user is invalid or not a friend.
	bool singleDelete(string username); // return false only if username not found in friends.
	bool doubleDelete(shared_ptr<GechatUser> user); // return false only if user is invalid or not a friend.
	bool doubleDelete(string username); // return false only if username not found in friends.
	bool operator== (const GechatUser &comp) const;
	bool operator< (const GechatUser &comp) const;
	// Not complete...
private:
	string m_username;
	vector<shared_ptr<GechatUser>> m_friendList;
};

ostream& operator<< (ostream& os, GechatUser &user);

#endif