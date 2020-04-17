#include "customset.h"

#ifndef _TICKETS_HPP_
#define _TICKETS_HPP_

#define LOTTO6 6
#define LOTTO7 7


class LotteryTicket {
public:
    LotteryTicket();
    LotteryTicket(const CustomSet<int>& numbers, int round);
    virtual ~LotteryTicket();

    int getRound();
    int getCost();
    CustomSet<int> getNumbers() const;
    virtual int getTicketType() = 0;
    void setCost(const int& cost);
    virtual int claimPrize(const CustomSet<int>& prizeNumbers, int round) = 0;
    int calCombiNum(int a, int b);
    void calPrizeWin(int type, int bought, int right, int cnt);
protected:
    vector<int> prizeList;// how many prize won for each type
    int m_bought;
    bool m_claimed;
private:
    CustomSet<int> m_numbers;//numbers bought
    int m_round;  // The valid round of a ticket. An outdated ticket is invalid.
    int m_cost;   // The amount of money spent on this ticket.
};


class Lotto7Ticket:public LotteryTicket {
public:
    Lotto7Ticket(const CustomSet<int>& numbers, int round);
    virtual ~Lotto7Ticket();
    virtual int getTicketType();
    virtual int claimPrize(const CustomSet<int>& prizeNumbers, int round);
};


class Lotto6Ticket:public LotteryTicket {
public:
    Lotto6Ticket(const CustomSet<int>& numbers, int round);
    virtual ~Lotto6Ticket();
    virtual int getTicketType();
    virtual int claimPrize(const CustomSet<int>& prizeNumbers, int round);
};

#endif