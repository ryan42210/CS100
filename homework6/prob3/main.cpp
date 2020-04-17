#include "gechatuser.h"
#include "customset.h"

int main() {
    shared_ptr<GechatUser> gzw(new GechatUser("GeziWang"));
    shared_ptr<GechatUser> gf(new GechatUser("Girlfriend"));
    shared_ptr<GechatUser> third(new GechatUser("hh"));
    gzw->addFriend(gf);
    gzw->addFriend(third);
    gf->addFriend(gzw);
    gf->singleDelete(gzw);
    gzw->doubleDelete(gf);
    CustomSet<GechatUser> sad_story;
    sad_story.add(*gzw);
    sad_story.add(*gf);
    sad_story.sortSet();
    sad_story.printSet();  // prints "{GeziWang (friends: 0), Girlfriend(friends: 0)}\n"
}